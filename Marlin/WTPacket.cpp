/**
* Copyright (C) 2019 WEEDO3D Perron
*/

#include "CRC8.h"
#include "WTPacket.h"
#include "WTCMD.h"
#include "serial.h"
#include "SdFatConfig.h"
#include "cardreader.h"
#include "temperature.h"
#include "duration_t.h"
#include "printcounter.h"


 extern WT_STATUS wt_machineStatus;
 extern InPacket inp0;
 extern InPacket inp3;
 extern OutPacket outp0;
 extern OutPacket outp3;
 extern char uploadFilename[FILENAME_LENGTH + 2];
 extern void wtlcd_ShowUploadingScreen();
 extern void wtlcd_ShowUploadFailScreen();
 extern void wt_CloseUploadScreen();
 extern void lcd_setstatus(const char* message, const bool persist = false);
 extern void lcd_sdcard_stop();

 char packetCommand[MAX_CMD_SIZE];
 extern char wifi_ssid[30];
 extern char wifi_pwd[30];
 
 void Packet::appendByte(uint8_t data)
{
	if (length < MAX_PACKET_PAYLOAD) 
	{
		payload[length] = data;
		length++;
	}
	else 
		error(RC_BUFFER_OVERFLOW);
}

void Packet::error(ResponseCode error_code_in)
{
	Reset();
	rcode = error_code_in;
}


char Packet::Get_Error(void)
{
	return rcode;
}

void Packet::Reset()
{
	crc = 0;
	length = 0;

	memset((char *)payload, 0 , MAX_PACKET_PAYLOAD);
	rcode = RC_OK;
	state = PS_START;
}

void InPacket::Receiver(uint8_t b)
{
	if (state == PS_START) 
	{
		if (b == START_BYTE) 	
		{
			state = PS_LEN;			
		} 
	} 
	else if (state == PS_LEN) 
	{
		if (b <= MAX_PACKET_PAYLOAD) 	
		{
			expected_length = b;
			if (expected_length == 0)
				error(RC_PACKET_ERROR);
			else
				state = PS_PAYLOAD;
		} 
		else 
		{
			error(RC_BUFFER_OVERFLOW);
		}
	} 
	else if (state == PS_PAYLOAD)
	{
		appendByte(b);
		if (length >= expected_length) 
		{
			state = PS_CRC;
		}
	} 
	else if (state == PS_CRC) 
	{
		crc = CRC8(payload, 0, length);
		if (crc == b) 
			state = PS_END;
		else 
			error(RC_CRC_MISMATCH);		
	}
	else if (state == PS_END)
	{
		if (b == END_BYTE)
		{
			if (port == 0)
				wtvar_uart0_binmode = true;	
			PayloadProcess();
			Reset();
		}
		else
		{
			error(RC_PACKET_NOEND);
		}
	}
}

void InPacket::Process_State(void)
{
	outp->Reset();
	outp->appendByte('0');
	switch (wt_machineStatus)
	{
	case IDLE:
		outp->appendByte(0x30);
		break;
	case PRINTING:
		outp->appendByte(0x31);
		break;
	case PAUSE:
		outp->appendByte(0x32);
		break;
	case ABORT:
		outp->appendByte(0x33);
		break;
	case FINISH:
		outp->appendByte(0x34);
		break;
	}
	outp->Send();
}

void InPacket::Process_BeginWrite(void)
{
	ZERO(uploadFilename);
	strncpy(uploadFilename, (const char*)&payload[1], length - 1);
	wtlcd_ShowUploadingScreen();		

	outp->Reset();
	outp->appendByte('W');
	if (card.openFile(uploadFilename, false))
	{
		outp->appendByte(0x30);			
		outp->Send();
	}
	else
	{
		outp->appendByte(0x31);			
		outp->Send();
		wtlcd_ShowUploadFailScreen();
	}
}

void InPacket::Process_WritePage(void)
{
	outp->Reset();
	outp->appendByte('D');
	if (rcode == RC_OK)
	{
		if (card.write((const char*)&payload[1], length - 1))
		{
			outp->appendByte(0x30);			
			outp->Send();
		}
		else
		{
			outp->appendByte(0x31);			
			outp->Send();
			card.closefile();			
			wtlcd_ShowUploadFailScreen();
		}
	}
	else
	{
		outp->appendByte(0x32);			
		outp->Send();
		wtlcd_ShowUploadFailScreen();
	}
}

void InPacket::Process_EndWrite(void)
{
	outp->Reset();
	outp->appendByte('E');
	if (rcode == RC_OK)
	{
		if (card.write((const char*)&payload[1], length - 1))
		{
			outp->appendByte(0x30);			
			outp->Send();
			wt_CloseUploadScreen();
		}
		else
		{
			outp->appendByte(0x31);			
			outp->Send();
			wtlcd_ShowUploadFailScreen();
		}

		card.closefile();			

	}
	else
	{
		outp->appendByte(0x32);			
		outp->Send();
		wtlcd_ShowUploadFailScreen();
	}
}

extern char ipAddress[16];
extern char esp32_hardware[8];
extern char esp32_version[8];
extern char esp32_name[12];

void InPacket::Process_Version(void)
{
	outp->Reset();

	uint8_t* p2 = outp->payload;

	sprintf_P((char*)p2, PSTR("VN:%s H:%s F:%s A:%s W:%s G:%s"), MACHINE_NAME, HARDWARE_VERSION, SHORT_BUILD_VERSION, ipAddress, esp32_hardware, esp32_version);

	outp->Send();

}

void InPacket::Process_Temperature(void)
{
	outp->Reset();

	int t0 = 0;
	int t1 = 0;
	int b0 = 0;
	int c0 = 0;
	uint8_t* p2 = outp->payload;

	t0 = thermalManager.degHotend(0);

#if HOTENDS > 1
	t1 = thermalManager.degHotend(1);
#endif

#if HAS_HEATED_BED
	b0 = thermalManager.degBed();
#endif

#if HAS_TEMP_CHAMBER
	c0 = thermalManager.degChamber();
#endif

	sprintf_P((char*)p2, PSTR("TT0:%d T1:%d B:%d C:%d"), t0, t1, b0, c0);

	outp->Send();

}

void InPacket::Process_Print(void)
{
	outp->Reset();

	uint8_t* p2 = outp->payload;
	char printfile[20];
	memset(printfile, 0, 20);
	card.getPrintingFilename(printfile);

	int percent = card.getPrintPercent();

	char buffer[21];
	memset(buffer, 0, 21);
	duration_t elapsed = print_job_timer.duration();
	elapsed.toString(buffer);

	sprintf_P((char*)p2, PSTR("SF:%s P:%d B:%s"), printfile, percent, buffer);

	outp->Send();
}

void InPacket::Process_Filelist(void)
{
	outp->Reset();
	outp->appendByte('B');
	if (card.cardOK)
	{
		outp->appendByte(0x30);
		outp->Send();
		card.lsRoot(outp);
	}
	else
	{
		outp->appendByte(0x32);
		outp->Send();
	}
}

void InPacket::Process_Filedelete(void)
{
	outp->Reset();
	outp->appendByte('R');
	if (rcode == RC_OK)
	{
		bool ret = false;
		if (card.cardOK) 
		{
			card.closefile();
			if (card.removeFile((const char*)&payload[1]) == 0)
				ret = true;
		}

		if (ret)
		{
			outp->appendByte(0x30);		
			outp->Send();
		}
		else
		{
			outp->appendByte(0x31);			
			outp->Send();
		}
	}
	else
	{
		outp->appendByte(0x32);			
		outp->Send();
		wtlcd_ShowUploadFailScreen();
	}
}

extern uint8_t commands_in_queue;
extern bool _enqueuecommand(const char* cmd, bool say_ok = false);
void InPacket::Process_GCode(void)
{
	outp->Reset();
	outp->appendByte('G');
	if (commands_in_queue < BUFSIZE)
	{
		_enqueuecommand(&payload[1], false);
		outp->appendByte(0x30);
	}
	else
	{
		outp->appendByte(0x31);
	}
	outp->Send();
}

void InPacket::Process_Unknown(void)
{
	outp->Reset();
	outp->appendByte('9');
	outp->appendByte('9');
	outp->Send();
}

void InPacket::Proess_WifiSetting(void)
{
	outp->Reset();
	outp->appendByte('N');
	outp->appendByte(0x30);
	outp->Send();

	memset(wifi_ssid, 0,30);
	memset(wifi_pwd, 0, 30);

	int spacepos = strchr((const char*)&payload[1], ' ') - (const char*)&payload[1];
	int plen = strlen((char*)payload) - 1;
	if (spacepos > 0 && spacepos < plen)
	{
		strncpy(wifi_ssid, (const char*)&payload[1], spacepos);
		strncpy(wifi_pwd, (const char*)&payload[spacepos + 2], plen - spacepos - 1);
		WT_WIFI_Join();
	}

}

extern void wt_restart();
void InPacket::Process_Reboot(void)
{
	outp->Reset();
	outp->appendByte('X');
	outp->appendByte(0x30);
	outp->Send();

	wt_restart();
	while (1);
}

void InPacket::Process_GetIP(void)
{
	char* tempS;
	tempS = (char*)&payload[1];

	if (strstr(tempS, "Disconnected") != NULL)
	{
		strcpy_P(ipAddress, PSTR("Disconnected"));
	}
	else
	{
		strcpy(ipAddress, tempS);
	}

	lcd_setstatus(ipAddress);

	outp->Reset();
	outp->appendByte('I');
	outp->appendByte(0x30);
	outp->Send();
}

void InPacket::Process_GetESP32HV(void)
{
	char* tempS;
	tempS = (char*)&payload[1];

	if (strlen(tempS) <= 8)
		strcpy(esp32_hardware, tempS);
	else
		strncpy(esp32_hardware, tempS, 8);

	outp->Reset();
	outp->appendByte('H');
	outp->appendByte(0x30);
	outp->Send();
}

void InPacket::Process_GetESP32FV(void)
{
	char* tempS;
	tempS = (char*)&payload[1];

	if (strlen(tempS) <= 8)
		strcpy(esp32_version, tempS);
	else
		strncpy(esp32_version, tempS, 8);

	outp->Reset();
	outp->appendByte('F');
	outp->appendByte(0x30);
	outp->Send();
}

void InPacket::Process_GetESP32NAME(void)
{
	char* tempS;
	tempS = (char*)&payload[1];

	if (strlen(tempS) <= 12)
		strcpy(esp32_name, tempS);
	else
		strncpy(esp32_name, tempS, 8);

	outp->Reset();
	outp->appendByte('J');
	outp->appendByte(0x30);
	outp->Send();
}

extern char esp32_serial[16];
void InPacket::Process_GetESP32Serial(void)
{
	char* tempS;
	tempS = (char*)&payload[1];

	memset(esp32_serial, 0, 16);
	if (strlen(tempS) <= 15)
		strcpy(esp32_serial, tempS);
	else
		strncpy(esp32_serial, tempS, 15);

	outp->Reset();
	outp->appendByte('K');
	outp->appendByte(0x30);
	outp->Send();
}


void InPacket::Process_AbortPrinting(void)
{
	outp->Reset();
	outp->appendByte('A');
	outp->appendByte(0x30);
	outp->Send();

	safe_delay(500);

	lcd_sdcard_stop();
	while (1);
}

void InPacket::PayloadProcess(void)
{
	if (length > 0)
	{
		switch(payload[0])
		{
			case '0':		
				Process_State();
				break;

			case 'W':		
				Process_BeginWrite();
				break;

			case 'D':		
				Process_WritePage();
				break;

			case 'E':		
				Process_EndWrite();
				break;

			case 'T':	
				Process_Temperature();
				break;

			case 'S':		
				Process_Print();
				break;

			case 'V':		
				Process_Version();
				break;

			case 'B':		
				Process_Filelist();
				break;

			case 'R':	
				Process_Filedelete();
				break;

			case 'G':		
				Process_GCode();
				break;

			case 'N':		
				Proess_WifiSetting();
				break;

			case 'X':	
				Process_Reboot();
				break;

			case 'I':	
				Process_GetIP();
				break;

			case 'H':	
				Process_GetESP32HV();
				break;

			case 'F':		
				Process_GetESP32FV();
				break;

			case 'J':		
				Process_GetESP32NAME();
				break;

			case 'K':		
				Process_GetESP32Serial();
				break;

			case 'A':	
				Process_AbortPrinting();
				break;

			default:
				Process_Unknown();
				break;
		}
	}
	else
	{
		error(RC_PACKET_ERROR);
	}
}

void InPacket::SendCommand(char cmd)
{
	outp->Reset();
	outp->appendByte(cmd);
	outp->appendByte(0x31);
	outp->Send();
}

void OutPacket::Send(void)
{
	for (i = 0; i < MAX_PACKET_PAYLOAD; i++)
	{
		if (payload[i] == 0)
		 break;
	}
	length = i;
	buffer[0] = START_BYTE;
	buffer[1] = length;
	for (i = 0; i < length; i++)
		buffer[i + 2] = payload[i];
	crc = CRC8(payload, 0, length);
	buffer[length + 2] = crc;
	buffer[length + 3] = END_BYTE;
	customizedSerial.write(buffer, length + 4);
}

