#pragma once
#ifndef __OPCODES_H
#define __OPCODES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"

typedef int (*OP)(State8080* state, UNUSED uint16_t basePC, uint8_t opcode);

typedef struct {
    OP      targetFunc; // Pointer to function wrapper
    uint8_t cycleCount; // Total amount of cycles per opcode
    uint8_t size;       // Size of opcode (1, 2, 3 bytes typically)
} opcode_8080;

uint8_t CheckCondition(State8080* state, ConditionFlags identifier);

void SetFlag(State8080* state, uint32_t flagState, uint8_t flags);
// TODO: Add function for Auxiliary carry flag

int UNDEFINED_OPCODE(UNUSED State8080* state, UNUSED uint16_t basePC, UNUSED uint8_t opcode);

/*---- DATA TRANSFER ----*/

void MOV();

void MVI();

void LXI();

void LDA();

void STA();

void LHLD();

void SHLD();

void LDAX();

void STAX();

void XCHG();


/*---- ARITHMETIC ----*/

// ADD_REG, ADD_MEM, ADD_IMM (ADI)
void ADD();

// ADC_REG, ADC_MEM, ADC_IMM (ACI)
void ADC();

// SUB_REG, SUB_MEM, SUB_IMM (SUI)
void SUB();

// SBB_REG, SBB_MEM, SBB_IMM (SBI)
void SBB();

// INR_REG, INR_MEM
void INR();

// DCR_REG, DCR_MEM
void DCR();

// INX_RP
void INX();

// DCX_RP
void DCX();

// DAD_RP
void DAD();

// DAA
void DAA();

/*---- LOGICAL ----*/

// ANA_REG, ANA_IMM (ANI)
void ANA();

// XRA_REG, XRA_IMM (XRI)
void XRA();

// ORA_REG, ORA_IMM (ORI)
void ORA();

// CMP_REG, CMP_MEM, CMP_IMM (CPI)
void CMP();

void RLC();

void RRC();

void RAL();

void RAR();

void CMA();

void CMC();

void STC();

/*---- BRANCH ----*/

void JMP();

void RET();

void RST();

void PCHL();

/*---- STACK I/O MACHINE CONTROL ----*/

// PUSH_RP PUSH_PSW
void PUSH();

// POP_RP, POP_PSW
void POP();

void XTHL();

void SPHL();

void IN();

void OUT();

void EI();

void DI();

void HLT();

void NOP();




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
#endif // __INSTRUCTIONS_H