#pragma once
#ifndef __OPCODES_H
#define __OPCODES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

#define UNDEFINED_OP_CODE "UNDF"

typedef int (*OP)(State8080* state, UNUSED uint16_t basePC, uint8_t opcode);

typedef struct {
    OP      targetFunc; // Pointer to function wrapper
    uint8_t cycleCount; // Total amount of cycles per opcode
    uint8_t size;       // Size of opcode (1, 2, 3 bytes typically)
} Opcode8080;


uint8_t CheckCondition(State8080* state, ConditionFlags identifier)
{

}

void SetFlag(State8080* state, uint32_t flagState, uint8_t flags)
{

}

// TODO: Add function for Auxiliary carry flag

int UNDEFINED_OPCODE(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    printf("Undefined Instruction");
    exit(-1);
}

/*---- DATA TRANSFER ----*/

int MOV(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    
}

int MVI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int LXI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int LDA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int STA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int LHLD(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int SHLD(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int LDAX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int STAX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int XCHG(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}


/*---- ARITHMETIC ----*/

// ADD_REG, ADD_MEM,
int ADD(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// ADD_IMM
int ADI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// ADC_REG, ADC_MEM
int ADC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int ACI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// SUB_REG, SUB_MEM
int SUB(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// SUB_IMM
int SUI(State8080* state,UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// SBB_REG, SBB_MEM
int SBB(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// SBB_IMM
int SBI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// INR_REG, INR_MEM
int INR(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// DCR_REG, DCR_MEM
int DCR(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// INX_RP
int INX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// DCX_RP
int DCX(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// DAD_RP
int DAD(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// DAA
int DAA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

/*---- LOGICAL ----*/

// ANA_REG
int ANA(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// ANA_IMM
int ANI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// XRA_REG
int XRA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// XRA_IMM
int XRI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// ORA_REG
int ORA(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// ORA_IMM
int ORI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// CMP_REG, CMP_MEM
int CMP(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int CPI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int RLC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int RRC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int RAL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int RAR(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int CMA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int CMC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int STC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

/*---- BRANCH ----*/

// JMP without conditions
int JMP(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// JMP with conditions
int JMPCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int CALL(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int CCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

// RET with(out) conditions
int RET(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int RCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int RST(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{

}

int PCHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

/*---- STACK I/O MACHINE CONTROL ----*/

// PUSH_RP PUSH_PSW
int PUSH(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// POP_RP, POP_PSW
int POP(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int XTHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int SPHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int IN(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int OUT(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int EI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int DI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int HLT(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

int NOP(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{

}

// Look up table for each 8080 opcode (256 opcodes in the 8080 manual)
Opcode8080 opcodeLookUp[256] = { /* Github doesn't like clean formatting :( */
    [0x00] = {NOP, 4, 1},
    [0x01] = {LXI, 10, 3},
    [0x02] = {STAX, 7, 1},
    [0x03] = {INX, 5, 1},
    [0x04] = {INR, 5, 1},
    [0x05] = {DCR, 5, 1},
    [0x06] = {MVI, 7, 2},
    [0x07] = {RLC, 7, 1},
    [0x08] = {NOP, 4, 1},
    [0x09] = {DAD, 10, 1},
    [0x0A] = {LDAX, 7, 1},
    [0x0B] = {DCX, 5, 1},
    [0x0C] = {INR, 5, 1},
    [0x0D] = {DCR, 5, 1},
    [0x0E] = {MVI, 7, 2},
    [0x0F] = {RRC, 4, 1},
    [0x10] = {NOP, 4, 1},
    [0x11] = {LXI, 10, 3},
    [0x12] = {STAX, 7, 1},
    [0x13] = {INX, 5, 1},
    [0x14] = {INR, 5, 1},
    [0x15] = {DCR, 5, 1},
    [0x16] = {MVI, 7, 1},
    [0x17] = {RAL, 4, 1},
    [0x18] = {NOP, 4, 1},
    [0x19] = {DAD, 10, 1},
    [0x1A] = {LDAX, 7, 1},
    [0x1B] = {DCX, 5, 1},
    [0x1C] = {INR, 5, 1},
    [0x1D] = {DCR, 5, 1},
    [0x1E] = {MVI, 7, 2},
    [0x1F] = {RAR, 4, 1},
    [0x20] = {NOP, 4, 1},
    [0x21] = {LXI, 10, 3},
    [0x22] = {SHLD, 16, 3},
    [0x23] = {INX, 5, 1},
    [0x24] = {INR, 5, 1},
    [0x25] = {DCR, 5, 1},
    [0x26] = {MVI, 7, 2},
    [0x27] = {DAA, 4, 1},
    [0x28] = {NOP, 4, 1},
    [0x29] = {DAD, 10, 1},
    [0x2A] = {LHLD, 16, 3},
    [0x2B] = {DCX, 5, 1},
    [0x2C] = {INR, 5, 1},
    [0x2D] = {DCR, 5, 1},
    [0x2E] = {MVI, 7, 2},
    [0x2F] = {CMA, 4, 1},
    [0x30] = {NOP, 4, 1},
    [0x31] = {LXI, 10, 3},
    [0x32] = {STA, 13, 3},
    [0x33] = {INX, 5, 1},
    [0x34] = {INR, 5, 1},
    [0x35] = {DCR, 5, 1},
    [0x36] = {MVI, 10, 2},
    [0x37] = {STC, 4, 1},
    [0x38] = {NOP, 4, 1},
    [0x39] = {DAD, 10, 1},
    [0x3A] = {LDA, 13, 3},
    [0x3B] = {DCX, 5, 1},
    [0x3C] = {INR, 5, 1},
    [0x3D] = {DCR, 5, 1},
    [0x3E] = {MVI, 7, 2},
    [0x3F] = {CMC, 4, 1},
    [0x40] = {MOV, 5, 1},
    [0x41] = {MOV, 5, 1},
    [0x42] = {MOV, 5, 1},
    [0x43] = {MOV, 5, 1},
    [0x44] = {MOV, 5, 1},
    [0x45] = {MOV, 5, 1},
    [0x46] = {MOV, 5, 1},
    [0x47] = {MOV, 5, 1},
    [0x48] = {MOV, 5, 1},
    [0x49] = {MOV, 5, 1},
    [0x4A] = {MOV, 5, 1},
    [0x4B] = {MOV, 5, 1},
    [0x4C] = {MOV, 5, 1},
    [0x4D] = {MOV, 5, 1},
    [0x4E] = {MOV, 5, 1},
    [0x4F] = {MOV, 5, 1},
    [0x50] = {MOV, 5, 1},
    [0x51] = {MOV, 5, 1},
    [0x52] = {MOV, 5, 1},
    [0x53] = {MOV, 5, 1},
    [0x54] = {MOV, 5, 1},
    [0x55] = {MOV, 5, 1},
    [0x56] = {MOV, 5, 1},
    [0x57] = {MOV, 5, 1},
    [0x58] = {MOV, 5, 1},
    [0x59] = {MOV, 5, 1},
    [0x5A] = {MOV, 5, 1},
    [0x5B] = {MOV, 5, 1},
    [0x5C] = {MOV, 5, 1},
    [0x5D] = {MOV, 5, 1},
    [0x5E] = {MOV, 5, 1},
    [0x5F] = {MOV, 5, 1},
    [0x60] = {MOV, 5, 1},
    [0x61] = {MOV, 5, 1},
    [0x62] = {MOV, 5, 1},
    [0x63] = {MOV, 5, 1},
    [0x64] = {MOV, 5, 1},
    [0x65] = {MOV, 5, 1},
    [0x66] = {MOV, 5, 1},
    [0x67] = {MOV, 5, 1},
    [0x68] = {MOV, 5, 1},
    [0x69] = {MOV, 5, 1},
    [0x6A] = {MOV, 5, 1},
    [0x6B] = {MOV, 5, 1},
    [0x6C] = {MOV, 5, 1},
    [0x6D] = {MOV, 5, 1},
    [0x6E] = {MOV, 5, 1},
    [0x6F] = {MOV, 5, 1},
    [0x70] = {MOV, 5, 1},
    [0x71] = {MOV, 5, 1},
    [0x72] = {MOV, 5, 1},
    [0x73] = {MOV, 5, 1},
    [0x74] = {MOV, 5, 1},
    [0x75] = {MOV, 5, 1},
    [0x76] = {MOV, 5, 1},
    [0x77] = {HLT, 7, 1},
    [0x78] = {MOV, 5, 1},
    [0x79] = {MOV, 5, 1},
    [0x7A] = {MOV, 5, 1},
    [0x7B] = {MOV, 5, 1},
    [0x7C] = {MOV, 5, 1},
    [0x7D] = {MOV, 5, 1},
    [0x7E] = {MOV, 5, 1},
    [0x7F] = {MOV, 5, 1},
    [0x80] = {ADD, 4, 1},
    [0x81] = {ADD, 4, 1},
    [0x82] = {ADD, 4, 1},
    [0x83] = {ADD, 4, 1},
    [0x84] = {ADD, 4, 1},
    [0x85] = {ADD, 4, 1},
    [0x86] = {ADD, 4, 1},
    [0x87] = {ADD, 4, 1},
    [0x88] = {ADC, 4, 1},
    [0x89] = {ADC, 4, 1},
    [0x8A] = {ADC, 4, 1},
    [0x8B] = {ADC, 4, 1},
    [0x8C] = {ADC, 4, 1},
    [0x8D] = {ADC, 4, 1},
    [0x8E] = {ADC, 4, 1},
    [0x8F] = {ADC, 4, 1},
    [0x90] = {SUB, 4, 1},
    [0x91] = {SUB, 4, 1},
    [0x92] = {SUB, 4, 1},
    [0x93] = {SUB, 4, 1},
    [0x94] = {SUB, 4, 1},
    [0x95] = {SUB, 4, 1},
    [0x96] = {SUB, 4, 1},
    [0x97] = {SUB, 4, 1},
    [0x98] = {SBB, 4, 1},
    [0x99] = {SBB, 4, 1},
    [0x9A] = {SBB, 4, 1},
    [0x9B] = {SBB, 4, 1},
    [0x9C] = {SBB, 4, 1},
    [0x9D] = {SBB, 4, 1},
    [0x9E] = {SBB, 4, 1},
    [0x9F] = {SBB, 4, 1},
    [0xA0] = {ANA, 4, 1},
    [0xA1] = {ANA, 4, 1},
    [0xA2] = {ANA, 4, 1},
    [0xA3] = {ANA, 4, 1},
    [0xA4] = {ANA, 4, 1},
    [0xA5] = {ANA, 4, 1},
    [0xA6] = {ANA, 4, 1},
    [0xA7] = {ANA, 4, 1},
    [0xA8] = {XRA, 4, 1},
    [0xA9] = {XRA, 4, 1},
    [0xAA] = {XRA, 4, 1},
    [0xAB] = {XRA, 4, 1},
    [0xAC] = {XRA, 4, 1},
    [0xAD] = {XRA, 4, 1},
    [0xAE] = {XRA, 4, 1},
    [0xAF] = {XRA, 4, 1},
    [0xB0] = {ORA, 4, 1},
    [0xB1] = {ORA, 4, 1},
    [0xB2] = {ORA, 4, 1},
    [0xB3] = {ORA, 4, 1},
    [0xB4] = {ORA, 4, 1},
    [0xB5] = {ORA, 4, 1},
    [0xB6] = {ORA, 4, 1},
    [0xB7] = {ORA, 4, 1},
    [0xB8] = {CMP, 4, 1},
    [0xB9] = {CMP, 4, 1},
    [0xBA] = {CMP, 4, 1},
    [0xBB] = {CMP, 4, 1},
    [0xBC] = {CMP, 4, 1},
    [0xBD] = {CMP, 4, 1},
    [0xBE] = {CMP, 4, 1},
    [0xBF] = {CMP, 4, 1},
    [0xC0] = {RCON, 11, 1},
    [0xC1] = {POP, 10, 1},
    [0xC2] = {JMPCON, 10, 3},
    [0xC3] = {JMP, 10, 3},
    [0xC4] = {CCON, 17, 3},
    [0xC5] = {PUSH, 11, 1},
    [0xC6] = {ADI, 7, 2},
    [0xC7] = {RST, 11, 1},
    [0xC8] = {RCON, 11, 1},
    [0xC9] = {RET, 10, 1},
    [0xCA] = {JMPCON, 10, 3},
    [0xCB] = {JMP, 10, 3},
    [0xCC] = {CCON, 17, 3},
    [0xCD] = {CALL, 17, 3},
    [0xCE] = {ACI, 7, 2},
    [0xCF] = {RST, 11, 1},
    [0xD0] = {RCON, 11, 1},
    [0xD1] = {POP, 10, 1},
    [0xD2] = {JMPCON, 10, 3},
    [0xD3] = {OUT, 10, 2},
    [0xD4] = {CCON, 17, 3},
    [0xD5] = {PUSH, 11, 1},
    [0xD6] = {SUI, 7, 2},
    [0xD7] = {RST, 11, 1},
    [0xD8] = {RCON, 11, 1},
    [0xD9] = {RET, 10, 1},
    [0xDA] = {JMPCON, 10, 3},
    [0xDB] = {IN, 10, 2},
    [0xDC] = {CCON, 17, 3},
    [0xDD] = {CALL, 17, 3},
    [0xDE] = {SBI, 7, 2},
    [0xDF] = {RST, 11, 1},
    [0xE0] = {RCON, 11, 1},
    [0xE1] = {POP, 10, 1},
    [0xE2] = {JMPCON, 10, 3},
    [0xE3] = {XTHL, 18, 1},
    [0xE4] = {CCON, 17, 3},
    [0xE5] = {PUSH, 11, 1},
    [0xE6] = {ANI, 7, 2},
    [0xE7] = {RST, 11, 1},
    [0xE8] = {RCON, 11, 1},
    [0xE9] = {PCHL, 5, 1},
    [0xEA] = {JMPCON, 10, 3},
    [0xEB] = {XCHG, 5, 1},
    [0xEC] = {CCON, 17, 3},
    [0xED] = {CALL, 17, 3},
    [0xEE] = {XRI, 7, 2},
    [0xEF] = {RST, 11, 1},
    [0xF0] = {RCON, 11, 1},
    [0xF1] = {POP, 10, 1},
    [0xF2] = {JMPCON, 10, 3},
    [0xF3] = {DI, 4, 1},
    [0xF4] = {CCON, 17, 3},
    [0xF5] = {PUSH, 11, 1},
    [0xF6] = {ORI, 7, 2},
    [0xF7] = {RST, 11, 1},
    [0xF8] = {RCON, 11, 1},
    [0xF9] = {SPHL, 5, 1},
    [0xFA] = {JMPCON, 10, 3},
    [0xFB] = {EI, 4, 1},
    [0xFC] = {CCON, 17, 3},
    [0xFD] = {CALL, 17, 3},
    [0xFE] = {CPI, 7, 2},
    [0xFF] = {RST, 11, 1}
};


// void UndefinedInstruction(State8080* state);

// /* DATA TRANSFER */

// //Flags: none
// void movReg(uint8_t* src, uint8_t* dst);

// //Flags: none
// void movFromMem(State8080* state, uint8_t* reg);

// //Flags: none
// void movToMem(State8080* state, uint8_t* reg);

// //Flags: none
// void mvi(State8080* state, uint8_t* reg, uint8_t imm);

// //Flags: none
// void lxi(State8080* state, uint8_t* rph, uint8_t* rpl, uint8_t dh, uint8_t dl);

// //Flags: none
// void ldax(State8080* state, uint8_t* rph, uint8_t* rpl);

// //Flags: none
// void stax(State8080* state, uint8_t* rph, uint8_t* rpl);

// /* ARITHMETIC */

// //Flags: Z, S, P, CY, AC
// void addReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, CY, AC
// void adcReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, AC
// void inrReg(State8080* state, uint8_t* reg);

// //Flags: None
// void inx(uint8_t* rph, uint8_t* rpl);

// //Flags: Z, S, P, CY, AC
// void subReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, CY, AC
// void sbbReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, AC
// void dcrReg(State8080* state, uint8_t* reg);

// //Flags: None
// void dcx(uint8_t* rph, uint8_t* rpl);

// //Flags: CY
// void dad(State8080* state, uint8_t* rph, uint8_t* rpl);

// //Flags: Z, S, P, CY, AC
// void daa();

// /* LOGICAL */

// //Flags: Z, S, P, CY, AC (CY is cleared)
// void anaReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, CY, AC (CY and AC are cleared)
// void xraReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, CY, AC (CY and AC are cleared)
// void oraReg(State8080* state, uint8_t* reg);

// //Flags: Z, S, P, CY, AC
// // z = 1 if (A) = (r)
// // cy = 1 if (A) < (r)
// void cmpReg(State8080* state, uint8_t* reg);

// /* BRANCH */

// void jmp(State8080* state, uint16_t adr);

// /* STACK, I/O, MACHINE CONTROL */

// void push(State8080* state, uint8_t* rph, uint8_t* rpl);
// void pop(State8080* state, uint8_t* rph, uint8_t* rpl);


// void call(State8080* state, uint8_t adrl, uint8_t adrh);
// // void ret(State8080* state, uint8_t adrl, uint8_t adrh);

// int rst(State8080* state, uint16_t base, uint8_t opcode);

// void ei(State8080* state);
// void di(State8080* state);

// /*
// void hlt();
// void nop();
// */

// /* CONDITIONAL CODES */

// /*

// Condition                   CCC
// NZ  -> not zero (Z = 0)     (000)     
// Z   -> zero (Z = 1)         (001)
// NC  -> no carry (CY = 0)    (010)
// C   -> carry (CY = 1)       (011)
// PO  -> parity odd (P = 0)   (100)
// PE  -> parity even (P =1)   (101)
// P   -> plus (S = 0)         (110)
// M   -> minus (S = 1)        (111)

// */

// void UpdateAllFlags(State8080* state, uint16_t ans);
// int CheckParity(int check, int size);

// void PrintProcState(State8080* state);
#endif // __OPCODES_H