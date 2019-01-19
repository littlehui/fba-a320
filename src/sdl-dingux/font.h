/*
 * Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
 *
 * (c) Copyright 1996 - 2001 Gary Henderson (gary.henderson@ntlworld.com) and
 *                           Jerremy Koot (jkoot@snes9x.com)
 *
 * Super FX C emulator code 
 * (c) Copyright 1997 - 1999 Ivar (ivar@snes9x.com) and
 *                           Gary Henderson.
 * Super FX assembler emulator code (c) Copyright 1998 zsKnight and _Demo_.
 *
 * DSP1 emulator code (c) Copyright 1998 Ivar, _Demo_ and Gary Henderson.
 * C4 asm and some C emulation code (c) Copyright 2000 zsKnight and _Demo_.
 * C4 C code (c) Copyright 2001 Gary Henderson (gary.henderson@ntlworld.com).
 *
 * DOS port code contains the works of other authors. See headers in
 * individual files.
 *
 * Snes9x homepage: http://www.snes9x.com
 *
 * Permission to use, copy, modify and distribute Snes9x in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Snes9x is freeware for PERSONAL USE only. Commercial users should
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for Snes9x or software derived from Snes9x.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so everyone can benefit from the modifications
 * in future versions.
 *
 * Super NES and Super Nintendo Entertainment System are trademarks of
 * Nintendo Co., Limited and its subsidiary companies.
 */

#ifndef _EMU_FONT_H_
#define _EMU_FONT_H_

#include <SDL/SDL.h>

#define color16(red, green, blue) ((red << 11) | (green << 5) | blue)

#define COLOR_BG            color16(0, 0, 0)
#define COLOR_ROM_INFO      color16(22, 36, 26)
#define COLOR_ACTIVE_ITEM   color16(0xFF,0xFF,0x00)
#define COLOR_INACTIVE_ITEM color16(0x80,0x80,0xFF)
#define COLOR_FRAMESKIP_BAR color16(15, 31, 31)
#define COLOR_HELP_TEXT     color16(0x80,0x80,0xFF)
#define COLOR_TEXT          color16(0xFF,0xFF,0xFF)

typedef unsigned short 	uint16;
typedef unsigned char 	uint8;

void DisplayChar (uint16 *Screen, uint8 c, uint16 resW);
void DrawString (const char *string, uint16 *screen, uint8 x, uint8 y, uint16 resW);
void DrawRect ( uint16 *screen, int x, int y, int w, int h, int c, uint16 resW );

void DrawChar(SDL_Surface *s, int x, int y, unsigned char a, int fg_color, int bg_color);
void DrawString2(SDL_Surface *sfc, const char *s, unsigned short fg_color, unsigned short bg_color, int x, int y);

#endif	// _EMU_FONT_H_
