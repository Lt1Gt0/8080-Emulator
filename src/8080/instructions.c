#include "instuctions.h"

/* DATA TRANSFER */

void movReg(uint8_t* dst, uint8_t* src)
{
    dst = src;
}

void movFromMem(State8080* state, uint8_t* reg)
{
    uint16_t offset = (state->h << 8) | (state->l);
    reg = state->memory[offset];
}

void movToMem(State8080* state, uint8_t* reg)
{
    uint16_t offset = (state->h << 8) | (state->l);
    state->memory[offset] = reg;
}

// 2-byte opcode so increment pc by 1
void mvi(State8080* state, uint8_t* reg, uint8_t* imm)
{
    reg = imm;
    state->pc += 1;
}

// 3-byte opcode so increment pc by 2
void lxi(State8080* state, uint8_t* rph, uint8_t* rpl, uint8_t dh, uint8_t dl)
{
    rph = dh;
    rpl = dl; 
    state->pc += 2;
}

void ldax(State8080* state, uint8_t* rph, uint8_t* rpl)
{
    uint16_t offset = (*rph << 8) | (*rpl);
    state->a = state->memory[offset];   
}

void stax(State8080* state, uint8_t* rph, uint8_t* rpl)
{
    uint16_t offset = (*rph << 8) | (*rpl);
    state->memory[offset] = state->a;
}

/* ARITHMETIC */
void add(State8080* state, uint8_t* reg)
{
    
}

/* LOGICAL */

/* BRANCH */

/* STACK, I/O, MACHINE CONTROL */

/* CONDITIONAL CODES */
