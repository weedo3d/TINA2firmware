/**
* Copyright (C) 2019 WEEDO3D Perron
*/

#include "WTCMD.h"
#include "parser.h"
#include "ultralcd.h"
#include "cardreader.h"
#include "printcounter.h"
#include "duration_t.h"
#include "buzzer.h"
#include "configuration_store.h"
#include "serial.h"
#include "WTGcodeinfo.h"

#define ACTION_ON_PAUSE		"pause"
#define ACTION_ON_PAUSED	"paused"
#define ACTION_ON_RESUME	"resume"
#define ACTION_ON_CANCEL	"cancel"
#define ACTION_ON_DISCONNECT	"disconnect"
#define ACTION_ON_START       "start"
#define ACTION_ON_FINISH      "finish"

#define EEPROM_HOST_MODE				1000

#define STATUS_CHECK_TIME_INTERVAL		1000
#define STATUS_TOGGLE_TIME_INTERVAL		5000

extern void wtlcd_welcome1();
extern void wtlcd_welcome2();
extern void wtlcd_welcome3();
extern void wtlcd_welcome4();
extern void wtlcd_debugMenu();
extern void wtlcd_WifiOTAMenu();
extern void menu_action_submenu(screenFunc_t func);
extern void wtlcd_ShowUploadingScreen();
extern void wtlcd_ShowUploadFailScreen();
extern void wt_restart();
extern void lcd_sdcard_stop();
extern void lcd_return_to_status();
extern void lcd_main_menu();
extern CardReader card;
extern InPacket inp3;

WT_STATUS wt_machineStatus = WT_STATUS::IDLE;

uint8_t wt_onlineprinting = SPARK_IDLE;		// 0 = not printing, 1 = paused, 2 = printing

extern Buzzer buzzer;

char ipAddress[16];
char esp32_name[12];
char esp32_hardware[8];
char esp32_version[8];
char esp32_message[22];
char esp32_serial[16];
bool getIPAddress = false;
bool isOTAUpdating = false;
char uploadFilename[FILENAME_LENGTH + 2];
char wifi_ssid[30];
char wifi_pwd[30];
char parsedString[30];
uint8_t wt_hostmode = HOST_WIIBUILDER;
uint8_t wt_hostmode_init = 0;
char tb_state[20];
uint32_t wt_status_check = STATUS_CHECK_TIME_INTERVAL;
uint32_t wt_status_togle = STATUS_TOGGLE_TIME_INTERVAL;

void WT_Set_SmartConfig()
{
	getIPAddress = false;
	SERIAL_PROTOCOLLNPGM("WTCMD:CONFIG");
}

void WT_Get_IP()
{
	inp3.SendCommand('I');
}

void WT_ESP32_Restart()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:RESTART");
}

void WT_Get_ESP32Version()
{
	inp3.SendCommand('H');
	inp3.SendCommand('F');
	inp3.SendCommand('J');
	inp3.SendCommand('K');
}

void WT_OTA_Default()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:OTADEFAULT");
}

void WT_WIFI_Default()
{
	SERIAL_PROTOCOLLNPGM("WTCMD:WIFIDEFAULT");
}

void WT_WIFI_Join()
{
	SERIAL_EOL();
	SERIAL_PROTOCOLPGM("WTCMD:JOIN ");
	SERIAL_PROTOCOLPAIR("SSID:", wifi_ssid);
	SERIAL_PROTOCOLLNPAIR(" PWD:", wifi_pwd);
}

void WT_TB_STATE()
{
	SERIAL_EOL();
	SERIAL_PROTOCOLPGM("WTCMD:TBSTATE ");
}

void Show_WelcomeScreen1()
{
	defer_return_to_status = true;
	lcd_goto_screen(wtlcd_welcome1);
}

void Show_WelcomeScreen2()
{
	defer_return_to_status = true;
	lcd_goto_screen(wtlcd_welcome2);
}

void Show_WelcomeScreen3()
{
	defer_return_to_status = true;
	lcd_goto_screen(wtlcd_welcome3);
}

void Show_WelcomeScreen4()
{
	defer_return_to_status = true;
	lcd_goto_screen(wtlcd_welcome4);
}

void ShowDebugMenu()
{
	wtvar_goDebugMenu = 1;
	(void)settings.save();
	lcd_goto_screen(lcd_main_menu);
}

void DisableDebugMenu()
{
	wtvar_goDebugMenu = 0;
	(void)settings.save();
	lcd_return_to_status();
}

static void CheckFileExist(const char * name)
{
	uint32_t ret;
	
	ret = card.checkFileExist(name);

	SERIAL_PROTOCOLLNPAIR(MSG_CHECKFILESIZE, ret);
	SERIAL_PROTOCOLLNPGM("\r");
}

void GetMachineStatus()
{
	SERIAL_ECHOPGM("MStatus:");
	SERIAL_ECHO(wt_machineStatus);

	SERIAL_ECHOPGM(" MFile:");
	card.printFilename();

	char buffer[21];
	duration_t elapsed = print_job_timer.duration();
	elapsed.toString(buffer);

	SERIAL_ECHOPGM(" MTime:");
	SERIAL_ECHO(buffer);

	SERIAL_ECHOPGM(" MPercent:");
	card.getStatus();

	SERIAL_EOL();
}

static void ParseIPAddress()
{
	char* tempS;
	tempS = parser.string_arg;

	if (strstr(tempS, "Disconnected") != NULL)
	{
		strcpy_P(ipAddress, PSTR("Disconnected"));
	}
	else
	{
		strcpy(ipAddress, tempS);
	}

	lcd_setstatus(ipAddress);
}

static void ParseTBState()
{
	ZERO(tb_state);
	strcpy(tb_state, parser.string_arg);
}

void wt_CloseUploadScreen()
{
	buzzer.tone(30, 1000);
	lcd_return_to_status();
}

void wt_spark_begin()
{
	wt_onlineprinting = SPARK_PRINTING;
	print_job_timer.start();
	lcd_setstatusPGM(MMSG_PRINTING[wtvar_language], -1);
	lcd_return_to_status();
}

void wt_spark_end()
{
	wt_onlineprinting = SPARK_IDLE;
	print_job_timer.stop();
	enqueue_and_echo_commands_P(PSTR("M18"));
	if (print_job_timer.duration() > 60)
		enqueue_and_echo_commands_P(PSTR("M31"));
	else
		lcd_reset_status();
}

void wt_spark_cancel()
{
	lcd_sdcard_stop();
	while (1);
}

void wt_spark_pause()
{
#if ENABLED(PARK_HEAD_ON_PAUSE)
	enqueue_and_echo_commands_P(PSTR("M125"));
#endif
	wt_onlineprinting = SPARK_PAUSED;
	print_job_timer.pause();
	lcd_setstatusPGM(MMSG_PRINT_PAUSED[wtvar_language], -1);
}

extern void resume_print(const float &slow_load_length = 0, const float &fast_load_length = 0, const float &purge_length = ADVANCED_PAUSE_PURGE_LENGTH, const int8_t max_beep_count = 0, const bool skipmenu = false);
void wt_spark_resume()
{
#if ENABLED(PARK_HEAD_ON_PAUSE)
	resume_print(0, 0, 0, 0, true);
#endif
	wt_onlineprinting = SPARK_PRINTING;
	print_job_timer.start();
	lcd_setstatusPGM(MMSG_PRINTING[wtvar_language], -1);
	lcd_return_to_status();
}

void wt_online_pause()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_PAUSE);
}

void wt_online_resume()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_RESUME);
}

void wt_online_cancel()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_CANCEL);
}

extern uint8_t lcd_status_update_delay;
// W Command Process
void WTCMD_Process()
{
	switch (parser.codenum)
	{
	case 1:		
		wt_spark_begin();
		break;

	case 2:		
		wt_spark_end();
		break;

	case 3:		
		wt_spark_cancel();
		break;

	case 4:		
		wt_spark_pause();
		break;

	case 5:		
		wt_spark_resume();
		break;

	case 6:		
		lcd_setstatusPGM(MMSG_OCTOPRINT_OPEN, -1);
		break;

	case 7:		
		lcd_setstatusPGM(MMSG_OCTOPRINT_CLOSE, -1);
		break;

	case 100:	
		Show_WelcomeScreen1();
		break;

	case 101:	
		Show_WelcomeScreen2();
		break;

	case 102:	
		Show_WelcomeScreen3();
		break;

	case 103:	
		Show_WelcomeScreen4();
		break;

	case 104:	
		ShowDebugMenu();
		break;

	case 105:  
		DisableDebugMenu();
		break;

	case 106:		
		ZERO(uploadFilename);
		if (strlen(parser.string_arg) <= FILENAME_LENGTH)
			strcpy(uploadFilename, parser.string_arg);
		else
			strncpy(uploadFilename, parser.string_arg, FILENAME_LENGTH);
		wtlcd_ShowUploadingScreen();
		break;

	case 107:		
		wt_CloseUploadScreen();
		break;

	case 200:	
		CheckFileExist(parser.string_arg);
		break;

	case 201:	
		GetMachineStatus();
		break;

	case 202:	
		card.appendFile(parser.string_arg);
		break;

	case 203:	
		wt_restart();
		while (1);
		break;

	case 204:	
		ParseIPAddress();
		getIPAddress = true;
		break;

	case 205:	
		memset(esp32_serial, 0, 16);
		if (strlen(parser.string_arg) <= 16)
			strcpy(esp32_serial, parser.string_arg);
		else
			strncpy(esp32_serial, parser.string_arg, 16);
		break;

	case 206:	
		memset(esp32_version, 0, 8);
		if (strlen(parser.string_arg) <= 8)
			strcpy(esp32_version, parser.string_arg);
		else
			strncpy(esp32_version, parser.string_arg, 8);
		break;

	case 207:	
		memset(esp32_name, 0, 12);
		if (strlen(parser.string_arg) <= 12)
			strcpy(esp32_name, parser.string_arg);
		else
			strncpy(esp32_name, parser.string_arg, 12);
		break;

	case 208:	
		memset(esp32_message, 0, 22);
		if (strlen(parser.string_arg) <= 22)
			strcpy(esp32_message, parser.string_arg);
		else
			strncpy(esp32_message, parser.string_arg, 22);
		break;

	case 209:		
		lcd_sdcard_stop();
		break;

	case 210:		
		WT_WIFI_Default();
		break;

	case 211:		
		enqueue_and_echo_commands_P(PSTR("M104 T0 S210"));
		enqueue_and_echo_commands_P(PSTR("M701 T0"));
		enqueue_and_echo_commands_P(PSTR("M104 S0"));
		break;

	case 212:		
		enqueue_and_echo_commands_P(PSTR("M104 T0 S210"));
		enqueue_and_echo_commands_P(PSTR("M702 T0"));
		enqueue_and_echo_commands_P(PSTR("M104 S0"));
		break;

	case 213:	
		ParseTBState();
		break;

	case 300:		
		memset(wifi_ssid, 0, 30);
		strcpy(wifi_ssid, parser.string_arg);
		break;

	case 301:		//
		memset(wifi_pwd, 0, 30);
		strcpy(wifi_pwd, parser.string_arg);
		break;

	case 302:			
		WT_WIFI_Join();
		break;

	default:
		 parser.unknown_command_error();

	}
}

uint8_t extractFront(const char* source, char* ident, char* valString)
{
	int len1 = strlen(source);
	int len2 = strlen(ident);

	if (len1 < len2) return 0;

	int start;
	int i = 0;
	const char* sp;
	sp = source;
	do
	{
		start = strstr(sp, ident) - source;
		sp++;
		i++;
	} while ((start > 0) && (start < len1) && (i < len1) && (source[start - 1] != 0x20));

	if (start >= 0 && start < len1)
	{
		sp = source;
		sp += len2 + start;
		i = len2 + start;

		while (i < len1 && *sp != 0x20)
		{
			sp++;
			i++;
		}
		if (i > len2)		
		{
			sp = source;
			sp += len2 + start;
			memcpy(valString, sp, i - len2 - start);
			valString[i - len2 - start] = 0;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

void wt_restart()
{
	clear_command_queue();
	safe_delay(500);
	asm volatile ("jmp 0");
};

uint8_t wt_get_hostmode(void)
{
	if (wt_hostmode_init == 0)
	{	
		wt_hostmode_init = 1;
		wt_hostmode = eeprom_read_byte(EEPROM_HOST_MODE);
		if (wt_hostmode > 1) wt_hostmode = HOST_WIIBUILDER;
	}

	return wt_hostmode;
}

void wt_set_hostmode(const uint8_t mode)
{
	if (mode != wt_hostmode)
	{
		wt_hostmode = mode;
		eeprom_write_byte(EEPROM_HOST_MODE, wt_hostmode);
		wt_restart();
	}
}

void host_action_start()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_START);
}

void host_action_finish()
{
	SERIAL_ECHOLNPGM("//action:" ACTION_ON_FINISH);
}

void calc_local_printing_time(void)
{
	float p = (float)progress_bar_percent * 0.01;
	uint32_t elapsed = print_job_timer.duration();

	long est_total;
	if (gcodeinfo.info.i_totaltime > 0)
	{
		if (p > 0)
			est_total = (long)((float)elapsed / p);
		else
			est_total = gcodeinfo.info.i_totaltime;

		long est_last = est_total - elapsed;
		long slicing_last = gcodeinfo.info.i_totaltime - elapsed;
		if (slicing_last < 0) slicing_last = 0;

		gcodeinfo.info.i_lefttime = (long)((float)est_last * p + (float)slicing_last * (1 - p));
	}
	else
	{
		if (p > 0)
			est_total = (long)((float)elapsed / p);
		else
			est_total = 0;

		gcodeinfo.info.i_lefttime = est_total - elapsed;
		if (gcodeinfo.info.i_lefttime < 0) gcodeinfo.info.i_lefttime = 0;
	}
}

void wt_loopaction(void)
{
	uint32_t nowtime = getcurrenttime();
	if (nowtime > wt_status_check)
	{	
		wt_status_check = nowtime + STATUS_CHECK_TIME_INTERVAL;

		if (wt_machineStatus == WT_STATUS::PRINTING)
		{	
			if (nowtime > wt_status_togle)
			{
				wt_status_togle = nowtime + STATUS_TOGGLE_TIME_INTERVAL;

				if (wtvar_status_time == 1)
				{
					calc_local_printing_time();
					wtvar_status_time = 2;
				}
				else
				{
					wtvar_status_time = 1;
				}
			}
		}
		else if (wt_machineStatus == WT_STATUS::PAUSE)
		{
			wtvar_status_time = 1;
		}
		else
		{	
			wtvar_status_time = 0;
		}
	}

}