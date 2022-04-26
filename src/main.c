#include "8080/8080.h"
#include "8080/Disassembler/disassembler.h"
#include "Computer/machine.h"
#include "Emulator/SpaceInvaders/spaceinvaders.h"
#include <stdint.h>

int main(int argc, char** argv)
{
    // InitializeSpaceInvaders();

    int running = 0;
    State8080* state = Init8080();
    uint8_t* opcode;

    /* Load ROM into memory */
    ReadFile(state, "Invaders/invaders.h", 0); 
    ReadFile(state, "Invaders/invaders.g", 0x800); 
    ReadFile(state, "Invaders/invaders.f", 0x1000); 
    ReadFile(state, "Invaders/invaders.e", 0x1800); 

    while (running == 0) {
        /*
        DB -> IN D8
        D3 -> OUT D8
        */

        // opcode = &state->memory[state->pc];   
        // if (*opcode == 0xDB) {
            // Read the nex byte of the opcode as port
            // port = opcode[1];
            // state->a = inb(state, port);
            // state->pc += 1;
            // 
        // } else if (*opcode == 0xD8) {
            // port = opcode[1];
            // outb(state, port);
            // state->pc += 1;
        // } else {
            // running = Emulate8080p(state);
        // }
        running = Emulate8080p(state);
    }

    return 0;
}