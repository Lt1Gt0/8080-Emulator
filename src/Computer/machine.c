#include "Computer/machine.h"

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

uint8_t inb(State8080* state, uint8_t port)
{
    uint8_t a;
    switch (port) {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        // uint16_t 
        break;
    }
    return 0; // default for now
}

void outb(State8080* state, uint8_t port)
{

}