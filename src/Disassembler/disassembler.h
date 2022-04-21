#pragma once
#ifndef __DISASSEMBLER_H
#define __DISASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED_OP_CODE "UNDF"

int DecodeInstruction(int* buffer, int pc);
unsigned int* ReadFileToHexBuffer(FILE* fp, size_t* filesize);
void PrintHexBuffer(const int* buffer, size_t buflen);


#endif // __DISASSEMBLER_H