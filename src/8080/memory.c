#include "8080/memory.h"

/* MEMORY MANIPULATION/READING */
void* MemRef(VirtualMemory* mem, uint16_t offset)
{
    return (void*)((uintptr_t)mem->base | offset);
}

uint8_t MemRead(VirtualMemory* mem, uint16_t offset)
{
    return *(uint8_t*)MemRef(mem, offset);
}

uint16_t MemShortRead(VirtualMemory* mem, uint16_t offset)
{
    return *(uint16_t*)MemRef(mem, offset);
}

void MemWrite(VirtualMemory* mem, uint16_t offset, uint8_t value)
{
    uint8_t* target = (uint8_t*)MemRef(mem, offset);
    *target = value;
}

void MemShortWrite(VirtualMemory* mem, uint16_t offset, uint16_t value)
{
    uint16_t* target = (uint16_t*)MemRef(mem, offset);
    *target = value;
}