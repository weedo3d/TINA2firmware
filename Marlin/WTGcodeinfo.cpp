/**
* Copyright (C) 2019 WEEDO3D Perron
*/

#include "Marlin.h"
#include "cardreader.h"
#include "duration_t.h"
#include "WTGcodeinfo.h"

WTGcodeinfo gcodeinfo;

void WTGcodeinfo::reset(void)
{
	memset(info.machine, 0, 20);
	strcpy_P(info.machine, PSTR(MSG_NONE));
	memset(info.material, 0, 10);
	strcpy_P(info.material, PSTR(MSG_NONE));
	memset(info.layerheight, 0, 10);
	strcpy_P(info.layerheight, PSTR(MSG_NONE));
	memset(info.density, 0, 10);
	strcpy_P(info.density, PSTR(MSG_NONE));
	memset(info.temp0, 0, 10);
	strcpy_P(info.temp0, PSTR(MSG_NONE));
	memset(info.totaltime, 0, 10);
	strcpy_P(info.totaltime, PSTR(MSG_NONE));
	memset(info.filament, 0, 10);
	strcpy_P(info.filament, PSTR(MSG_NONE));
	info.i_lefttime = 0;
}

void WTGcodeinfo::parse(char* filename)
{
	ZERO(info.filename);
	strcpy(info.filename, filename);
	reset();
	card.openFile(filename, true);

	sd_count = 0;
	bool card_eof = card.eof();
	bool sd_comment_mode = false;
	uint8_t linecount = 0;

	memset(linebuffer, 0, MAX_COMMENT_LINE_LENGTH);
	while (!card_eof && linecount < 30)
	{
		const int16_t n = card.get();
		char sd_char = (char)n;
		card_eof = card.eof();

		if (card_eof || n == -1 || sd_char == '\r')
		{
			linebuffer[sd_count] = '\0';

			if (sd_comment_mode)
			{
				if (strstr_P(linebuffer, PSTR("MachineType:")) != NULL)
				{
					getvalue(info.machine);
				}

				if (strstr_P(linebuffer, PSTR("FilamentType:")) != NULL)
				{
					getvalue(info.material);
				}

				if (strstr_P(linebuffer, PSTR("Layer height:")) != NULL)
				{
					getvalue(info.layerheight);
					strcat(info.layerheight, "mm");
				}

				if (strstr_P(linebuffer, PSTR("InfillDensity:")) != NULL)
				{
					getvalue(info.density);
					strcat(info.density, "%");
					SERIAL_ECHO(info.density);
				}

				if (strstr_P(linebuffer, PSTR("Extruder0Temperature:")) != NULL)
				{
					getvalue(info.temp0);
				}

				if (strstr_P(linebuffer, PSTR("TIME:")) != NULL)
				{
					getvalue(info.totaltime);
					info.i_totaltime = atol(info.totaltime) + 120;
					duration_t tempT = info.i_totaltime;
					tempT.toDigital(info.totaltime);
				}

				if (strstr_P(linebuffer, PSTR("FilamentUsed:")) != NULL)
				{
					getvalue(info.filament);
					info.f_filament = atof(info.filament) / (float)335.4 + 1;
					uint16_t tempi = info.f_filament;
					memset(info.filament, 0, 10);
					sprintf_P(info.filament, PSTR("%ig"), tempi);
				}
			}
			memset(linebuffer, 0, MAX_COMMENT_LINE_LENGTH);

			sd_count = 0; // clear sd line buffer
			linecount++;
			sd_comment_mode = false;
			
		}
		else if (sd_count >= MAX_COMMENT_LINE_LENGTH - 1) 
		{	
			SERIAL_ECHOLNPGM("Error: comment line too long");
			return;
		}
		else 
		{
			if (sd_char == ';')
				sd_comment_mode = true;
			else
				linebuffer[sd_count++] = sd_char;
		}
	}

	card.closefile();

}

void WTGcodeinfo::getvalue(char* data)
{
	uint8_t pos = 0;
	pos = strchr(linebuffer, ':') - linebuffer;

	if (pos > 1 && pos < sd_count)
	{
		uint8_t dp = 0;
		for (uint8_t i = 0; i < sd_count - pos; i++)
		{
			if (linebuffer[pos + i + 1] != 0x20)
				data[dp++] = linebuffer[pos + i + 1];
		}
	}
}
