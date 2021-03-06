#pragma once
#ifndef __SPACE_INVADERS_H
#define __SPACE_INVADERS_H

#include "8080/8080.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

// Defines based off of information about space invader rom
#define TOTAL_ROM_FILES 4

#define ROM_OFFSET      0x0000
#define VRAM_OFFSET     0x2400 // Start address of VRAM
#define VRAM_SIZE       0x1C00 // 2400 - 3FFF (256 * 28) or (VRAM_OFFSET - (WINDOW_HEIGHT * WINDOW_WIDTH) / sizeof(byte)) 
#define VRAM_DELAY      0x0009 // 112 Hz for 1000 ms
#define HALF_1          0x0002 // Pending interrupt to call rst 1
#define FULL_2          0x0004 // Pending interrupt to call rst 2

#define WINDOW_WIDTH (256) // Window width, this will be rotated
#define WINDOW_HEIGHT (224)// Window height, this will be rotated


/* 
The version of the rom that is currently loaded
only supports the color black and green
*/
#define PIX_GREEN 0xFF00 // RGB888 GREEN value
#define PIX_BLACK 0x0000 // RGB888 BLACK Value

/* TODO
Set up key mapping for sdl events
*/

typedef struct {
    SDL_Window*     window;
    SDL_Surface*    surface;
    uint32_t*       pixels; 
    uint8_t         quit;
    SDL_Event       event;
    SDL_TimerID     vRAMTimer;
} InvaderWindow;

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

InvaderWindow* InitInvaderWindow();
void InvadersInputHandler(SDL_KeyboardEvent event);
void InvaderEventHandler(State8080* state, InvaderWindow* window);
void SetPixel(uint32_t* pix, uint32_t x, uint32_t y, uint8_t state);
void DrawVideoRAM(State8080* state, uint32_t* pixels);
uint32_t UpdateVRAM(uint32_t interval, UNUSED void* param);
void DestroyWindow(InvaderWindow* window);

uint8_t InvadersIn(uint8_t port);
void InvadersOut(uint8_t port, uint8_t data);

#endif // __SPACE_INVADERS_H