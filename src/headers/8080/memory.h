#pragma once
#ifndef __MEMORY_H
#define __MEMORY_H

#include <inttypes.h>

typedef struct {
    void* base;
} VirtualMemory;

/* MEMORY MANIPULATION/READING */
void* MemRef(VirtualMemory* mem, uint16_t offset);
uint8_t MemRead(VirtualMemory* mem, uint16_t offset);
uint16_t MemShortRead(VirtualMemory* mem, uint16_t offset);
void MemWrite(VirtualMemory* mem, uint16_t offset, uint8_t value);
void MemShortWrite(VirtualMemory* mem, uint16_t offset, uint16_t value);

#endif // __MEMORY_H