#pragma once
#ifndef __SPACE_INVADERS_H
#define __SPACE_INVADERS_H

#include <SDL2/SDL.h>
#include <errno.h>
#include <stdio.h>

typedef struct WindowInfo {
    SDL_Surface* surface;
} WindowInfo;

/* GENERAL WINDOW INFORMATION 

Working RAM:    $0x2000 - $0x23FF
Video RAN:      $0x2400 - $0x3FFF
RAM Mirror:     $0x4000 -

Ports:
	Read 1 (Looks like keyboard/user input??)
	BIT	0	coin (0 when active)
		1	P2 start button
		2	P1 start button
		3	?
		4	P1 shoot button
		5	P1 joystick left
		6	P1 joystick right
		7	?
	
	Read 2 (Joystick controls)
	BIT	0,1	dipswitch number of lives (0:3,1:4,2:5,3:6)
		2	tilt 'button'
		3	dipswitch bonus life at 1:1000,0:1500
		4	P2 shoot button
		5	P2 joystick left
		6	P2 joystick right
		7	dipswitch coin info 1:off,0:on
	
	Read 3		shift register result
	
	Write 2		shift register result offset (bits 0,1,2)
	Write 3		sound related
	Write 4		fill shift register
	Write 5		sound related
	Write 6		strange 'debug' port? eg. it writes to this port when
			it writes text to the screen (0=a,1=b,2=c, etc)
	
	(write ports 3,5,6 can be left unemulated, read port 1=$01 and 2=$00
	will make the game run, but but only in attract mode)


    Overlay dimensions (screen rotated 90 degrees anti-clockwise):
	,_______________________________.
	|WHITE            ^             |
	|                32             |
	|                 v             |
	|-------------------------------|
	|RED              ^             |
	|                32             |
	|                 v             |
	|-------------------------------|
	|WHITE                          |
	|         < 224 >               |
	|                               |
	|                 ^             |
	|                120            |
	|                 v             |
	|                               |
	|                               |
	|                               |
	|-------------------------------|
	|GREEN                          |
	| ^                  ^          |
	|56        ^        56          |
	| v       72         v          |
	|____      v      ______________|
	|  ^  |          | ^            |
	|<16> |  < 118 > |16   < 122 >  |
	|  v  |          | v            |
	|WHITE|          |         WHITE|
	`-------------------------------'
*/

int InitializeSpaceInvaders();
extern WindowInfo* winfo;

#endif // __SPACE_INVADERS_H