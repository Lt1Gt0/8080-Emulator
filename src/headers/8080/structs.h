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

typedef enum {
    NZ  = 0x00, // Not Zero (Z = 0) 
    Z   = 0x01, // Zero (Z = 1)
    NC  = 0x02, // No Carry (CY = 0)
    C   = 0x03, // Carry (CY = 1)
    PO  = 0x04, // Parity Odd (P = 0)
    PE  = 0x05, // Parity Even (P = 1)
    P   = 0x06, // Plus (S = 0)
    M   = 0x07  // Minus (S = 1)
}ConditionFlags;

// from the 8080 Manual, Flag bits will be check
// by shifting bits like such, the bits are in order
// inside of the state struct for PSW
typedef enum {
    SIGN_FLAG   = 1 << 0,
    ZERO_FLAG   = 1 << 1,
    AUX_FLAG    = 1 << 3,
    PARITY_FLAG = 1 << 5,
    CARRY_FLAG  = 1 << 7
}flagBits;
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
            uint8_t s   : 1; // Sign
            uint8_t z   : 1; // Zero 
            uint8_t pad : 1; // Padding
            uint8_t ac  : 1; // Auxiliary Carry
            uint8_t pad : 1; // Padding
            uint8_t p   : 1; // Parity 
            uint8_t pad : 1; // Padding
            uint8_t cy  : 1; // Carry
        };
        uint8_t PSW; // Program Status Word
    };

    uint8_t* memory; // Memory location
    uint8_t int_enable; // interrupts enabled
    uint8_t int_pend; // Pending Interrupts 

}State8080;

#endif // __STRUCTS_H