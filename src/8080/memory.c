#include "8080/memory.h"

/* MEMORY MANIPULATION/READING */
void* MemRef(VirtualMemory* mem, uint16_t offset)
{
    // TODO
}

uint8_t MemRead(VirtualMemory* mem, uint16_t offset)
{
    // TODO
    return 0; // DEFAULT FOR NOW
}

uint16_t MemShortRead(VirtualMemory* mem, uint16_t offset)
{
    return 0; // DEFAULT FOR NOW
}

void MemWrite(VirtualMemory* mem, uint16_t offset, uint8_t value)
{
    // TODO
}

void MemShortWrite(VirtualMemory* mem, uint16_t offset, uint16_t value)
{
    // TODO
}

/* MISC */
void ReadFile(State8080* state, const char* filename, uint32_t offset)
{
    FILE* fp = fopen(filename, "r+b");

    if (fp == NULL) {
        printf("ERROR: Could not open [%s]", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    rewind(fp);

    uint8_t* buf = &state->memory[offset];
    fread(buf, filesize, 1, fp);
    fclose(fp);
}