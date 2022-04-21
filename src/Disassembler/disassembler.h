#pragma once
#ifndef __DISASSEMBLER_H
#define __DISASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>

#define UNDEFINED_OP_CODE "UNDF"

char* GetOpcode(int opcode);
int* ReadFileToHexBuffer(FILE* fp, size_t* filesize);
void PrintHexBuffer(const int* buffer, size_t buflen);


#endif // __DISASSEMBLER_H