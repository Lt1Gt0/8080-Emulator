#pragma once
#ifndef __OPCODES_H
#define __OPCODES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "memory.h"
#include "Debug/debug.h"

#define UNDEFINED_OP_CODE "UNDF"

typedef int (*OP)(State8080* state, UNUSED uint16_t basePC, uint8_t opcode);

typedef struct {
    OP      targetFunc; // Pointer to function wrapper
    uint8_t cycleCount; // Total amount of cycles per opcode
    uint8_t size;       // Size of opcode (1, 2, 3 bytes typically)
} Opcode8080;

uint8_t* ByteRegRef(State8080* state, uint8_t ident)
{
    switch (ident) {
    case 0x00: // (000)
        return &state->b;
    case 0x01: // (001)
        return &state->c;
    case 0x02: // (010)
        return &state->d;
    case 0x03: // (011)
        return &state->e;
    case 0x04: // (100)
        return &state->h;
    case 0x05: // (101)
        return &state->l;
    case 0x06: // (110)
        // Register pair HL is typically used to refer to memory locations
        return (uint8_t*)MemRef(&state->memory, state->hl);
    case 0x07: // (111)
        return &state->a;
    default:
        fprintf(stderr, "Unable to indetify register: %02x", ident);
        exit(-1);
    }
}

uint16_t* ShortRegRef(State8080* state, uint8_t ident)
{
    switch (ident) {
    case 0x00: // (000)
        return &state->bc;
    case 0x01: // (001)
        return &state->de;
    case 0x02: // (010)
        return &state->hl;
    case 0x03: // (011)
        return &state->sp;
    default:
        fprintf(stderr, "Unable to identify register: %04x", ident);
        exit(-1);
    }
}

uint8_t CheckCondition(State8080* state, ConditionFlags identifier)
{
    switch (identifier) {
    case NZ:
        if (!state->PSW.z)
            return 1;
        return 0;
    case Z:
        if (state->PSW.z)
            return 1;
        return 0; 
    case NC:
        if (!state->PSW.cy)
            return 1;
        return 0;
    case C:
        if (state->PSW.cy)
            return 1;
        return 0;
    case PO:
        if (!state->PSW.p)
            return 1;
        return 0;
    case PE:
        if (state->PSW.p)
            return 1;
        return 0;
    case P:
        if (!state->PSW.s)
            return 1;
        return 0;
    case M:
        if (state->PSW.s)
            return 1;
        return 0;
    default: // Should not check ever
        fprintf(stderr, "Undefined Flag Identifier - %d", identifier);
        exit(-1);
    }
}

/* This wont do anything to affect the AC flag */
void SetFlags(State8080* state, uint32_t stateFinal, uint8_t flags)
{
    if (flags & SIGN_FLAG) {
        // Check for sign in bit in the first 8 bits of stateFinal
        state->PSW.s = (stateFinal & 0x80) ? 1 : 0; 
    }

    if (flags & ZERO_FLAG) {
        // Check the first 8 bits to see if any are, if so z = 0
        state->PSW.z = (stateFinal & 0xFF) ? 0 : 1;
    }

    if (flags & AUX_FLAG)
        // I dont know what do for AUX right now so I will leave it unaffected
        fprintf(stderr, "Unable to affect flag: Auxiliary Carry");

    if (flags & PARITY_FLAG) {
        uint8_t check = stateFinal & 0xFF;
        int totalBits = 0;
        
        for (int i = 0; i < 8; i++) {
            if (check & 1)
                totalBits++;
            check >>= 1;
        }

        // If totalBits is odd, P = 0
        state->PSW.p = (totalBits & 1) ? 0 : 1;
    }

    if (flags & CARRY_FLAG) {
        // If the bit past the 8 bit limit is on, set cy = 1
        state->PSW.cy = (stateFinal & 0x100) ? 1 : 0;
    }

}

void auxSet(State8080* state, uint32_t baseVal, uint32_t dif)
{

}

uint8_t PackPSW(ProcStatusWord psw)
{
    uint8_t status;
    status |= psw.s ? SIGN_FLAG : 0;
    status |= psw.z ? ZERO_FLAG : 0;
    status |= psw.ac ? AUX_FLAG : 0;
    status |= psw.p ? PARITY_FLAG : 0;
    status |= psw.cy ? CARRY_FLAG : 0;
    return status;
}

ProcStatusWord UnpackPSW(uint8_t status)
{
    ProcStatusWord psw;
    psw.s = status & SIGN_FLAG ? 1 : 0; 
    psw.z = status & ZERO_FLAG ? 1 : 0; 
    psw.ac = status & AUX_FLAG ? 1 : 0;
    psw.p = status & PARITY_FLAG ? 1 : 0;
    psw.cy = status & CARRY_FLAG ? 1 : 0;
    return psw;
}

// TODO: Add function for Auxiliary carry flag

int UNDEFINED_OPCODE(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    fprintf(stderr, "Undefined Instruction\n");
    exit(-1);

    return -1;
}

/*---- DATA TRANSFER ----*/

/**
 * MOV r1, r2
 *  (r1) <- (r2)
 * 
 * MOV r, M
 *  (r) <- ((H) (L))
 * 
 * MOV M, r
 *  ((H) (L)) <- (r)
 * 
 * Flags - None
 */
int MOV(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    /* 
    01 DDD SSS
    00 111 000 >> 3 = DDD
    */
    uint8_t dstIdentifier = (0x38 & opcode) >> 3;
    uint8_t srcIdentifier = (0x07 & opcode);

    uint8_t* dst = ByteRegRef(state, dstIdentifier);
    uint8_t* src = ByteRegRef(state, srcIdentifier);
    *dst = *src;
    PRINT_DECOMPILED(basePC, "MOV r(%X), r(%X)\n", dstIdentifier, srcIdentifier);
    return 1;
}

/**
 * MVI r, data 
 *  (r) <- (byte 2)
 * 
 * MVI M, data
 *  ((H) (L)) <- (byte 2)
 * 
 * Flags - None
 */
int MVI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t dstIdentifier = (0x38 & opcode) >> 3;
    uint8_t imm = MemRead(&state->memory, basePC + 1);
    uint8_t* dst = ByteRegRef(state, dstIdentifier);
    *dst = imm;
    PRINT_DECOMPILED(basePC, "MVI r(%X), (%X)\n", dstIdentifier, imm);
    return 1;
}

 
 /**
  * LXI rp, D16
  * 
  * (rh) <- (byte 3)
  * (rl) <- (byte 2)
  * 
  * Flags - None  
  */
int LXI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t dstIdentifier = (0x30 & opcode) >> 4;
    uint16_t imm = MemShortRead(&state->memory, basePC + 1);
    uint16_t* dst = ShortRegRef(state, dstIdentifier);
    *dst = imm;
    PRINT_DECOMPILED(basePC, "LXI rp(%X), (%X)\n", dstIdentifier, imm);
    return 1;
}

/**
 * LDA
 * 
 * (A) <- ((byte 3)(byte 2)) 
 * 
 * Flags - None
 */
int LDA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t loadData = MemShortRead(&state->memory, basePC + 1);
    state->a = MemShortRead(&state->memory, loadData);

    PRINT_DECOMPILED(basePC, "%s\n", "LDA");
    return 1;
}

/**
 * Store Accumulator Direct
 *  
 * ((byte 3) (byte 2)) <- A
 * 
 * Flags: None
 */
int STA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t offset = MemShortRead(&state->memory, basePC + 1);
    MemShortWrite(&state->memory, offset, state->a);
    PRINT_DECOMPILED(basePC, "%s\n", "STA");
    return 1;
}

/**
 * LHLD
 * 
 * (L) <- ((byte 3)(byte 2))
 * (H) <- ((byte 3)(byte 2) + 1)
 *  
 * Flags - None
 */
int LHLD(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * SHLD
 * 
 * ((byte 3)(byte 2)) <- (L)
 * ((byte 3)(byte 2) + 1) <- (H)
 *  
 * Flags - None
 */
int SHLD(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * LDAX
 * 
 * (A) <- ((rp))
 * 
 * Flags - None
 */
int LDAX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regIdentifier = (opcode & 0x30) >> 4;

    if (regIdentifier < 2) {
        uint16_t* reg = ShortRegRef(state, regIdentifier);
        state->a = MemRead(&state->memory, *reg);
        PRINT_DECOMPILED(basePC, "LDAX rp(%X), %X\n", regIdentifier, state->a);
    } else {
        fprintf(stderr, "ILLEGAL OPCODE");
        exit(-1);
    }
    return 1;
}

/**
 * STAX 
 * 
 * ((rp)) <- (A)
 * i
 * Flags - None
 */
int STAX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    PRINT_DECOMPILED(basePC, "%s\n", "STAX");
    return 1;
}

/**
 * XCHG
 * 
 * (H) <--> (D)
 * (L) <--> (E) 
 *  
 * Flags - None
 */
int XCHG(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t tmp = state->hl;
    state->hl = state->de;
    state->de = tmp;

    PRINT_DECOMPILED(basePC, "%s\n", "XCHG");    
    return 1;
}

/*---- ARITHMETIC ----*/

/**
 * ADD REG, ADD MEM 
 * 
 * (A) <- (A) + (r)
 * (A) <- (A) + ((H) (L))
 * 
 * Flags - Z, S, P, CY, AC
 */
int ADD(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regIdentifier = (0x07 & opcode);
    uint16_t tmp = *(ByteRegRef(state, regIdentifier));
    tmp += state->a;

    SetFlags(state, tmp, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    //TODO: Affect AC flag

    state->a = tmp;
    PRINT_DECOMPILED(basePC, "ADD r(%X)\n", regIdentifier);

    return 1;
}

/**
 * ADD_IMM
 * 
 * (A) <- (A) + (byte 2)
 * 
 * Flags - Z, S, P, CY, AC
 */
int ADI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t imm = MemRead(&state->memory, basePC + 1);
    imm += state->a;

    SetFlags(state, imm, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    //TODO: Affect AC flag

    state->a = imm;
    PRINT_DECOMPILED(basePC, "ADI (%X)\n", imm);
    return 1;
}

/**
 * ADC_REG, ADC_MEM 
 * 
 * (A) <- (A) + (r) + (CY)
 * (A) <- (A) + ((H) (L)) + (CY)
 *  
 * Flags - Z, S, P, CY, AC
 */
int ADC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t regIdentifier = (0x07 & opcode);
    uint16_t tmp = *(ByteRegRef(state, regIdentifier));
    tmp += state->a + state->PSW.cy;
    
    SetFlags(state, state->a, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    state->a = tmp;
    PRINT_DECOMPILED(basePC, "ADC (%X)\n", tmp);
    return 1;
}

/**
 * ACI
 * 
 * (A) <- (A) + (byte 2) + (CY)
 * 
 * Flags: Z, S, P, CY, AC
 */
int ACI(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint16_t imm = MemRead(&state->memory, basePC + 1);
    imm += state->a + state->PSW.cy;

    SetFlags(state, imm, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    state->a = imm;
    PRINT_DECOMPILED(basePC, "ACI (%X)\n", imm);
    return 1;
}

// SUB_REG, SUB_MEM
// Flags: Z, S, P, CY, AC
int SUB(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

// SUB_IMM
// Flags: Z, S, P, CY, AC
int SUI(State8080* state,UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// SBB_REG, SBB_MEM
// Flags: Z, S, P, CY, AC
int SBB(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

// SBB_IMM
// Flags: Z, S, P, CY, AC
int SBI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// INR_REG, INR_MEM
// Flags: Z, S, P, AC
int INR(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

/**
 * DCR_REG, DCR_MEM
 * 
 * (r) <- (r) - 1
 * ((H) (L)) <- ((H) (L)) - 1
 *  
 * Flags: Z, S, P, AC
 */
int DCR(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regIdentifier = (opcode & 0x38) >> 3;
    uint8_t* reg = ByteRegRef(state, regIdentifier);
    uint16_t tmp = *reg;
    tmp -= 1;

    SetFlags(state, tmp, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG);
    // TODO: Affect AC flag

    *reg = (uint8_t)tmp;
    PRINT_DECOMPILED(basePC, "DCR r(%X)\n", regIdentifier);
    return 1;
}

/**
 * INX 
 * 
 * (rh) (rl) <- (rh) (rl) + 1
 * 
 * Flags - None
 */
int INX(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regPairIdentifier = (opcode & 0x30) >> 4;
    uint16_t* regPair = ShortRegRef(state, regPairIdentifier);
    *regPair += 1;

    PRINT_DECOMPILED(basePC, "INX r(%X)\n", regPairIdentifier);
    return 1;
}

// DCX_RP
// Flags: None
int DCX(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * DAD_RP
 * 
 * (H) (L) <- (H) (L) + (rh) (rl) 
 * 
 * Flags - CY
 */
int DAD(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regPairIdentifier = (0x30 & opcode) >> 4;
    uint16_t* target = ShortRegRef(state, regPairIdentifier);
    uint32_t tmp = state->hl;

    tmp += *target;
    state->hl = tmp & 0xFFFF;
    state->PSW.cy = (state->hl < tmp) ? 1 : 0;
    
    PRINT_DECOMPILED(basePC, "DAD rp(%X)\n", regPairIdentifier);
    return 1;
}

// DAA
// Flags: Z, S, P, CY, AC
int DAA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/*---- LOGICAL ----*/

/**
 * ANA_REG
 *  
 * (A) <- (A) & (r)
 * (A) <- (A) & ((H) (L))
 * 
 * Flags - Z, S, P, CY, AC
 * (CY flag is cleared)
 */
int ANA(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regIdentifier = (opcode & 0x07);
    uint8_t* reg = ByteRegRef(state, regIdentifier);
    uint8_t base = state->a;
    uint8_t target = *reg;
    base &= target;

    SetFlags(state, state->a, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    state->a = target;
    PRINT_DECOMPILED(basePC, "ANA r(%X)\n", regIdentifier);
    return 1;
}

/**
 * ANA_IMM
 * 
 * (A) <- (A) & (byte 2)
 *  
 * Flags - Z, S, P, CY, AC
 * (CY and AC flags are cleared)
 */
int ANI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t imm = MemRead(&state->memory, basePC + 1);
    state->a &= imm;

    SetFlags(state, state->a, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    // state->a = tmp;
    PRINT_DECOMPILED(basePC, "ANI (%X)\n", imm)
    return 1;
}

/**
 * XRA_REG
 * 
 * (A) <- (A) ^ (r) 
 * (A) <- (A) ^ ((H) (L))
 * 
 * Flags - Z, S, P, CY, AC
 * (CY and AC flags are cleared)
 */
int XRA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t regIdentifier = (opcode & 0x07);
    uint8_t* reg = ByteRegRef(state, regIdentifier);
    uint8_t base = state->a;
    uint8_t target = *reg;
    base ^= target;

    SetFlags(state, state->a, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    state->a = target;
    PRINT_DECOMPILED(basePC, "XRA r(%X)\n", regIdentifier)
    return 1;
}

/**
 * XRA_IMM
 * 
 * (A) <- (A) ^ (byte 2) 
 * 
 * Flags - Z, S, P, CY, AC
 * (CY and AC flags are cleared)
 */
int XRI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t imm = MemRead(&state->memory, basePC + 1);
    state->a ^= imm;

    SetFlags(state, state->a, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    PRINT_DECOMPILED(basePC, "XRI (%X)\n", imm);
    return 1;
}

// ORA_REG
// Flags: Z, S, P, CY, AC
// (CY and AC flags are cleared)
int ORA(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

// ORA_IMM
// Flags: Z, S, P, CY, AC
// (CY and AC flags are cleared)
int ORI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * CMP_REG, CMP_MEM
 * 
 * (A) - (r)
 * (A) - ((H) (L)) 
 * 
 * Flags - Z, S, P, CY, AC
 * Z = 1 if (A) = (r)
 * CY = 1 if (A) < (r)
 */
int CMP(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    uint8_t regIdentifier = (opcode & 0x07);
    uint8_t* reg = ByteRegRef(state, regIdentifier);
    uint8_t res = state->a - *reg;

    SetFlags(state, res, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flag

    PRINT_DECOMPILED(basePC, "CMP (%X)\n", regIdentifier);
    return 1;
}

/**
 * Compare Immedate 
 * 
 * (A) - (byte 2)
 * 
 * Flags: Z, S, P, CY, AC
 * (Z = 1 if (A) = (byte 2). CY = 1 if (A) < (byte 2))
 */
int CPI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t imm = MemRead(&state->memory, basePC + 1);
    uint16_t res = state->a - imm;

    SetFlags(state, res, ZERO_FLAG | SIGN_FLAG | PARITY_FLAG | CARRY_FLAG);
    // TODO: Affect AC flagi

    PRINT_DECOMPILED(basePC, "CPI (%X)\n", imm);
    return 1;
}

// Flags: CY
int RLC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * RRC 
 * 
 * (A(n)) <- (A(n-1)); (A7) <- (A0)
 * (CY) <- (A0)
 *  
 * Flags - CY
 */
int RRC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t lsb = 0x1 & state->a;
    state->a >>= 1;

    if (lsb) {
        state->a |= 0x80;
        state->PSW.cy = 1;
    } else {
        state->PSW.cy = 0;
    }
    
    PRINT_DECOMPILED(basePC, "%s\n", "RRC");
    return 1;
}

// Flags: CY
int RAL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// Flags: CY
int RAR(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// Flags: None
int CMA(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// Flags: CY
int CMC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

// Flags: CY
int STC(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/*---- BRANCH ----*/

/*
NZ -> not zero (Z = 0) (000)
Z -> zero (Z = 1) (001)
NC -> no carry (CY = 0) (010)
C -> carry (CY = 1) (011)
PO -> parity odd (P = 0) (100)
PE -> parity even (P = 1) (101)
P -> plus (S = 0) (110)
M -> minus (S = 1) (111)

All of this is stored in the cpu as the ConditionFlags enum
*/

/**
 * JMP without conditions
 * 
 * (PC) <- (byte 3)(byte 2) 
 * 
 * Flags - None
 */
int JMP(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{      
    if (opcode == 0xC3) {
        state->pc = MemShortRead(&state->memory, basePC + 1);
        PRINT_DECOMPILED(basePC, "JMP (%X)\n", state->pc);
    } else if (opcode == 0xCB) {
        PRINT_DECOMPILED(basePC, "%s\n", "UNDF");
        exit(-1);
    } else {
        fprintf(stderr, "Illegal Opcode");
        exit(-1);
    }
    return 1;
}

/**
 * JMP with conditions
 * 
 * if (CCC),
 *  (PC) <- (byte 3)(byte 2) 
 * 
 * flags - None
 */
int JMPCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    if (CheckCondition(state, (0x38 & opcode) >> 3)) {
        state->pc = MemShortRead(&state->memory, basePC + 1);
    }

    PRINT_DECOMPILED(basePC, "JMP con(%X) %X\n", (0x38 & opcode) >> 3, MemShortRead(&state->memory, basePC + 1));
    return 1;
}

/**
 * CALL
 * 
 * ((SP) - 1) <- (PCH)
 * ((SP) - 2) <- (PCL)
 * (SP) <- (SP) - 2 
 * (PC) <- (byte 3)(byte 2) 
 * 
 * Flags - None 
 */
int CALL(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    if (opcode == 0xCD) {
        state->sp -= 2;
        MemShortWrite(&state->memory, state->sp, state->pc);
        state->pc = MemShortRead(&state->memory, basePC + 1);
        PRINT_DECOMPILED(basePC, "CALL (%X)\n", state->pc);
    } else {
        PRINT_DECOMPILED(basePC, "%s\n", "UNDF");
    }
    return 1;
}

// Condition Call
// Flags: None
int CCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

/**
 * RET without conditioins 
 *
 * (PCL) <- ((SP))
 * (PCH) <- ((SP) + 1)
 * (SP) <- (SP) + 2
 *  
 * Flags - None
 */
int RET(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    if (opcode == 0xC9) {
        state->pc = MemShortRead(&state->memory, state->sp);
        state->sp += 2;
        PRINT_DECOMPILED(basePC, "%s\n", "RET");
    } else {
        PRINT_DECOMPILED(basePC, "%s\n", "UNDF");
        exit(-1);
    }
    return 1;
}


// Conditional Return
// Flags: None
int RETCON(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    return 1;
}

/**
 * RST
 * 
 * ((SP) - 1) <- (PCH)
 * ((SP) - 2) <- (PCL)
 * (SP) <- (SP) - 2
 * (PC) <- 8 * (NNN)
 *  
 * Flags - None
 */
int RST(State8080* state, UNUSED uint16_t basePC, uint8_t opcode)
{
    state->sp -= 2;
    MemShortWrite(&state->memory, state->sp, state->pc);

    uint16_t target = ((0x38 & opcode) >> 3);
    state->pc = target * 8;
    state->int_enable = 0;

    PRINT_DECOMPILED(basePC, "RST %X\n", target);
    return 1;
}

// Jump H and L indirect -> move H and L to PC
// Flags: None
int PCHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    state->pc = state->hl;
    PRINT_DECOMPILED(basePC, "%s\n", "PCHL");
    return 1;
}

/*---- STACK I/O MACHINE CONTROL ----*/

/**
 * PUSH_RP
 * ((SP) - 1) <- (rh)
 * ((SP) - 2) <- (rl)
 * (SP) <- (SP) - 2
 * 
 * PUSH_PSW
 * ((SP) - 1) = (A)
 * ((SP) - 2)0 <- (CY), ((SP) - 2)1 <- 1
 * ((SP) - 2)2 <- (P), ((SP) - 2)3 <- 0
 * ((SP) - 2)4 <- (AC), ((SP) - 2)5 <- 0
 * ((SP) - 2)6 <- (Z), ((SP) - 2)7 <- (S)
 * (SP) <- (SP) - 2
 * 
 * Flags - None
 */
int PUSH(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t regPairIdentifier = (0x30 & opcode) >> 4;

    if (regPairIdentifier == 0x3) {
        state->sp -= 2;
        MemWrite(&state->memory, state->sp, PackPSW(state->PSW));
        MemWrite(&state->memory, state->sp + 1, state->a);
        PRINT_DECOMPILED(basePC, "%s\n", "PUSH PSW");
    } else {
        uint16_t* reg = ShortRegRef(state, regPairIdentifier);
        state->sp -= 2;
        MemShortWrite(&state->memory, state->sp, *reg);
        PRINT_DECOMPILED(basePC, "PUSH rp(%X)\n", regPairIdentifier);
    }

    return 1;
}

/**
 * POP_RP
 * (rl) <- ((SP))
 * (rh) <- ((SP) + 1)
 * (SP) <- (SP) + 2
 * 
 * POP_PSW
 * (CY) <- ((SP))0
 * (P) <- ((SP))2
 * (AC) <- ((SP))4
 * (Z) <- ((SP))6
 * (S) <- ((SP))7
 * (A) <- (SP) + 1
 * (SP) <- (SP) + 2
 *  
 * Flags - None
 */
// POP_RP, POP_PSW
// Flags: None
int POP(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t regPairIdentifier = (0x30 & opcode) >> 4;

    if (regPairIdentifier == 0x03) {
        state->PSW = UnpackPSW(MemRead(&state->memory, state->sp));
        state->a = MemRead(&state->memory, state->sp + 1);
        state->sp += 2;
        PRINT_DECOMPILED(basePC, "%s\n", "POP PSW");
    } else {
        uint16_t* reg = ShortRegRef(state, regPairIdentifier);
        *reg = MemShortRead(&state->memory, state->sp);
        state->sp += 2;
        PRINT_DECOMPILED(basePC, "POP rp(%X)\n", regPairIdentifier);
    }

    return 1;
}

/**
 * XTHL
 * 
 * (L) <--> ((SP))
 * (H) <--> ((SP) + 1)
 *  
 * Flags - None
 */
int XTHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint16_t tmp = MemShortRead(&state->memory, state->sp);
    MemShortWrite(&state->memory, state->sp, state->hl);
    state->hl = tmp;
    
    PRINT_DECOMPILED(basePC, "%s\n", "XTHL");
    return 1;
}

/**
 * SPHL
 * 
 * (SP) <- ((H) (L))
 *  
 * Flags - None
 */
int SPHL(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    state->sp = state->hl;
    PRINT_DECOMPILED(basePC, "%s\n", "SPHL");
    return 1;
}

// Flags: None
int IN(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    return 1;
}

/**
 * OUT
 * 
 * (data) <- (A)
 * 
 * Flags - None  
 */
int OUT(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    uint8_t port = MemRead(&state->memory, basePC + 1);
    state->ProcOUT(port, state->a);

    PRINT_DECOMPILED(basePC, "OUT %X\n", port);
    return 1;
}

/**
 * EI
 * 
 * Enable Interrupts
 *  
 * Flags - None
 */
int EI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    state->int_enable = 1;
    PRINT_DECOMPILED(basePC, "%s\n", "EI");
    return 1;
}

/**
 * DI 
 * 
 * Disable Interrupts
 * 
 * Flags - None
 */
int DI(State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    state->int_enable = 0;
    PRINT_DECOMPILED(basePC, "%s\n", "DI");
    return 1;
}

/**
 * HALT
 * 
 * Flags - None 
 */
int HLT(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    state->halt = 1;
    PRINT_DECOMPILED(basePC, "%s\n", "HLT");
    return 1;
}

// Flags: None
int NOP(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode)
{
    PRINT_DECOMPILED(basePC, "%s\n", "NOP");
    return 1;
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
    [0x16] = {MVI, 7, 2},
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
    [0x76] = {HLT, 7, 1},
    [0x77] = {MOV, 5, 1},
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
    [0xC0] = {RETCON, 11, 1},
    [0xC1] = {POP, 10, 1},
    [0xC2] = {JMPCON, 10, 3},
    [0xC3] = {JMP, 10, 3},
    [0xC4] = {CCON, 17, 3},
    [0xC5] = {PUSH, 11, 1},
    [0xC6] = {ADI, 7, 2},
    [0xC7] = {RST, 11, 1},
    [0xC8] = {RETCON, 11, 1},
    [0xC9] = {RET, 10, 1},
    [0xCA] = {JMPCON, 10, 3},
    [0xCB] = {JMP, 10, 3},
    [0xCC] = {CCON, 17, 3},
    [0xCD] = {CALL, 17, 3},
    [0xCE] = {ACI, 7, 2},
    [0xCF] = {RST, 11, 1},
    [0xD0] = {RETCON, 11, 1},
    [0xD1] = {POP, 10, 1},
    [0xD2] = {JMPCON, 10, 3},
    [0xD3] = {OUT, 10, 2},
    [0xD4] = {CCON, 17, 3},
    [0xD5] = {PUSH, 11, 1},
    [0xD6] = {SUI, 7, 2},
    [0xD7] = {RST, 11, 1},
    [0xD8] = {RETCON, 11, 1},
    [0xD9] = {RET, 10, 1},
    [0xDA] = {JMPCON, 10, 3},
    [0xDB] = {IN, 10, 2},
    [0xDC] = {CCON, 17, 3},
    [0xDD] = {CALL, 17, 3},
    [0xDE] = {SBI, 7, 2},
    [0xDF] = {RST, 11, 1},
    [0xE0] = {RETCON, 11, 1},
    [0xE1] = {POP, 10, 1},
    [0xE2] = {JMPCON, 10, 3},
    [0xE3] = {XTHL, 18, 1},
    [0xE4] = {CCON, 17, 3},
    [0xE5] = {PUSH, 11, 1},
    [0xE6] = {ANI, 7, 2},
    [0xE7] = {RST, 11, 1},
    [0xE8] = {RETCON, 11, 1},
    [0xE9] = {PCHL, 5, 1},
    [0xEA] = {JMPCON, 10, 3},
    [0xEB] = {XCHG, 5, 1},
    [0xEC] = {CCON, 17, 3},
    [0xED] = {CALL, 17, 3},
    [0xEE] = {XRI, 7, 2},
    [0xEF] = {RST, 11, 1},
    [0xF0] = {RETCON, 11, 1},
    [0xF1] = {POP, 10, 1},
    [0xF2] = {JMPCON, 10, 3},
    [0xF3] = {DI, 4, 1},
    [0xF4] = {CCON, 17, 3},
    [0xF5] = {PUSH, 11, 1},
    [0xF6] = {ORI, 7, 2},
    [0xF7] = {RST, 11, 1},
    [0xF8] = {RETCON, 11, 1},
    [0xF9] = {SPHL, 5, 1},
    [0xFA] = {JMPCON, 10, 3},
    [0xFB] = {EI, 4, 1},
    [0xFC] = {CCON, 17, 3},
    [0xFD] = {CALL, 17, 3},
    [0xFE] = {CPI, 7, 2},
    [0xFF] = {RST, 11, 1}
};

#endif // __OPCODES_H