#pragma once
#ifndef __SPACE_INVADERS_H
#define __SPACE_INVADERS_H

#include <stdint.h>
// Defines based off of information about space invader rom
#define ALIGNED_PREFIX  (1 << 16) // Prefix to get 16-bit aligned memory
#define ROM_OFFSET      0x00
#define VRAM_OFFSET     0x2400
#define VRAM_SIZE       0x1C00
#define VRAM_DELAY      0x9 // 112 Hz for 1000 ms
#define HALF_1          0x2 // Pending interrupt to call rst 1
#define FULL_2          0x4 // Pending interrupt to call rst 2

#define WINDOW_WIDTH    (256) // Window width, this will be rotated
#define WINDOW_HEIGHT   (224) // Window height, this will be rotated
#define PIX_GREEN       0xFF00 // RGB888 GREEN value
#define PIX_BLACK       0x0 // RGB888 BLACK Value

/* TODO
Set up key mapping for sdl events
*/

typedef struct InvaderWindow {
    // SDL WINDOW
    // SDL SURFACE
    uint32_t* pixels; 
    uint8_t quit; // Event on quit
    // SDL EVENTS
    // SDL TIMER
}InvaderWindow;

typedef struct PortIO {
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
}PortIO;

#endif // __SPACE_INVADERS_H