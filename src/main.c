#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"
// #include "8080/Disassembler/disassembler.h"
// #include "Debug/debug.h"


int main(int argc, char** argv)
{
    int running = 0;
    State8080* state = Init8080();
    
    /* Load ROM into memory */
    ReadFile(state, "Invaders/invaders.h", 0 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.g", 0x800 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.f", 0x1000 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.e", 0x1800 + ROM_OFFSET); 

    for (int i = 0; i < 0x2000; i++) {
        // Emulate8080p(state);
        ExecuteInstruction(state);
    }

    // while (running == 0) {
        // running = Emulate8080p(state);
    // }
    
    return 0;
}