/**
* Copyright (C) 2019 WEEDO3D Perron
*/

#ifndef WTCMD_H
#define WTCMD_H

#include "Marlin.h"

#define SPARK_IDLE		0
#define SPARK_PAUSED	1
#define SPARK_PRINTING	2
#define SPARK_LOST		3

#define HOST_WIIBUILDER	0
#define HOST_SPARK		1

enum WT_STATUS : char {
	IDLE = 0, 
	PRINTING = 1,
	PAUSE = 2,
	ABORT = 3,
	FINISH = 4
};

extern WT_STATUS wt_machineStatus;

extern char parsedString[30];

void WTCMD_Process();

void WT_Set_SmartConfig();

void WT_Get_IP();

void WT_ESP32_Restart();

void WT_Get_ESP32Version();

void WT_OTA_Default();

void WT_WIFI_Default();

void WT_WIFI_Join();

void WT_TB_STATE();

void wt_online_pause();

void wt_online_resume();

void wt_online_cancel();

uint8_t extractFront(const char* source, char* ident, char* valString);

uint8_t wt_get_hostmode(void);

void wt_set_hostmode(const uint8_t mode);

void wt_restart();

void GetMachineStatus();

void host_action_start();

void host_action_finish();

void wt_loopaction(void);

#endif

