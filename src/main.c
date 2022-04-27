#include "8080/8080.h"
#include "8080/Disassembler/disassembler.h"
#include "Emulator/SpaceInvaders/spaceinvaders.h"
#include <stdint.h>

int main(int argc, char** argv)
{
    int running = 0;
    State8080* state = Init8080();
    
    /* Load ROM into memory */
    ReadFile(state, "Invaders/invaders.h", 0 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.g", 0x800 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.f", 0x1000 + ROM_OFFSET); 
    ReadFile(state, "Invaders/invaders.e", 0x1800 + ROM_OFFSET); 

    while (running == 0) {
        running = Emulate8080p(state);
    }
    
    return 0;
}