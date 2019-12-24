/*
 * FinalBurn Alpha for Dingux/OpenDingux
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
 
#ifndef _GUI_MAIN_H_
#define _GUI_MAIN_H_

#define START_X	8
#define START_Y	120

#define BLANC		0
#define ROUGE		9
#define ORANGE		18
#define JAUNE		27
#define VERT		36
#define BLEU		45

//#define OPTIONS_FOR_GCW0
#ifndef OPTIONS_FOR_GCW0
  #define OPTIONS_FOR_A320
#endif

enum OPTION_FBA {
	OPTION_FBA_RUN,
	OPTION_FBA_SOUND,
	OPTION_FBA_SAMPLERATE,
	OPTION_FBA_VSYNC,
	OPTION_FBA_SHOWFPS,
	OPTION_FBA_68K,
	OPTION_FBA_Z80,
	OPTION_FBA_ROTATE,
	OPTION_FBA_FLIP,
	OPTION_FBA_ANALOG,
	// OPTION_FBA_VSYNC,
	// OPTION_FBA_SHOWFPS,
	// OPTION_FBA_68K,
	// OPTION_FBA_Z80,
	// OPTION_FBA_ANALOG,
// OPTION_FBA_FAVORITE,
};

#define OPTION_FBA_FIRST		OPTION_FBA_RUN
#define OPTION_FBA_LAST			OPTION_FBA_ANALOG

enum OPTION_GUI {
	OPTION_GUI_DELAYSPEED,
	OPTION_GUI_REPEATSPEED,
	OPTION_GUI_LIST,
	OPTION_GUI_SHADOW,
	OPTION_GUI_SKIN,
	OPTION_GUI_PATH0,
	OPTION_GUI_PATH1,
	OPTION_GUI_PATH2,
	OPTION_GUI_PATH3,
	OPTION_GUI_PATH4,
	OPTION_GUI_PATH5,
	OPTION_GUI_PATH6,
	OPTION_GUI_RETURN,
};

#define OPTION_GUI_LAST			OPTION_GUI_RETURN

void GuiRun();

#endif // _GUI_MAIN_H_
