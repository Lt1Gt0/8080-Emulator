#pragma once
#ifndef __CPU8080_H
#define __CPU8080_H
#include <stdint.h>
#include "memory.h"

// I dont feel like typing __attribute__((unused)) all the time
#define UNUSED __attribute__((unused))

// #define MSB_UINT8   0x80
// #define MSB_UINT16  0x8000 

typedef enum {
    NZ  = 0x00, // Not Zero (Z = 0) (000)
    Z   = 0x01, // Zero (Z = 1) (001)
    NC  = 0x02, // No Carry (CY = 0) (010)
    C   = 0x03, // Carry (CY = 1) (011)
    PO  = 0x04, // Parity Odd (P = 0) (100)
    PE  = 0x05, // Parity Even (P = 1) (101)
    P   = 0x06, // Plus (S = 0) (110)
    M   = 0x07  // Minus (S = 1) (111)
} ConditionFlags;

typedef struct {
    uint8_t s;
    uint8_t z;
    uint8_t ac;
    uint8_t p;
    uint8_t cy;
} ProcStatusWord;

// from the 8080 Manual, Flag bits will be check
// by shifting bits like such, the bits are in order
// inside of the state struct for ProcStateWord
typedef enum {
    SIGN_FLAG   = 1 << 0,
    ZERO_FLAG   = 1 << 1,
    AUX_FLAG    = 1 << 3,
    PARITY_FLAG = 1 << 5,
    CARRY_FLAG  = 1 << 7
} flagBits;

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

    uint16_t    sp; // Stack Pointer
    uint16_t    pc; // Program Counter
    uint8_t     int_enable; // interrupts enabled
    uint8_t     int_pend; // Pending Interrupts 
    uint8_t     halt;
    
    ProcStatusWord  PSW;
    VirtualMemory   memory; // Memory location
    int             ROMSize;

    uint8_t (*ProcIN)(uint8_t);
    void (*ProcOUT)(uint8_t, uint8_t);
} State8080;

#endif // __CPU8080_H