// #pragma once
// #ifndef __DISASSEMBLER_H
// #define __DISASSEMBLER_H

// #include "8080/cpu.h"

// #include <stdio.h>
// #include <stdlib.h>


// int DecodeInstruction(unsigned char* buffer, int pc);
// void ReadFile(State8080* state, const char* filename, uint32_t offset);
// void PrintHexBuffer(const unsigned char* buffer, size_t buflen);

// /* OPCODE PRINTING */
// void PrintOpcode(const char* opcodeStr, const unsigned char opcode);
// void PrintOpcodeReg(const char* opcodeStr, const char* reg, const unsigned char opcode);
// void PrintMultipleOperands(const char* opcodeStr, const unsigned char* opcodes, int opCount);
// void PrintRegMultipleOperands(const char* opcodeStr, const unsigned char* reg, const unsigned char* opcodes, int opCount);

// #endif // __DISASSEMBLER_H