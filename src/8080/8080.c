#include "8080.h"

State8080* Init8080()
{
    State8080* state = calloc(1, sizeof(State8080));
    state->memory = malloc(0x10000); // Allocate 16k worth of memory
    return state;
}

int Emulate8080p(State8080* state)
{
    DecodeInstruction(state->memory, state->pc);
    unsigned char* opcode = &state->memory[state->pc];
    uint16_t ans, offset;
    uint8_t psw, tmp;
    
    state->pc += 1;
    switch (*opcode) {
    case 0x00: // NOP
        break;
    case 0x01: // LXI B, D16
        lxi(state, &state->c, &state->b, opcode[1], opcode[2]);
        break;
    case 0x02: //STAX B
        stax(state, &state->b, &state->c);
        break;
    case 0x03: // INX B
        state->c++;
        if (state->c == 0)
            state->b++;
        // inx(&state->b, &state->c);
        break;
    case 0x04: // INR B
        inrReg(state, &state->b);
        break;
    case 0x05: // DCR B
        dcrReg(state, &state->b);
        break;
    case 0x06: // MVI B, D8
        mvi(state, &state->b, opcode[1]);
        break;
    case 0x07: // RLC
        UndefinedInstruction(state);
        break;
    case 0x08: // NOP
        break;
    case 0x09: // DAD B
        dad(state, &state->b, &state->c);
        break;
    case 0x0A: // LDAX B
        ldax(state, &state->b, &state->c);
        break;
    case 0x0B: // DCX B
        dcx(&state->b, &state->c);
        break;
    case 0x0C: // INR C
        inrReg(state, &state->c);
        break;
    case 0x0D: // DCR C
        dcrReg(state, &state->b);
        break;
    case 0x0E: // MVI C, D8
        mvi(state, &state->c, opcode[1]);
        break;
    case 0x0F: // RRC
        tmp = state->a;
        state->a = ((tmp & 1) << 7) | (tmp >> 1);
        state->cc.cy = ((tmp & 1) == 1);
        break;
    case 0x10: // NOP
        break;
    case 0x11: // LXI D, D16
        lxi(state, &state->e, &state->d, opcode[1], opcode[2]);
        break;
    case 0x12: // STAX D
        stax(state, &state->d, &state->e);
        break;
    case 0x13: // INX D
        state->e++;
        if (state->e == 0)
            state->d++;
        // inx(&state->d, &state->e);
        break;
    case 0x14: // INR D
        inrReg(state, &state->d);
        break;
    case 0x15: // DCR D
        dcrReg(state, &state->b);
        break;
    case 0x16: // MVI D, D8
        mvi(state, &state->d, opcode[1]);
        break;
    case 0x17: // RAL
        UndefinedInstruction(state);
        break;
    case 0x18: // NOP
        break;
    case 0x19: // DAD D
        dad(state, &state->b, &state->c);
        break;
    case 0x1A: // LDAX D
        ldax(state, &state->d, &state->e);
        break;
    case 0x1B: // DCX D
        dcx(&state->d, &state->e);
        break;
    case 0x1C: // INR E
        inrReg(state, &state->e);
        break;
    case 0x1D: // DCR E
        dcrReg(state, &state->b);
        break;
    case 0x1E: // MVI E, D8
        mvi(state, &state->e, opcode[1]);
        break;
    case 0x1F: // RAR
        tmp = state->a;
        state->a = (state->cc.cy << 7) | (tmp >> 1);
        state->cc.cy = ((tmp & 1) == 1);
        break;
    case 0x20: // NOP
        break;
    case 0x21: // LXI H, D16
        lxi(state, &state->l, &state->h, opcode[1], opcode[2]);
        break;
    case 0x22: // SHLD adr
        offset = (opcode[2] << 8) | (opcode[1]);
        state->memory[offset] = state->l;
        state->memory[offset + 1] = state->l;
        state->pc += 2;
        break;
    case 0x23: // INX H
        state->l++;
        if (state->l == 0)
            state->h++;
        // inx(&state->h, &state->l);
        break;
    case 0x24: // INR H
        inrReg(state, &state->h);
        break;
    case 0x25: // DCR H
        dcrReg(state, &state->b);
        break;
    case 0x26: // MVI H, D8
        mvi(state, &state->h, opcode[1]);
        break;
    case 0x27: // DAA
        UndefinedInstruction(state);
        break;
    case 0x28: // NOP
        break;
    case 0x29: // DAD H
        dad(state, &state->b, &state->c);
        break;
    case 0x2A: // LHLD adr
        offset = (opcode[2] << 8) | (opcode[1]);
        state->l = state->memory[offset];
        state->h = state->memory[offset + 1];
        state->pc += 2;
        break;
    case 0x2B: // DCX H
        dcx(&state->h, &state->l);
        break;
    case 0x2C: // INR L
        inrReg(state, &state->l);
        break;
    case 0x2D: // DCR L
        dcrReg(state, &state->b);
        break;
    case 0x2E: // MVI L, D8
        mvi(state, &state->l, opcode[1]);
        break;
    case 0x2F: // CMA
        state->a = ~(state->a); //I think this is right;
        break;
    case 0x30: // NOP
        break;
    case 0x31: // LXI SP, D16
        state->sp = (opcode[2] << 8) | (opcode[1]);
        state->pc += 2;
        break;
    case 0x32: // STA adr
        offset = (opcode[2] << 8) | (opcode[1]);
        state->memory[offset] = state->a;
        break;
    case 0x33: // INX SP
        state->sp += 1; // Double check to make sure it is correct
        break;
    case 0x34: // INR M
        // Flags: Z, S, P, AC
        ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)1;
        tmp = state->cc.cy;
        UpdateAllFlags(state, ans);
        state->cc.cy = tmp; // retore cy
        state->h = (ans >> 8) & 0xFF;
        state->l = ans & 0xFF;
        break;
    case 0x35: // DCR M
        // Flags: Z, S, P, AC
        // Not sure if any of this is correct
        offset = ((uint16_t)(state->h << 8) | (state->l));
        ans = state->memory[offset] - 1;
        tmp = state->cc.cy;
        UpdateAllFlags(state, ans);
        state->cc.cy = tmp; // retore cy
        state->h = (ans >> 8) & 0xFF;
        state->l = ans & 0xFF;
        break;
    case 0x36: // MVI M, D8
        offset = (state->h << 8) | (state->l);
        state->memory[offset] = opcode[1];
        state->pc += 1;
        break;
    case 0x37: // STC
        state->cc.cy = 1;
        break;
    case 0x38: // NOP
        break;
    case 0x39: // DAD SP
        UndefinedInstruction(state);
        break;
    case 0x3A: // LDA adr
        offset = (opcode[2] << 8) | (opcode[1]);
        state->a = state->memory[offset];
        state->pc += 2;
        break;
    case 0x3B: // DCX SP
        state->sp = state->sp - 1;
        break;
    case 0x3C: // INR A
        inrReg(state, &state->a);
        break;
    case 0x3D: // DCR A
        dcrReg(state, &state->b);
        break;
    case 0x3E: // MVI A, D8
        mvi(state, &state->a, opcode[1]);
        break;
    case 0x3F: // CMC
        state->cc.cy = ~(state->cc.cy);
        break;
    case 0x40: // MOV B, B
        // Set register to itself so just break
        break;
    case 0x41: // MOV B, C
        movReg(&state->b, &state->c);
        break;
    case 0x42: // MOV B, D
        movReg(&state->b, &state->d);
        break;
    case 0x43: // MOV B, E
        movReg(&state->b, &state->e);
        break;
    case 0x44: // MOV B, H
        movReg(&state->b, &state->h);
        break;
    case 0x45: // MOV B, L
        movReg(&state->b, &state->l);
        break;
    case 0x46: // MOV B, M
        movFromMem(state, &state->b);
        break;
    case 0x47: // MOV B, A
        movReg(&state->b, &state->a);
        break;
    case 0x48: // MOV C, B
        movReg(&state->c, &state->b);
        break;
    case 0x49: // MOV C, C
        // Set register to itself so just break
        break;
    case 0x4A: // MOV C, D
        movReg(&state->c, &state->d);
        break;
    case 0x4B: // MOV C, E
        movReg(&state->c, &state->e);
        break;
    case 0x4C: // MOV C, H
        movReg(&state->c, &state->h);
        break;
    case 0x4D: // MOV C, L
        movReg(&state->c, &state->l);
        break;
    case 0x4E: // MOV C, M
        movFromMem(state, &state->c);
        break;
    case 0x4F: // MOV C, A
        movReg(&state->c, &state->a);
        break;
    case 0x50: // MOV D, B
        movReg(&state->d, &state->b);
        break;
    case 0x51: // MOV D, C
        movReg(&state->d, &state->c);
        break;
    case 0x52: // MOV D, D
        // Set register to itself so just break
        break;
    case 0x53: // MOV D, E
        movReg(&state->d, &state->e);
        break;
    case 0x54: // MOV D, H
        movReg(&state->d, &state->h);
        break;
    case 0x55: // MOV D, L
        movReg(&state->d, &state->l);
        break;
    case 0x56: // MOV D, M
        movFromMem(state, &state->d);
        break;
    case 0x57: // MOV D, A
        movReg(&state->d, &state->a);
        break;
    case 0x58: // MOV E, B
        movReg(&state->e, &state->b);
        break;
    case 0x59: // MOV E, C
        movReg(&state->e, &state->c);
        break;
    case 0x5A: // MOV E, D
        movReg(&state->e, &state->d);
        break;
    case 0x5B: // MOV E, E
        // Set register to itself so just break
        break;
    case 0x5C: // MOV E, H
        movReg(&state->e, &state->h);
        break;
    case 0x5D: // MOV E, L
        movReg(&state->e, &state->l);
        break;
    case 0x5E: // MOV E, M
        movFromMem(state, &state->e);
        break;
    case 0x5F: // MOV E, A
        movReg(&state->e, &state->a);
        break;
    case 0x60: // MOV H, B
        movReg(&state->h, &state->b);
    case 0x61: // MOV H, C 
        movReg(&state->h, &state->c);
        break;
    case 0x62: // MOV H, D
        movReg(&state->h, &state->d);
        break;
    case 0x63: // MOV H, E
        movReg(&state->h, &state->e);
        break;
    case 0x64: // MOV H, H
        // Set register to itself so just break
        break;
    case 0x65: // MOV H, L
        movReg(&state->h, &state->l);
        break;
    case 0x66: // MOV H, M
        movFromMem(state, &state->h);
        break;
    case 0x67: // MOV H, A
        movReg(&state->h, &state->a);
        break;
    case 0x68: // MOV L, B
        movReg(&state->l, &state->b);
        break;
    case 0x69: // MOV L, C
        movReg(&state->l, &state->c);
        break;
    case 0x6A: // MOV L, D
        movReg(&state->l, &state->d);
        break;
    case 0x6B: // MOV L, E
        movReg(&state->l, &state->e);
        break;
    case 0x6C: // MOV L, H
        movReg(&state->l, &state->h);
        break;
    case 0x6D: // MOV L, L
        // Set register to itself so just break
        break;
    case 0x6E: // MOV L, M
        movFromMem(state, &state->l);
        break;
    case 0x6F: // MOV L, A
        movReg(&state->l, &state->a);
        break;
    case 0x70: // MOV M, B
        movToMem(state, &state->b);
        break;
    case 0x71: // MOV M, C
        movToMem(state, &state->c);
        break;
    case 0x72: // MOV M, D
        movToMem(state, &state->d);
        break;
    case 0x73: // MOV M, E
        movToMem(state, &state->e);
        break;
    case 0x74: // MOV M, H
        movToMem(state, &state->h);
        break;
    case 0x75: // MOV M, L
        movToMem(state, &state->l);
        break;
    case 0x76: // HLT
        break;
    case 0x77: // MOV M, A
        movToMem(state, &state->a);
        break;
    case 0x78: // MOV A, B
        movReg(&state->a, &state->b);
        break;
    case 0x79: // MOV A, C
        movReg(&state->a, &state->c);
        break;
    case 0x7A: // MOV A, D
        movReg(&state->a, &state->d);
        break;
    case 0x7B: // MOV A, E
        movReg(&state->a, &state->e);
        break;
    case 0x7C: // MOV A, H
        movReg(&state->a, &state->h);
        break;
    case 0x7D: // MOV A, L
        movReg(&state->a, &state->l);
        break;
    case 0x7E: // MOV A, M
        offset = (state->h << 8) | (state->l);
        state->a = state->memory[offset];
        break;
    case 0x7F: // MOV A, A
        // Set register to itself so just break
        break;
    case 0x80: // ADD B
        addReg(state, &state->b);
        break;
    case 0x81: // ADD C 
        addReg(state, &state->c);
        break;
    case 0x82: // ADD D
        addReg(state, &state->d);
        break;
    case 0x83: // ADD E
        addReg(state, &state->e);
        break;
    case 0x84: // ADD H
        addReg(state, &state->h);
        break;
    case 0x85: // ADD L
        addReg(state, &state->l);
        break;
    case 0x86: // ADD M
        offset = (uint16_t)((state->h << 8) | (state->l));
        ans = (uint16_t) state->a + state->memory[offset];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0x87: // ADD A
        addReg(state, &state->a);
        break;
    case 0x88: // adcReg B
        adcReg(state, &state->b);
        break;
    case 0x89: // adcReg C
        adcReg(state, &state->c);
        break;
    case 0x8A: // adcReg D
        adcReg(state, &state->d);
        break;
    case 0x8B: // adcReg E
        adcReg(state, &state->e);
        break;
    case 0x8C: // adcReg H
        adcReg(state, &state->h);
        break;
    case 0x8D: // adcReg L
        adcReg(state, &state->l);
        break;
    case 0x8E: // adcReg M
        offset = (uint16_t)((state->h << 8) | (state->l));
        ans = (uint16_t) state->a + state->memory[offset];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0x8F: // adcReg A
        adcReg(state, &state->a);
        break;
    case 0x90: // SUB B
        subReg(state, &state->b);
        break;
    case 0x91: // SUB C
        subReg(state, &state->c);
        break;
    case 0x92: // SUB D
        subReg(state, &state->d);
        break;
    case 0x93: // SUB E
        subReg(state, &state->e);
        break;
    case 0x94: // SUB H
        subReg(state, &state->h);
        break;
    case 0x95: // SUB L
        subReg(state, &state->l);
        break;
    case 0x96: // SUB M
        ans = (uint16_t) state->a - ((uint16_t)(state->h << 8) | (state->l));
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0x97: // SUB A
        subReg(state, &state->a);
        break;
    case 0x98: // SBB B
        sbbReg(state, &state->b);
        break;
    case 0x99: // SBB C
        sbbReg(state, &state->c);
        break;
    case 0x9A: // SBB D
        sbbReg(state, &state->d);
        break;
    case 0x9B: // SBB E
        sbbReg(state, &state->e);
        break;
    case 0x9C: // SBB H
        sbbReg(state, &state->h);
        break;
    case 0x9D: // SBB L
        sbbReg(state, &state->l);
        break;
    case 0x9E: // SBB M
        ans = (uint16_t) state->a - ((uint16_t)(state->h << 8) | (state->l)) - (uint16_t) state->cc.cy;
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0x9F: // SBB A
        sbbReg(state, &state->a);
        break;
    case 0xA0: // ANA B
        anaReg(state, &state->b);
        break;
    case 0xA1: // ANA C
        anaReg(state, &state->c);
        break;
    case 0xA2: // ANA D
        anaReg(state, &state->d);
        break;
    case 0xA3: // ANA E
        anaReg(state, &state->e);
        break;
    case 0xA4: // ANA H
        anaReg(state, &state->h);
        break;
    case 0xA5: // ANA L
        anaReg(state, &state->l);
        break;
    case 0xA6: // ANA M
        offset = (uint16_t)((state->h << 8) | (state->l));
        ans = (uint16_t) state->a & state->memory[offset];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xA7: // ANA A
        anaReg(state, &state->a);
        break;
    case 0xA8: // XRA B
        xraReg(state, &state->b);
        break;
    case 0xA9: // XRA C
        xraReg(state, &state->c);
        break;
    case 0xAA: // XRA D
        xraReg(state, &state->d);
        break;
    case 0xAB: // XRA E
        xraReg(state, &state->e);
        break;
    case 0xAC: // XRA H
        xraReg(state, &state->h);
        break;
    case 0xAD: // XRA L
        xraReg(state, &state->l);
        break;
    case 0xAE: // XRA M
        offset = (uint16_t)((state->h << 8) | (state->l));
        ans = (uint16_t) state->a | state->memory[offset];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xAF: // XRA A
        xraReg(state, &state->a);
        break;
    case 0xB0: // ORA B
        oraReg(state, &state->b);
        break;
    case 0xB1: // ORA C
        oraReg(state, &state->c);
        break;
    case 0xB2: // ORA D
        oraReg(state, &state->c);
        break;
    case 0xB3: // ORA E
        oraReg(state, &state->e);
        break;
    case 0xB4: // ORA H
        oraReg(state, &state->h);
        break;
    case 0xB5: // ORA L
        oraReg(state, &state->l);
        break;
    case 0xB6: // ORA M
        offset = (uint16_t)((state->h << 8) | (state->l));
        ans = (uint16_t) state->a | state->memory[offset];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xB7: // ORA A
        oraReg(state, &state->a);
        break;
    case 0xB8: // CMP B
        cmpReg(state, &state->b);
        break;
    case 0xB9: // CMP C
        cmpReg(state, &state->c);
        break;
    case 0xBA: // CMP D
        cmpReg(state, &state->d);
        break;
    case 0xBB: // CMP E
        cmpReg(state, &state->e);
        break;
    case 0xBC: // CMP H
        cmpReg(state, &state->h);
        break;
    case 0xBD: // CMP L
        cmpReg(state, &state->l);
        break;
    case 0xBE: // CMP M
        offset = (uint16_t)(state->h << 8) | (state->l);
        ans = (uint16_t) state->a - (uint16_t) state->memory[offset];
        UpdateAllFlags(state, ans);
        break;
    case 0xBF: // CMP A
        cmpReg(state, &state->a);
        break;
    case 0xC0: // RNZ
        UndefinedInstruction(state);
        break;
    case 0xC1: // POP B
        pop(state, &state->b, &state->c);
        break;
    case 0xC2: // JNZ adr 
        if (state->cc.z == 0) 
            state->pc = (opcode[2] << 8) | (opcode[1]);
        else 
            state->pc += 2;
        break;
    case 0xC3: // JMP adr
        jmp(state, ((opcode[2] << 8) | (opcode[1])));
        break;
    case 0xC4: // CNZ adr
        UndefinedInstruction(state);
        break;
    case 0xC5: // PUSH B
        push(state, &state->b, &state->c);
        break;
    case 0xC6: // ADI D8
        ans = (uint16_t) state->a + (uint16_t) opcode[1];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;        
        break;
    case 0xC7: // RST 0
        call(state, 0, 0);
        break;
    case 0xC8: // RZ
        UndefinedInstruction(state);
        break;
    case 0xC9: // RET
        state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
        state->pc += 2;
        break;
    case 0xCA: // JZ adr
        if (state->cc.z == 0) {
            jmp(state, ((opcode[2] << 8) | (opcode[1])));
        }
        break;
    case 0xCB: // NOP
        break;
    case 0xCC: // CZ adr
        UndefinedInstruction(state);
        break;
    case 0xCD: // CALL adr
        call(state, opcode[2], opcode[1]); 
        break;
    case 0xCE: // ACI D8
        ans = (uint16_t) state->a + (uint16_t) opcode[1] + (uint16_t) state->cc.cy;
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;        
        break;
    case 0xCF: // RST 1
        call(state, 0 , 0x08);
        break;
    case 0xD0: // RNC
        if (state->cc.cy == 0) {
            jmp(state, ((opcode[2] << 8) | (opcode[1])));
        }
        break;
    case 0xD1: // POP D
        pop(state, &state->d, &state->e);
        break;
    case 0xD2: // JNC adr
        UndefinedInstruction(state);
        break;
    case 0xD3: // OUT D8
        UndefinedInstruction(state);
        break;
    case 0xD4: // CNC adr
        UndefinedInstruction(state);
        break;
    case 0xD5: // PUSH D
        push(state, &state->d, &state->e);
        break;
    case 0xD6: // SUI D8
        ans = (uint16_t) state->a - (uint16_t) opcode[1]; // Make sure this is correct 
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xD7: // RST 2
        call(state, 0, 0x10);
        break;
    case 0xD8: // RC
        UndefinedInstruction(state);
        break;
    case 0xD9: // NOP
        break;
    case 0xDA: // JC adr
        UndefinedInstruction(state);
        break;
    case 0xDB: // IN D8
        UndefinedInstruction(state);
        break;
    case 0xDC: // CC adr
        UndefinedInstruction(state);
        break;
    case 0xDD: // NOP
        break;
    case 0xDE: // SBI D8 
        ans = (uint16_t) state->a - (uint16_t) opcode[1] - (uint16_t) state->cc.cy;
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xDF: // RST 3
        call(state, 0, 0x18);
        break;
    case 0xE0: // RPO
        UndefinedInstruction(state);
        break;
    case 0xE1: // POP H
        pop(state, &state->h, &state->l);
        break;
    case 0xE2: // JPO adr
        UndefinedInstruction(state);
        break;
    case 0xE3: // XTHL
        UndefinedInstruction(state);
        break;
    case 0xE4: // CPO adr
        UndefinedInstruction(state);
        break;
    case 0xE5: // PUSH H
        push(state, &state->h, &state->l);
        break;
    case 0xE6: // ANI D8
        ans = state->a & opcode[1];
        UpdateAllFlags(state, (uint16_t)ans);
        state->cc.p = CheckParity(ans, 8);
        state->cc.cy = 0;
        state->a = ans;
        break;
    case 0xE7: // RST 4
        call(state, 0, 0x20);
        break;
    case 0xE8: // RPE
        UndefinedInstruction(state);
        break;
    case 0xE9: // PCHL
        state->pc = (uint16_t)((state->h << 8) | (state->l)); // Not sure if this is right
        break;
    case 0xEA: // JPE adr
        UndefinedInstruction(state);
        break;
    case 0xEB: // XCHG
        tmp = state->h;
        state->h = state->d;
        state->d = tmp;

        tmp = state->l;
        state->l = state->e;
        state->e = tmp;
        break;
    case 0xEC: // CPE adr
        UndefinedInstruction(state);
        break;
    case 0xED: // NOP
        break;
    case 0xEE: // XRI D8
        ans = (uint16_t) state->a ^ (uint16_t) opcode[1];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xEF: // RST 5
        call(state, 0, 0x28);
        break;
    case 0xF0: // RP
        UndefinedInstruction(state);
        break;
    case 0xF1: // POP PSW
        state->a = state->memory[state->sp + 1];
        psw = state->memory[state->sp];
        state->cc.z = ((psw & 0x01) == 0x01);
        state->cc.s = ((psw & 0x02) == 0x02);
        state->cc.p = ((psw & 0x04) == 0x04);
        state->cc.cy = ((psw & 0x05) == 0x05);
        state->cc.ac = ((psw & 0x10) == 0x10);
        state->sp += 2;
        break;
    case 0xF2: // JP adr
        UndefinedInstruction(state);
        break;
    case 0xF3: // DI
        di(state);
        break;
    case 0xF4: // CP adr
        UndefinedInstruction(state);
        break;
    case 0xF5: // PUSH PSW
        state->memory[state->sp - 1] = state->a;
        psw=(state->cc.z
            |state->cc.s << 1
            |state->cc.p << 2
            |state->cc.cy << 3
            |state->cc.ac << 4);
        state->memory[state->sp - 2] = psw;
        state->sp -= 2;
        break;
    case 0xF6: // ORI D8
        ans = (uint16_t) state->a | (uint16_t) opcode[1];
        UpdateAllFlags(state, ans);
        state->a = ans & 0xFF;
        break;
    case 0xF7: // RST 6
        call(state, 0, 0x30);
        break;
    case 0xF8: // RM
        UndefinedInstruction(state);
        break;
    case 0xF9: // SPHL
        state->sp = (uint16_t)((state->h << 8) | (state->l));
        break;
    case 0xFA: // JM adr
        UndefinedInstruction(state);
        break;
    case 0xFB: // EI
        ei(state);
        break;
    case 0xFC: // CM adr
        UndefinedInstruction(state);
        break;
    case 0xFD: // NOP
        break;
    case 0xFE: // CPI D8
        tmp = state->a - opcode[1];
        UpdateAllFlags(state, ans);
        state->cc.p = CheckParity(tmp, 8);
        state->cc.cy = (state->a < opcode[1]);
        state->pc += 1;
        break;
    case 0xFF: // RST 7
        call(state, 0, 0x38);
        break;
    default:
        UndefinedInstruction(state);
        break;
    }

    PrintProcState(state);
    return 0;
}