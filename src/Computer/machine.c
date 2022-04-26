#include "machine.h"

Machine machine;
uint8_t inb(State8080* state, uint8_t port)
{
    uint8_t a;
    switch (port) {
    case 3:
        // Return data shifted by some amount
        machine.ShiftRegisters.value = (machine.ShiftRegisters.shift1 << 8) | (machine.ShiftRegisters.shift0);
        state->a = ((machine.ShiftRegisters.value >> (8 - machine.ShiftRegisters.offset)) && 0xFF);
        break;
    }
    return 0; // default for now
}

void outb(State8080* state, uint8_t port)
{
    switch (port) {
    case 2:
        // set the offset for the 8 bit result
        machine.ShiftRegisters.offset = machine.ShiftRegisters.value & 0x07;
        break;
    case 4:
        // set data in shift registers
        machine.ShiftRegisters.shift0 = machine.ShiftRegisters.shift1;
        machine.ShiftRegisters.shift1 = machine.ShiftRegisters.value;
        break;
    } 
}

// void MachineKeyDown(char key)
// {
//     switch (key) {
//     case LEFT:
//         port |= 0x20; // Set 5 bits of port 1
//         break;
//     case RIGHT:
//         port |= 0x40 //
//     }
// }

// void MachineKeyUp(char key)
// {
//     switch (key) {

//     }
// }