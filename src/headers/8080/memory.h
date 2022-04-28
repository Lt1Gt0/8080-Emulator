#pragma once
#ifndef __MEMORY_H
#define __MEMORY_H

#include <inttypes.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "cpu.h"


typedef struct {
    void* base;
} VirtualMemory;

/* MEMORY MANIPULATION/READING */
void* MemRef(VirtualMemory* mem, uint16_t offset);
uint8_t MemRead(VirtualMemory* mem, uint16_t offset);
uint16_t MemShortRead(VirtualMemory* mem, uint16_t offset);
void MemWrite(VirtualMemory* mem, uint16_t offset, uint8_t value);
void MemShortWrite(VirtualMemory* mem, uint16_t offset, uint16_t value);

/* MISC */ 
void ReadFile(State8080* state, const char* filename, uint32_t offset);

#endif // __MEMORY_H