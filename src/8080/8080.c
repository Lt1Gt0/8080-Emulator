#include "8080.h"

State8080* Init8080()
{
    State8080* state = calloc(1, sizeof(State8080));
    state->memory = malloc(0x10000); // Allocate 16k worth of memory
    return state;
}

void UndefinedInstuction(State8080* state)
{
    printf("UNDEFINED OPCODE!\n");
    exit(1);
}

int Emulate8080p(State8080* state)
{
    unsigned char* opcode = &state->memory[state->pc];

    switch (*opcode) {
    case 0x00: // NOP
        break;
    case 0x01: // LXI B, D16
        state->c = opcode[1];
        state->b = opcode[2];
        state->pc += 2;
        break;
    case 0x02: //STAX B
        UndefinedInstuction(state);
        break;
    case 0x03: // INX B
        UndefinedInstuction(state);
        break;
    case 0x04: // INR B
        UndefinedInstuction(state);
        break;
    case 0x05: // DCR B
        UndefinedInstuction(state);
        break;
    case 0x06: // MVI B, D8
        state->b = opcode[1];
        state->pc += 1;
        break;
    case 0x07: // RLC
        UndefinedInstuction(state);
        break;
    case 0x08: // NOP
        break;
    case 0x09: // DAD B
        UndefinedInstuction(state);
        break;
    case 0x0A: // LDAX B
        UndefinedInstuction(state);
        break;
    case 0x0B: // DCX B
        UndefinedInstuction(state);
        break;
    case 0x0C: // INR C
        UndefinedInstuction(state);
        break;
    case 0x0D: // DCR C
        UndefinedInstuction(state);
        break;
    case 0x0E: // MVI C, D8
        state->c = opcode[1];
        state->pc += 1;
        break;
    case 0x0F: // RRC
        UndefinedInstuction(state);
        break;
    case 0x10: // NOP
        break;
    case 0x11: // LXI D, D16
        state->e = opcode[1];
        state->d = opcode[2];
        state->pc += 2;
        break;
    case 0x12: // STAX D
        UndefinedInstuction(state);
        break;
    case 0x13: // INX D
        UndefinedInstuction(state);
        break;
    case 0x14: // INR D
        UndefinedInstuction(state);
        break;
    case 0x15: // DCR D
        UndefinedInstuction(state);
        break;
    case 0x16: // MVI D, D8
        state->d = opcode[1];
        state->pc += 1;
        break;
    case 0x17: // RAL
        UndefinedInstuction(state);
        break;
    case 0x18: // NOP
        break;
    case 0x19: // DAD D
        UndefinedInstuction(state);
        break;
    case 0x1A: // LDAX D
        UndefinedInstuction(state);
        break;
    case 0x1B: // DCX D
        UndefinedInstuction(state);
        break;
    case 0x1C: // INR E
        UndefinedInstuction(state);
        break;
    case 0x1D: // DCR E
        UndefinedInstuction(state);
        break;
    case 0x1E: // MVI E, D8
        state->e = opcode[1];
        state->pc += 1;
        break;
    case 0x1F: // RAR
        UndefinedInstuction(state);
        break;
    case 0x20: // NOP
        break;
    case 0x21: // LXI H, D16
        state->l = opcode[1];
        state->h = opcode[2];
        state->pc += 2;
        break;
    case 0x22: // SHDL adr
        UndefinedInstuction(state);
        break;
    case 0x23: // INX H
        UndefinedInstuction(state);
        break;
    case 0x24: // INR H
        UndefinedInstuction(state);
        break;
    case 0x25: // DCR H
        UndefinedInstuction(state);
        break;
    case 0x26: // MVI H, D8
        state->h = opcode[1];
        state->pc += 1;
        break;
    case 0x27: // DAA
        UndefinedInstuction(state);
        break;
    case 0x28: // NOP
        break;
    case 0x29: // DAD H
        UndefinedInstuction(state);
        break;
    case 0x2A: // LHLD adr
        UndefinedInstuction(state);
        break;
    case 0x2B: // DCX H
        UndefinedInstuction(state);
        break;
    case 0x2C: // INR L
        UndefinedInstuction(state);
        break;
    case 0x2D: // DCR L
        UndefinedInstuction(state);
        break;
    case 0x2E: // MVI L, D8
        state->l = opcode[1];
        state->pc += 1;
        break;
    case 0x2F: // CMA
        UndefinedInstuction(state);
        break;
    case 0x30: // NOP
        break;
    case 0x31: // LXI SP, D16
        UndefinedInstuction(state);
        break;
    case 0x32: // STA adr
        UndefinedInstuction(state);
        break;
    case 0x33: // INX SP
        UndefinedInstuction(state);
        break;
    case 0x34: // INR M
        UndefinedInstuction(state);
        break;
    case 0x35: // DCR M
        UndefinedInstuction(state);
        break;
    case 0x36: // MVI M, D8
        UndefinedInstuction(state);
        break;
    case 0x37: // STC
        UndefinedInstuction(state);
        break;
    case 0x38: // NOP
        break;
    case 0x39: // DAD SP
        UndefinedInstuction(state);
        break;
    case 0x3A: // LDA adr
        UndefinedInstuction(state);
        break;
    case 0x3B: // DCX SP
        UndefinedInstuction(state);
        break;
    case 0x3C: // INR A
        UndefinedInstuction(state);
        break;
    case 0x3D: // DCR A
        UndefinedInstuction(state);
        break;
    case 0x3E: // MVI A, D8
        state->a = opcode[1];
        state->pc += 1;
        break;
    case 0x3F: // CMC
        UndefinedInstuction(state);
        break;
    case 0x40: // MOV B, B
        // Set register to itself so just break
        break;
    case 0x41: // MOV B, C
        state->b = state->c;
        break;
    case 0x42: // MOV B, D
        state->b = state->d;
        break;
    case 0x43: // MOV B, E
        state->b = state->e;
        break;
    case 0x44: // MOV B, H
        state->b = state->h;
        break;
    case 0x45: // MOV B, L
        state->b = state->l;
        break;
    case 0x46: // MOV B, M
        UndefinedInstuction(state);
        break;
    case 0x47: // MOV B, A
        state->b = state->a;
        break;
    case 0x48: // MOV C, B
        state->c = state->b;
        break;
    case 0x49: // MOV C, C
        // Set register to itself so just break
        break;
    case 0x4A: // MOV C, D
        state->c = state->d;
        break;
    case 0x4B: // MOV C, E
        state->c = state->e;
        break;
    case 0x4C: // MOV C, H
        state->c = state->h;
        break;
    case 0x4D: // MOV C, L
        state->c = state->l;
        break;
    case 0x4E: // MOV C, M
        UndefinedInstuction(state);
        break;
    case 0x4F: // MOV C, A
        state->c = state->a;
        break;
    case 0x50: // MOV D, B
        state->d = state->b;
        break;
    case 0x51: // MOV D, C
        state->d = state->c;
        break;
    case 0x52: // MOV D, D
        // Set register to itself so just break
        break;
    case 0x53: // MOV D, E
        state->d = state->e;
        break;
    case 0x54: // MOV D, H
        state->d = state->h;
        break;
    case 0x55: // MOV D, L
        state->d = state->l;
        break;
    case 0x56: // MOV D, M
        UndefinedInstuction(state);
        break;
    case 0x57: // MOV D, A
        state->d = state->a;
        break;
    case 0x58: // MOV E, B
        state->e = state->b;
        break;
    case 0x59: // MOV E, C
        state->e = state->c;
        break;
    case 0x5A: // MOV E, D
        state->e = state->d;
        break;
    case 0x5B: // MOV E, E
        // Set register to itself so just break
        break;
    case 0x5C: // MOV E, H
        state->e = state->h;
        break;
    case 0x5D: // MOV E, L
        state->e = state->l;
        break;
    case 0x5E: // MOV E, M
        UndefinedInstuction(state);
        break;
    case 0x5F: // MOV E, A
        state->e = state->a;
        break;
    case 0x60: // MOV H, B
        state->h = state->b;
        break;
    case 0x61: // MOV H, C 
        state->h = state->c;
        break;
    case 0x62: // MOV H, D
        state->h = state->d;
        break;
    case 0x63: // MOV H, E
        state->h = state->e;
        break;
    case 0x64: // MOV H, H
        // Set register to itself so just break
        break;
    case 0x65: // MOV H, L
        state->h = state->l;
        break;
    case 0x66: // MOV H, M
        UndefinedInstuction(state);
        break;
    case 0x67: // MOV H, A
        state->h = state->a;
        break;
    case 0x68: // MOV L, B
        state->l = state->b;
        break;
    case 0x69: // MOV L, C
        state->l = state->c;
        break;
    case 0x6A: // MOV L, D
        state->l = state->d;
        break;
    case 0x6B: // MOV L, E
        state->l = state->e;
        break;
    case 0x6C: // MOV L, H
        UndefinedInstuction(state);
        break;
    case 0x6D: // MOV L, L
        // Set register to itself so just break
        break;
    case 0x6E: // MOV L, M
        UndefinedInstuction(state);
        break;
    case 0x6F: // MOV L, A
        state->l = state->a;
        break;
    case 0x70: // MOV M, B
        UndefinedInstuction(state);
        break;
    case 0x71: // MOV M, C
        UndefinedInstuction(state);
        break;
    case 0x72: // MOV M, D
        UndefinedInstuction(state);
        break;
    case 0x73: // MOV M, E
        UndefinedInstuction(state);
        break;
    case 0x74: // MOV M, H
        UndefinedInstuction(state);
        break;
    case 0x75: // MOV M, L
        UndefinedInstuction(state);
        break;
    case 0x76: // HLT
        UndefinedInstuction(state);
        break;
    case 0x77: // MOV M, A
        UndefinedInstuction(state);
        break;
    case 0x78: // MOV A, B
        state->a = state->b;
        break;
    case 0x79: // MOV A, C
        state->a = state->c;
        break;
    case 0x7A: // MOV A, D
        state->a = state->d;
        break;
    case 0x7B: // MOV A, E
        state->a = state->e;
        break;
    case 0x7C: // MOV A, H
        state->a = state->h;
        break;
    case 0x7D: // MOV A, L
        state->a = state->l;
        break;
    case 0x7E: // MOV A, M
        UndefinedInstuction(state);
        break;
    case 0x7F: // MOV A, A
        // Set register to itself so just break
        break;
    case 0x80: // ADD B
        UndefinedInstuction(state);
        break;
    case 0x81: // ADD C
        UndefinedInstuction(state);
        break;
    case 0x82: // ADD D
        UndefinedInstuction(state);
        break;
    case 0x83: // ADD E
        UndefinedInstuction(state);
        break;
    case 0x84: // ADD H
        UndefinedInstuction(state);
        break;
    case 0x85: // ADD L
        UndefinedInstuction(state);
        break;
    case 0x86: // ADD M
        UndefinedInstuction(state);
        break;
    case 0x87: // ADD A
        UndefinedInstuction(state);
        break;
    case 0x88: // ADC B
        UndefinedInstuction(state);
        break;
    case 0x89: // ADC C
        UndefinedInstuction(state);
        break;
    case 0x8A: // ADC D
        UndefinedInstuction(state);
        break;
    case 0x8B: // ADC E
        UndefinedInstuction(state);
        break;
    case 0x8C: // ADC H
        UndefinedInstuction(state);
        break;
    case 0x8D: // ADC L
        UndefinedInstuction(state);
        break;
    case 0x8E: // ADC M
        UndefinedInstuction(state);
        break;
    case 0x8F: // ADC A
        UndefinedInstuction(state);
        break;
    case 0x90: // SUB B
        UndefinedInstuction(state);
        break;
    case 0x91: // SUB C
        UndefinedInstuction(state);
        break;
    case 0x92: // SUB D
        UndefinedInstuction(state);
        break;
    case 0x93: // SUB E
        UndefinedInstuction(state);
        break;
    case 0x94: // SUB H
        UndefinedInstuction(state);
        break;
    case 0x95: // SUB L
        UndefinedInstuction(state);
        break;
    case 0x96: // SUB M
        UndefinedInstuction(state);
        break;
    case 0x97: // SUB A
        UndefinedInstuction(state);
        break;
    case 0x98: // SBB B
        UndefinedInstuction(state);
        break;
    case 0x99: // SBB C
        UndefinedInstuction(state);
        break;
    case 0x9A: // SBB D
        UndefinedInstuction(state);
        break;
    case 0x9B: // SBB E
        UndefinedInstuction(state);
        break;
    case 0x9C: // SBB H
        UndefinedInstuction(state);
        break;
    case 0x9D: // SBB L
        UndefinedInstuction(state);
        break;
    case 0x9E: // SBB M
        UndefinedInstuction(state);
        break;
    case 0x9F: // SBB A
        UndefinedInstuction(state);
        break;
    case 0xA0: // ANA B
        UndefinedInstuction(state);
        break;
    case 0xA1: // ANA C
        UndefinedInstuction(state);
        break;
    case 0xA2: // ANA D
        UndefinedInstuction(state);
        break;
    case 0xA3: // ANA E
        UndefinedInstuction(state);
        break;
    case 0xA4: // ANA H
        UndefinedInstuction(state);
        break;
    case 0xA5: // ANA L
        UndefinedInstuction(state);
        break;
    case 0xA6: // ANA M
        UndefinedInstuction(state);
        break;
    case 0xA7: // ANA A
        UndefinedInstuction(state);
        break;
    case 0xA8: // XRA B
        UndefinedInstuction(state);
        break;
    case 0xA9: // XRA C
        UndefinedInstuction(state);
        break;
    case 0xAA: // XRA D
        UndefinedInstuction(state);
        break;
    case 0xAB: // XRA E
        UndefinedInstuction(state);
        break;
    case 0xAC: // XRA H
        UndefinedInstuction(state);
        break;
    case 0xAD: // XRA L
        UndefinedInstuction(state);
        break;
    case 0xAE: // XRA M
        UndefinedInstuction(state);
        break;
    case 0xAF: // XRA A
        UndefinedInstuction(state);
        break;
    case 0xB0: // ORA B
        UndefinedInstuction(state);
        break;
    case 0xB1: // ORA C
        UndefinedInstuction(state);
        break;
    case 0xB2: // ORA D
        UndefinedInstuction(state);
        break;
    case 0xB3: // ORA E
        UndefinedInstuction(state);
        break;
    case 0xB4: // ORA H
        UndefinedInstuction(state);
        break;
    case 0xB5: // ORA L
        UndefinedInstuction(state);
        break;
    case 0xB6: // ORA M
        UndefinedInstuction(state);
        break;
    case 0xB7: // ORA A
        UndefinedInstuction(state);
        break;
    case 0xB8: // CMP B
        UndefinedInstuction(state);
        break;
    case 0xB9: // CMP C
        UndefinedInstuction(state);
        break;
    case 0xBA: // CMP D
        UndefinedInstuction(state);
        break;
    case 0xBB: // CMP E
        UndefinedInstuction(state);
        break;
    case 0xBC: // CMP H
        UndefinedInstuction(state);
        break;
    case 0xBD: // CMP L
        UndefinedInstuction(state);
        break;
    case 0xBE: // CMP M
        UndefinedInstuction(state);
        break;
    case 0xBF: // CMP A
        UndefinedInstuction(state);
        break;
    case 0xC0: // RNZ
        UndefinedInstuction(state);
        break;
    case 0xC1: // POP B
        UndefinedInstuction(state);
        break;
    case 0xC2: // JNZ addr 
        UndefinedInstuction(state);
        break;
    case 0xC3: // JMP addr
        UndefinedInstuction(state);
        break;
    case 0xC4: // CNZ addr
        UndefinedInstuction(state);
        break;
    case 0xC5: // PUSH B
        UndefinedInstuction(state);
        break;
    case 0xC6: // ADI D8
        UndefinedInstuction(state);
        break;
    case 0xC7: // RST 0
        UndefinedInstuction(state);
        break;
    case 0xC8: // RZ
        UndefinedInstuction(state);
        break;
    case 0xC9: // RET
        UndefinedInstuction(state);
        break;
    case 0xCA: // JZ addr
        UndefinedInstuction(state);
        break;
    case 0xCB: // NOP
        break;
    case 0xCC: // CZ addr
        UndefinedInstuction(state);
        break;
    case 0xCD: // CALL addr
        UndefinedInstuction(state);
        break;
    case 0xCE: // ACI D8
        UndefinedInstuction(state);
        break;
    case 0xCF: // RST 1
        UndefinedInstuction(state);
        break;
    case 0xD0: // RNC
        UndefinedInstuction(state);
        break;
    case 0xD1: // POP D
        UndefinedInstuction(state);
        break;
    case 0xD2: // JNC addr
        UndefinedInstuction(state);
        break;
    case 0xD3: // OUT D8
        UndefinedInstuction(state);
        break;
    case 0xD4: // CNC addr
        UndefinedInstuction(state);
        break;
    case 0xD5: // PUSH D
        UndefinedInstuction(state);
        break;
    case 0xD6: // SUI D8
        UndefinedInstuction(state);
        break;
    case 0xD7: // RST 2
        UndefinedInstuction(state);
        break;
    case 0xD8: // RC
        UndefinedInstuction(state);
        break;
    case 0xD9: // NOP
        break;
    case 0xDA: // JC addr
        UndefinedInstuction(state);
        break;
    case 0xDB: // IN D8
        UndefinedInstuction(state);
        break;
    case 0xDC: // CC addr
        UndefinedInstuction(state);
        break;
    case 0xDD: // NOP
        break;
    case 0xDE: // SBI D8 
        UndefinedInstuction(state);
        break;
    case 0xDF: // RST 3
        UndefinedInstuction(state);
        break;
    case 0xE0: // RPO
        UndefinedInstuction(state);
        break;
    case 0xE1: // POP H
        UndefinedInstuction(state);
        break;
    case 0xE2: // JPO addr
        UndefinedInstuction(state);
        break;
    case 0xE3: // XTHL
        UndefinedInstuction(state);
        break;
    case 0xE4: // CPO addr
        UndefinedInstuction(state);
        break;
    case 0xE5: // PUSH H
        UndefinedInstuction(state);
        break;
    case 0xE6: // ANI D8
        UndefinedInstuction(state);
        break;
    case 0xE7: // RST 4
        UndefinedInstuction(state);
        break;
    case 0xE8: // RPE
        UndefinedInstuction(state);
        break;
    case 0xE9: // PCHL
        UndefinedInstuction(state);
        break;
    case 0xEA: // JPE addr
        UndefinedInstuction(state);
        break;
    case 0xEB: // XCHG
        UndefinedInstuction(state);
        break;
    case 0xEC: // CPE addr
        UndefinedInstuction(state);
        break;
    case 0xED: // NOP
        break;
    case 0xEE: // XRI D8
        UndefinedInstuction(state);
        break;
    case 0xEF: // RST 5
        UndefinedInstuction(state);
        break;
    case 0xF0: // RP
        UndefinedInstuction(state);
        break;
    case 0xF1: // POP PSW
        UndefinedInstuction(state);
        break;
    case 0xF2: // JP addr
        UndefinedInstuction(state);
        break;
    case 0xF3: // DI
        UndefinedInstuction(state);
        break;
    case 0xF4: // CP addr
        UndefinedInstuction(state);
        break;
    case 0xF5: // PUSH PSW
        UndefinedInstuction(state);
        break;
    case 0xF6: // ORI D8
        UndefinedInstuction(state);
        break;
    case 0xF7: // RST 6
        UndefinedInstuction(state);
        break;
    case 0xF8: // RM
        UndefinedInstuction(state);
        break;
    case 0xF9: // SPHL
        UndefinedInstuction(state);
        break;
    case 0xFA: // JM addr
        UndefinedInstuction(state);
        break;
    case 0xFB: // RI
        UndefinedInstuction(state);
        break;
    case 0xFC: // CM addr
        UndefinedInstuction(state);
        break;
    case 0xFD: // NOP
        break;
    case 0xFE: // CPI D8
        UndefinedInstuction(state);
        break;
    case 0xFF: // RST 7
        UndefinedInstuction(state);
        break;
    default:
        UndefinedInstuction(state);
        break;
    }
    state->pc += 1;
}