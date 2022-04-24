#pragma once
#ifndef __INSTRUCTIONS_H
#define __INSTRUCTIONS_H

#include <stdint.h>
#include <stdio.h>
#include "structs.h"

/* DATA TRANSFER */

//Flags: none
void movReg(uint8_t* src, uint8_t* dst);

//Flags: none
void movFromMem(State8080* state, uint8_t* reg);

//Flags: none
void movToMem(State8080* state, uint8_t* reg);

//Flags: none
void mvi(State8080* state, uint8_t* reg, uint8_t imm);

//Flags: none
void lxi(State8080* state, uint8_t* rph, uint8_t* rpl, uint8_t dh, uint8_t dl);

//Flags: none
void ldax(State8080* state, uint8_t* rph, uint8_t* rpl);

//Flags: none
void stax(State8080* state, uint8_t* rph, uint8_t* rpl);

/* ARITHMETIC */

//Flags: Z, S, P, CY, AC
void addReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, CY, AC
void adcReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, AC
void inrReg(State8080* state, uint8_t* reg);

//Flags: None
void inx(uint8_t* rph, uint8_t* rpl);

//Flags: Z, S, P, CY, AC
void subReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, CY, AC
void sbbReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, AC
void dcrReg(State8080* state, uint8_t* reg);

//Flags: None
void dcx(uint8_t* rph, uint8_t* rpl);

//Flags: CY
void dad(State8080* state, uint8_t* rph, uint8_t* rpl);

//Flags: Z, S, P, CY, AC
void daa();

/* LOGICAL */

//Flags: Z, S, P, CY, AC (CY is cleared)
void anaReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, CY, AC (CY and AC are cleared)
void xraReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, CY, AC (CY and AC are cleared)
void oraReg(State8080* state, uint8_t* reg);

//Flags: Z, S, P, CY, AC
// z = 1 if (A) = (r)
// cy = 1 if (A) < (r)
void cmpReg(State8080* state, uint8_t* reg);

//Flags: CY
// void rlc();

//Flags: CY
// void rrc();

//Flags: CY
// void ral();

//Flags: CY
// void rar();

/* BRANCH */

/* STACK, I/O, MACHINE CONTROL */

void push(State8080* state, uint8_t* rph, uint8_t* rpl);
void pop(State8080* state, uint8_t* rph, uint8_t* rpl);

/*
void ei();
void di();
void hlt();
void nop();
*/

/* CONDITIONAL CODES */

/*

Condition                   CCC
NZ  -> not zero (Z = 0)     (000)     
Z   -> zero (Z = 1)         (001)
NC  -> no carry (CY = 0)    (010)
C   -> carry (CY = 1)       (011)
PO  -> parity odd (P = 0)   (100)
PE  -> parity even (P =1)   (101)
P   -> plus (S = 0)         (110)
M   -> minus (S = 1)        (111)

*/

void UpdateAllFlags(State8080* state, uint16_t ans);
int CheckParity(int check, int size);

void PrintProcState(State8080* state);
#endif // __INSTRUCTIONS_H