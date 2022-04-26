#ifndef __STRUCTS_H
#define __STRUCTS_H
#include <stdint.h>

//Might move these defines to spaceinvaders.h
#define MEMORY_SIZE 0x4000
#define ROM_SIZE 0x2000
#define STACK_START 0x2400
#define PROGRAM_START 0x0000

#define MSB_UINT8   0x80
#define MSB_UINT16  0x8000 

typedef struct State8080 {
    
    // Primary 8-bit accumulator
    uint8_t a;

    // Set up 3 16-bit register (BC, DE, HL);
    // Each 16-bit reg can function as 8 bit reg pairs (B, C, D, E, H, L)
    union {
        struct {
            uint8_t c;
            uint8_t b;
        };
        uint16_t bc;
    };

    union {
        struct {
            uint8_t e;
            uint8_t d;
        };
        uint16_t de;
    };

    union {
        struct {
            uint8_t l;
            uint8_t h;
        };
        uint16_t hl;
    };

    // Stack pointer
    uint16_t sp;

    // Program Counter
    uint16_t pc;
    
    // 8-bit Flags
    union {
        struct {
            uint8_t z   : 1; // Zero
            uint8_t s   : 1; // Sign
            uint8_t p   : 1; // Parity
            uint8_t cy  : 1; // Carry
            uint8_t ac  : 1; // Auxiliary Carry
            uint8_t pad : 3; // Padding
        };
        uint8_t PSW;
    };

    uint8_t* memory; // Memory location
    uint8_t int_enable; // interrupts enabled    
}State8080;

#endif // __STRUCTS_H