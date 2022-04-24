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

//Flags: Z, S, P, CY, AC
void addReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a + (uint16_t) reg;
    UpdateAllFlags(state, ans);
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, CY, AC
void adcReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a + (uint16_t) reg + (uint16_t) state->cc.cy;
    UpdateAllFlags(state, ans);
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, AC
void inrReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) reg + 1;
    uint8_t tmp = state->cc.cy;
    UpdateAllFlags(state, ans);
    reg = ans & 0xFF;

    //restore CY
    state->cc.cy = tmp;
}

//Flags: None
void inx(State8080* state, uint8_t* rph, uint8_t* rpl)
{

}

//Flags: Z, S, P, CY, AC
void subReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a - (uint16_t) reg;
    UpdateAllFlags(state, ans);
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, CY, AC
void sbbReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a - (uint16_t) reg - (uint16_t) state->cc.cy;
    UpdateAllFlags(state, ans);
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, AC
void dcrReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) reg - 1;
    UpdateAllFlags(state, ans);
    reg = ans & 0xFF;
}

//Flags: None
void dcx(State8080* state, uint8_t* rph, uint8_t* rpl)
{
    uint16_t ans = (uint16_t)(((uint16_t)rph << 8) | ((uint8_t)rpl)) - 1;
    rph = ans >> 8;
    rpl = ans & 0xFF;
}

//Flags: CY
void dad(State8080* state, uint8_t* rph, uint8_t* rpl)
{
    uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)(((uint8_t)rph << 8) | (uint8_t)rpl);
    state->h = ans >> 8;
    state->l = ans & 0xFF;
    state->cc.cy = (ans & 0xFF);
}

//Flags: Z, S, P, CY, AC
void daa()
{

}

/* LOGICAL */

//Flags: Z, S, P, CY, AC (CY is cleared)
void anaReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a & (uint16_t) reg;
    UpdateAllFlags(state, ans);
    state->cc.cy = 0;
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, CY, AC (CY and AC are cleared)
void xraReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a ^ (uint16_t) reg;
    UpdateAllFlags(state, ans);
    state->cc.cy = 0;
    state->cc.ac = 0;
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, CY, AC (CY and AC are cleared)
void oraReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a | (uint16_t) reg;
    UpdateAllFlags(state, ans);
    state->cc.cy = 0;
    state->cc.ac = 0;
    state->a = ans & 0xFF;
}

//Flags: Z, S, P, CY, AC
// z = 1 if (A) = (r)
// cy = 1 if (A) < (r)
void cmpReg(State8080* state, uint8_t* reg)
{
    uint16_t ans = (uint16_t) state->a - (uint16_t) reg;
    UpdateAllFlags(state, ans);
}

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

void push(State8080* state, uint8_t* rph, uint8_t* rpl)
{

}

void pop(State8080* state, uint8_t* rph, uint8_t* rpl)
{

}

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

void UpdateAllFlags(State8080* state, uint16_t ans)
{
    state->cc.z = ((ans & 0xFF) == 0);
    state->cc.s = ((ans & MSB_UINT8) != 0);
    state->cc.cy = (ans > 0xFF);

    // state->cc.p
    // state->cc.ac
}