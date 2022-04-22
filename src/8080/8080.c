#include "8080.h"

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
    case 0x01: // LXI B, word
        state->c = opcode[1];
        state->b = opcode[2];
        state->pc += 2;
        break;
    case 0x02:
        UndefinedInstuction(state);
        break;
    case 0x03:
        UndefinedInstuction(state);
        break;
    case 0x04:
        UndefinedInstuction(state);
        break;
    case 0x05:
        UndefinedInstuction(state);
        break;
    case 0x06:
        UndefinedInstuction(state);
        break;
    case 0x07:
        UndefinedInstuction(state);
        break;
    case 0x08:
        UndefinedInstuction(state);
        break;
    case 0x09:
        UndefinedInstuction(state);
        break;
    case 0x0A:
        UndefinedInstuction(state);
        break;
    case 0x0B:
        UndefinedInstuction(state);
        break;
    case 0x0C:
        UndefinedInstuction(state);
        break;
    case 0x0D:
        UndefinedInstuction(state);
        break;
    case 0x0E:
        UndefinedInstuction(state);
        break;
    case 0x0F:
        UndefinedInstuction(state);
        break;
    case 0x10:
        UndefinedInstuction(state);
        break;
    case 0x11:
        UndefinedInstuction(state);
        break;
    case 0x12:
        UndefinedInstuction(state);
        break;
    case 0x13:
        UndefinedInstuction(state);
        break;
    case 0x14:
        UndefinedInstuction(state);
        break;
    case 0x15:
        UndefinedInstuction(state);
        break;
    case 0x16:
        UndefinedInstuction(state);
        break;
    case 0x17:
        UndefinedInstuction(state);
        break;
    case 0x18:
        UndefinedInstuction(state);
        break;
    case 0x19:
        UndefinedInstuction(state);
        break;
    case 0x1A:
        UndefinedInstuction(state);
        break;
    case 0x1B:
        UndefinedInstuction(state);
        break;
    case 0x1C:
        UndefinedInstuction(state);
        break;
    case 0x1D:
        UndefinedInstuction(state);
        break;
    case 0x1E:
        UndefinedInstuction(state);
        break;
    case 0x1F:
        UndefinedInstuction(state);
        break;
    case 0x20:
        UndefinedInstuction(state);
        break;
    case 0x21:
        UndefinedInstuction(state);
        break;
    case 0x22:
        UndefinedInstuction(state);
        break;
    case 0x23:
        UndefinedInstuction(state);
        break;
    case 0x24:
        UndefinedInstuction(state);
        break;
    case 0x25:
        UndefinedInstuction(state);
        break;
    case 0x26:
        UndefinedInstuction(state);
        break;
    case 0x27:
        UndefinedInstuction(state);
        break;
    case 0x28:
        UndefinedInstuction(state);
        break;
    case 0x29:
        UndefinedInstuction(state);
        break;
    case 0x2A:
        UndefinedInstuction(state);
        break;
    case 0x2B:
        UndefinedInstuction(state);
        break;
    case 0x2C:
        UndefinedInstuction(state);
        break;
    case 0x2D:
        UndefinedInstuction(state);
        break;
    case 0x2E:
        UndefinedInstuction(state);
        break;
    case 0x2F:
        UndefinedInstuction(state);
        break;
    case 0x30:
        UndefinedInstuction(state);
        break;
    case 0x31:
        UndefinedInstuction(state);
        break;
    case 0x32:
        UndefinedInstuction(state);
        break;
    case 0x33:
        UndefinedInstuction(state);
        break;
    case 0x34:
        UndefinedInstuction(state);
        break;
    case 0x35:
        UndefinedInstuction(state);
        break;
    case 0x36:
        UndefinedInstuction(state);
        break;
    case 0x37:
        UndefinedInstuction(state);
        break;
    case 0x38:
        UndefinedInstuction(state);
        break;
    case 0x39:
        UndefinedInstuction(state);
        break;
    case 0x3A:
        UndefinedInstuction(state);
        break;
    case 0x3B:
        UndefinedInstuction(state);
        break;
    case 0x3C:
        UndefinedInstuction(state);
        break;
    case 0x3D:
        UndefinedInstuction(state);
        break;
    case 0x3E:
        UndefinedInstuction(state);
        break;
    case 0x3F:
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
    case 0x80:
        UndefinedInstuction(state);
        break;
    case 0x81:
        UndefinedInstuction(state);
        break;
    case 0x82:
        UndefinedInstuction(state);
        break;
    case 0x83:
        UndefinedInstuction(state);
        break;
    case 0x84:
        UndefinedInstuction(state);
        break;
    case 0x85:
        UndefinedInstuction(state);
        break;
    case 0x86:
        UndefinedInstuction(state);
        break;
    case 0x87:
        UndefinedInstuction(state);
        break;
    case 0x88:
        UndefinedInstuction(state);
        break;
    case 0x89:
        UndefinedInstuction(state);
        break;
    case 0x8A:
        UndefinedInstuction(state);
        break;
    case 0x8B:
        UndefinedInstuction(state);
        break;
    case 0x8C:
        UndefinedInstuction(state);
        break;
    case 0x8D:
        UndefinedInstuction(state);
        break;
    case 0x8E:
        UndefinedInstuction(state);
        break;
    case 0x8F:
        UndefinedInstuction(state);
        break;
    case 0x90:
        UndefinedInstuction(state);
        break;
    case 0x91:
        UndefinedInstuction(state);
        break;
    case 0x92:
        UndefinedInstuction(state);
        break;
    case 0x93:
        UndefinedInstuction(state);
        break;
    case 0x94:
        UndefinedInstuction(state);
        break;
    case 0x95:
        UndefinedInstuction(state);
        break;
    case 0x96:
        UndefinedInstuction(state);
        break;
    case 0x97:
        UndefinedInstuction(state);
        break;
    case 0x98:
        UndefinedInstuction(state);
        break;
    case 0x99:
        UndefinedInstuction(state);
        break;
    case 0x9A:
        UndefinedInstuction(state);
        break;
    case 0x9B:
        UndefinedInstuction(state);
        break;
    case 0x9C:
        UndefinedInstuction(state);
        break;
    case 0x9D:
        UndefinedInstuction(state);
        break;
    case 0x9E:
        UndefinedInstuction(state);
        break;
    case 0x9F:
        UndefinedInstuction(state);
        break;
    case 0xA0:
        UndefinedInstuction(state);
        break;
    case 0xA1:
        UndefinedInstuction(state);
        break;
    case 0xA2:
        UndefinedInstuction(state);
        break;
    case 0xA3:
        UndefinedInstuction(state);
        break;
    case 0xA4:
        UndefinedInstuction(state);
        break;
    case 0xA5:
        UndefinedInstuction(state);
        break;
    case 0xA6:
        UndefinedInstuction(state);
        break;
    case 0xA7:
        UndefinedInstuction(state);
        break;
    case 0xA8:
        UndefinedInstuction(state);
        break;
    case 0xA9:
        UndefinedInstuction(state);
        break;
    case 0xAA:
        UndefinedInstuction(state);
        break;
    case 0xAB:
        UndefinedInstuction(state);
        break;
    case 0xAC:
        UndefinedInstuction(state);
        break;
    case 0xAD:
        UndefinedInstuction(state);
        break;
    case 0xAE:
        UndefinedInstuction(state);
        break;
    case 0xAF:
        UndefinedInstuction(state);
        break;
    case 0xB0:
        UndefinedInstuction(state);
        break;
    case 0xB1:
        UndefinedInstuction(state);
        break;
    case 0xB2:
        UndefinedInstuction(state);
        break;
    case 0xB3:
        UndefinedInstuction(state);
        break;
    case 0xB4:
        UndefinedInstuction(state);
        break;
    case 0xB5:
        UndefinedInstuction(state);
        break;
    case 0xB6:
        UndefinedInstuction(state);
        break;
    case 0xB7:
        UndefinedInstuction(state);
        break;
    case 0xB8:
        UndefinedInstuction(state);
        break;
    case 0xB9:
        UndefinedInstuction(state);
        break;
    case 0xBA:
        UndefinedInstuction(state);
        break;
    case 0xBB:
        UndefinedInstuction(state);
        break;
    case 0xBC:
        UndefinedInstuction(state);
        break;
    case 0xBD:
        UndefinedInstuction(state);
        break;
    case 0xBE:
        UndefinedInstuction(state);
        break;
    case 0xBF:
        UndefinedInstuction(state);
        break;
    case 0xC0:
        UndefinedInstuction(state);
        break;
    case 0xC1:
        UndefinedInstuction(state);
        break;
    case 0xC2:
        UndefinedInstuction(state);
        break;
    case 0xC3:
        UndefinedInstuction(state);
        break;
    case 0xC4:
        UndefinedInstuction(state);
        break;
    case 0xC5:
        UndefinedInstuction(state);
        break;
    case 0xC6:
        UndefinedInstuction(state);
        break;
    case 0xC7:
        UndefinedInstuction(state);
        break;
    case 0xC8:
        UndefinedInstuction(state);
        break;
    case 0xC9:
        UndefinedInstuction(state);
        break;
    case 0xCA:
        UndefinedInstuction(state);
        break;
    case 0xCB:
        UndefinedInstuction(state);
        break;
    case 0xCC:
        UndefinedInstuction(state);
        break;
    case 0xCD:
        UndefinedInstuction(state);
        break;
    case 0xCE:
        UndefinedInstuction(state);
        break;
    case 0xCF:
        UndefinedInstuction(state);
        break;
    case 0xD0:
        UndefinedInstuction(state);
        break;
    case 0xD1:
        UndefinedInstuction(state);
        break;
    case 0xD2:
        UndefinedInstuction(state);
        break;
    case 0xD3:
        UndefinedInstuction(state);
        break;
    case 0xD4:
        UndefinedInstuction(state);
        break;
    case 0xD5:
        UndefinedInstuction(state);
        break;
    case 0xD6:
        UndefinedInstuction(state);
        break;
    case 0xD7:
        UndefinedInstuction(state);
        break;
    case 0xD8:
        UndefinedInstuction(state);
        break;
    case 0xD9:
        UndefinedInstuction(state);
        break;
    case 0xDA:
        UndefinedInstuction(state);
        break;
    case 0xDB:
        UndefinedInstuction(state);
        break;
    case 0xDC:
        UndefinedInstuction(state);
        break;
    case 0xDD:
        UndefinedInstuction(state);
        break;
    case 0xDE:
        UndefinedInstuction(state);
        break;
    case 0xDF:
        UndefinedInstuction(state);
        break;
    case 0xE0:
        UndefinedInstuction(state);
        break;
    case 0xE1:
        UndefinedInstuction(state);
        break;
    case 0xE2:
        UndefinedInstuction(state);
        break;
    case 0xE3:
        UndefinedInstuction(state);
        break;
    case 0xE4:
        UndefinedInstuction(state);
        break;
    case 0xE5:
        UndefinedInstuction(state);
        break;
    case 0xE6:
        UndefinedInstuction(state);
        break;
    case 0xE7:
        UndefinedInstuction(state);
        break;
    case 0xE8:
        UndefinedInstuction(state);
        break;
    case 0xE9:
        UndefinedInstuction(state);
        break;
    case 0xEA:
        UndefinedInstuction(state);
        break;
    case 0xEB:
        UndefinedInstuction(state);
        break;
    case 0xEC:
        UndefinedInstuction(state);
        break;
    case 0xED:
        UndefinedInstuction(state);
        break;
    case 0xEE:
        UndefinedInstuction(state);
        break;
    case 0xEF:
        UndefinedInstuction(state);
        break;
    case 0xF0:
        UndefinedInstuction(state);
        break;
    case 0xF1:
        UndefinedInstuction(state);
        break;
    case 0xF2:
        UndefinedInstuction(state);
        break;
    case 0xF3:
        UndefinedInstuction(state);
        break;
    case 0xF4:
        UndefinedInstuction(state);
        break;
    case 0xF5:
        UndefinedInstuction(state);
        break;
    case 0xF6:
        UndefinedInstuction(state);
        break;
    case 0xF7:
        UndefinedInstuction(state);
        break;
    case 0xF8:
        UndefinedInstuction(state);
        break;
    case 0xF9:
        UndefinedInstuction(state);
        break;
    case 0xFA:
        UndefinedInstuction(state);
        break;
    case 0xFB:
        UndefinedInstuction(state);
        break;
    case 0xFC:
        UndefinedInstuction(state);
        break;
    case 0xFD:
        UndefinedInstuction(state);
        break;
    case 0xFE:
        UndefinedInstuction(state);
        break;
    case 0xFF:
        UndefinedInstuction(state);
        break;
    }
    state->pc += 1;
}