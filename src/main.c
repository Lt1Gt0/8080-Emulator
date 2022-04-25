#include "8080/8080.h"
#include "8080/Disassembler/disassembler.h"
#include <stdint.h>

int main(int argc, char** argv)
{
    int running = 1;
    State8080* state = Init8080();
    
    /* Load ROM into memory */
    ReadFile(state, "Invaders/invaders.h", 0x0); 
    ReadFile(state, "Invaders/invaders.g", 0x800); 
    ReadFile(state, "Invaders/invaders.f", 0x1000); 
    ReadFile(state, "Invaders/invaders.e", 0x1800); 

    while (running) {
        running = Emulate8080p(state);
    }

    // size_t filesize;
    // unsigned char* buffer = ReadFileToHexBuffer(fp, &filesize);
    // PrintHexBuffer(buffer, filesize);
    
    // State8080* state = Init8080();
    // state->memory = buffer;

    // size_t progCount = 0;
    // while (progCount < filesize) {
        // Emulate8080p(state);
    // }

    return 0;
}