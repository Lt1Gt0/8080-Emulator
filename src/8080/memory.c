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