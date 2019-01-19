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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <SDL/SDL.h>

#include "burner.h"
#include "sdl_progress.h"
#include "sdl_run.h"
#include "font.h"

SDL_Surface *load_screen = NULL;
int fwidth = 320, fheight = 240; // text surface

void blit_loading_screen()
{
	extern SDL_Surface *screen;
	// extern SDL_Surface *RS97screen;
	SDL_Rect dst;

	dst.x = (screen->w - 320) / 2;
	dst.y = (screen->h - 240) / 2;
	SDL_BlitSurface(load_screen, NULL, screen, &dst);

	SDL_Flip(screen);

	SDL_FillRect(load_screen,NULL,SDL_MapRGB(load_screen->format,0x0,0x0,0x0));
	DrawString2(load_screen, "FinalBurn Alpha " VERSION, COLOR_TEXT, COLOR_BG, 50, 4);
	DrawString2(load_screen, "(c) Team FB Alpha", COLOR_TEXT, COLOR_BG, 80, 226);
}

void show_rom_loading_text(char *szText, int nSize, int nTotalSize)
{
	int doffset = 20;
	static long long size = 0;

	DrawRect((uint16 *)load_screen->pixels, doffset, 120, 300, 20, 0, fwidth);

	if (szText)
		DrawString2(load_screen, (const char*)szText, COLOR_TEXT, COLOR_BG, doffset, 80);

	DrawRect((uint16 *)load_screen->pixels, doffset, 100, 280, 12, 0x00FFFFFF, fwidth);
	DrawRect((uint16 *)load_screen->pixels, doffset+1, 101, 278, 10, 0x00808080, fwidth);

	if (nTotalSize == 0) {
		size = 0;
	} else {
		size += nSize;
		if (size > nTotalSize) size = nTotalSize;
		DrawRect((uint16 *)load_screen->pixels, doffset+1, 101, size * 278 / nTotalSize, 10, 0x00FFFF00, fwidth);
	}

	SDL_Event event;
	while(SDL_PollEvent(&event));
	blit_loading_screen();
}

void show_rom_error_text(char *szText)
{
	int doffset = 20;

	DrawRect((uint16 *)load_screen->pixels, doffset, 120, 300, 20, 0, fwidth);

	DrawString2(load_screen, "Error loading rom:", COLOR_ERROR, COLOR_BG, doffset, 60);
	if (szText)
		DrawString2(load_screen, (const char*)szText, COLOR_ERROR, COLOR_BG, doffset, 80);

	DrawString2(load_screen, "Press any key to exit", COLOR_TEXT, COLOR_BG, 60, 210);

	blit_loading_screen();

	SDL_Event event;
	while(event.type != SDL_KEYDOWN) SDL_WaitEvent(&event);
	GameLooping = false;
}

int ProgressCreate()
{
	// if(!load_screen) ProgressDestroy();
	load_screen = SDL_CreateRGBSurface(SDL_SWSURFACE, fwidth, fheight, 16, 0, 0, 0, 0);

	show_rom_loading_text("Open Zip", 0, 0);
}

int ProgressDestroy()
{
	if(load_screen) {
		SDL_FreeSurface(load_screen);
		load_screen = NULL;
	}
}

int ProgressUpdateBurner(double dProgress, const TCHAR* pszText, bool bAbs)
{
	return 0;
}


int ProgressError(TCHAR* szText, int bWarning)
{
	show_rom_error_text(szText);
	return 0;
}
