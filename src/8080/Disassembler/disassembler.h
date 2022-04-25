#pragma once
#ifndef __DISASSEMBLER_H
#define __DISASSEMBLER_H

#include "../8080.h"

#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED_OP_CODE "UNDF"

int DecodeInstruction(unsigned char* buffer, int pc);
void ReadFile(State8080* state, const char* filename, uint32_t offset);
void PrintHexBuffer(const unsigned char* buffer, size_t buflen);


#endif // __DISASSEMBLER_H