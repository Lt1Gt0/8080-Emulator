#pragma once
#ifndef __SPACE_INVADERS_H
#define __SPACE_INVADERS_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdio.h>
#include "8080/cpu.h"

// Defines based off of information about space invader rom
#define TOTAL_ROM_FILES 4
#define MEMORY_SIZE     0x4000 // ROM + RAM + VRAM + RAM mirror
#define ROM_SIZE        0x2000 // Size of the 4 ROM Files together
#define STACK_START     0x2400
#define PROGRAM_START   0x0000

#define ROM_OFFSET      0x0000
#define VRAM_OFFSET     0x2400 // Start address of VRAM
#define VRAM_SIZE       0x1C00 // 2400 - 3FFF (256 * 28) or (VRAM_OFFSET - (WINDOW_HEIGHT * WINDOW_WIDTH) / sizeof(byte)) 
#define VRAM_DELAY      0x0009 // 112 Hz for 1000 ms
#define HALF_1          0x0002 // Pending interrupt to call rst 1
#define FULL_2          0x0004 // Pending interrupt to call rst 2

#define WINDOW_WIDTH        256 // Window width, this will be rotated
#define WINDOW_HEIGHT       224 // Window height, this will be rotated
#define WINDOW_INIT_SUCCESS 0


/* 
The version of the rom that is currently loaded
only supports the color black and green
*/
#define PIX_GREEN       0xFF00 // RGB888 GREEN value
#define PIX_BLACK       0x0000 // RGB888 BLACK Value

/* TODO
Set up key mapping for sdl events
*/

typedef struct {
    uint32_t wFlags;
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Surface* windowSurface;
    SDL_DisplayMode displayMode;
    uint32_t* pixels; 
    uint8_t quit; // Event on quit
    // SDL EVENTS
    // SDL TIMER
}InvaderWindow;

typedef struct {
    uint8_t port0; // INPUT
    uint8_t port1; // INPUT
    uint8_t port2; // INPUT
    uint8_t port3; // OUTPUT
    uint8_t port5; // OUTPUT

    uint8_t shiftConfig;

    union {
        struct {
            uint8_t x; // Least Significant Byte
            uint8_t y; // Most Significant Byte
        };
        uint16_t hiddenReg; // 15 byte abstracted reg
    };
} PortIO;

int LoadSpaceInvaders(State8080* state);
void PrepareROM(State8080* state);

int InitializeInvaderWindow();
void InvaderEventLoop();

uint8_t InvadersIn(uint8_t port);
void InvadersOut(uint8_t port, uint8_t data);



#endif // __SPACE_INVADERS_H