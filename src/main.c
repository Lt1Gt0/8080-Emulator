#include "8080/8080.h"
#include "8080/Disassembler/disassembler.h"
#include <stdint.h>

int main(int argc, char** argv)
{
    int running = 0;
    State8080* state = Init8080();
    
    /* Load ROM into memory */
    ReadFile(state, "Invaders/invaders.h", 0); 
    ReadFile(state, "Invaders/invaders.g", 0x800); 
    ReadFile(state, "Invaders/invaders.f", 0x1000); 
    ReadFile(state, "Invaders/invaders.e", 0x1800); 

    // while (running == 0) {
        // running = Emulate8080p(state);
    // }

    
    while (state->pc < 0x2000) {
        state->pc += DecodeInstruction(state->memory, state->pc);
    }

    return 0;
}