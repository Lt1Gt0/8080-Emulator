#pragma once
#ifndef __MACHINE_H
#define __MACHINE_H

#include <stdint.h>
#include "../8080/structs.h"

/* PORT CONFIGURATIONS

Read
    00  INPUTS (Mapped in hardware but never used by code)
    01  INPUTS
    02  INPUTS
    03  bit shift register read
Write
    02  shift amount (3 bits)
    03  sound bits
    04  shift data
    05  sound bits
    06  watch-dogs
    07  (also demultiplexed)
*/

typedef enum {
    LEFT,
    RIGHT
}Keys;

typedef struct ShiftRegisters {
    uint16_t value;
    uint8_t shift0;
    uint8_t shift1;
    uint8_t offset;
} ShiftRegisters;

typedef struct Machine {
    ShiftRegisters ShiftRegisters;
    uint8_t port;
}Machine;

uint8_t inb(State8080* state, uint8_t port);
void outb(State8080* state, uint8_t port);

void MachineKeyDown(char key);
void MachineKeyUp(char key);
#endif // __MACHINE_H