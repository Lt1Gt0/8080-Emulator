#include "8080.h"

State8080* Init8080()
{
    State8080* state = calloc(1, sizeof(State8080));
    state->memory = malloc(0x10000); // Allocate 16k worth of memory
    return state;
}

void UndefinedInstruction(State8080* state)
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
        uint16_t offset = (state->b << 8) | (state->c);
        state->memory[offset] = state->a;
        break;
    case 0x03: // INX B
        uint16_t ans = (uint16_t)((state->b << 8) | (state->c)) + (uint16_t)1;
        state->b = (uint8_t)ans >> 8; // Might not have to typecast
        state->c = ans && 0xFF;
        break;
    case 0x04: // INR B
        uint16_t ans = (uint16_t) state->b + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->b = ans & 0xFF;
        break;
    case 0x05: // DCR B
        uint16_t ans = (uint16_t) state->b + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->b = ans & 0xFF;
        break;
    case 0x06: // MVI B, D8
        state->b = opcode[1];
        state->pc += 1;
        break;
    case 0x07: // RLC
        UndefinedInstruction(state);
        break;
    case 0x08: // NOP
        break;
    case 0x09: // DAD B
        uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)((state->b << 8) | (state->c));
        state->h = ans >> 8;
        state->l = ans & 0xFF;
        state->cc.cy = (ans > 0xFF);
        break;
    case 0x0A: // LDAX B
        uint16_t offset = (state->b << 8) | (state->c);
        state->a = state->memory[offset];
        break;
    case 0x0B: // DCX B
        uint16_t ans = (uint16_t)(state->b << 8) | (state->c) + (~(uint16_t)1 + 1);
        state->b = ans >> 8;
        state->c = ans & 0xFF;
        break;
    case 0x0C: // INR C
        uint16_t ans = (uint16_t) state->c + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->c = ans & 0xFF;
        break;
    case 0x0D: // DCR C
        uint16_t ans = (uint16_t) state->c + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->c = ans & 0xFF;
        break;
    case 0x0E: // MVI C, D8
        state->c = opcode[1];
        state->pc += 1;
        break;
    case 0x0F: // RRC
        UndefinedInstruction(state);
        break;
    case 0x10: // NOP
        break;
    case 0x11: // LXI D, D16
        state->e = opcode[1];
        state->d = opcode[2];
        state->pc += 2;
        break;
    case 0x12: // STAX D
        uint16_t offset = (state->d << 8) | (state->e);    
        state->memory[offset] = state->a;
        break;
    case 0x13: // INX D
        uint16_t ans = (uint16_t)((state->d << 8) | (state->e)) + (uint16_t)1;
        state->d = (uint8_t)ans >> 8; // Might not have to typecast
        state->e = ans & 0xFF;
        break;
    case 0x14: // INR D
        uint16_t ans = (uint16_t) state->d + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->d = ans & 0xFF;
        break;
    case 0x15: // DCR D
        uint16_t ans = (uint16_t) state->d + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->d = ans & 0xFF;
        break;
    case 0x16: // MVI D, D8
        state->d = opcode[1];
        state->pc += 1;
        break;
    case 0x17: // RAL
        UndefinedInstruction(state);
        break;
    case 0x18: // NOP
        break;
    case 0x19: // DAD D
        uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)((state->d << 8) | (state->e));
        state->h = ans >> 8;
        state->l = ans & 0xFF;
        state->cc.cy = (ans > 0xFF);
        UndefinedInstruction(state);
        break;
    case 0x1A: // LDAX D
        uint16_t offset = (state->d << 8) | (state->e);
        state->a = state->memory[offset];
        break;
    case 0x1B: // DCX D
        uint16_t ans = (uint16_t)(state->d << 8) | (state->e) + (~(uint16_t)1 + 1);
        state->d = ans >> 8;
        state->e = ans & 0xFF;
        break;
    case 0x1C: // INR E
        uint16_t ans = (uint16_t) state->e + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->e = ans & 0xFF;
        break;
    case 0x1D: // DCR E
        uint16_t ans = (uint16_t) state->e + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->e = ans & 0xFF;
        break;
    case 0x1E: // MVI E, D8
        state->e = opcode[1];
        state->pc += 1;
        break;
    case 0x1F: // RAR
        UndefinedInstruction(state);
        break;
    case 0x20: // NOP
        break;
    case 0x21: // LXI H, D16
        state->l = opcode[1];
        state->h = opcode[2];
        state->pc += 2;
        break;
    case 0x22: // SHLD adr
        uint16_t offset = (opcode[2] << 8) | (opcode[1]);
        state->memory[offset] = state->l;
        state->memory[offset + 1] = state->l;
        state->pc += 2;
        break;
    case 0x23: // INX H
        uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)1;
        state->h = (uint8_t)ans >> 8; // Might not have to typecast
        state->l = ans & 0xFF;
        break;
    case 0x24: // INR H
        uint16_t ans = (uint16_t) state->h + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->h = ans & 0xFF;
        break;
    case 0x25: // DCR H
        uint16_t ans = (uint16_t) state->h + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->h = ans & 0xFF;
        break;
    case 0x26: // MVI H, D8
        state->h = opcode[1];
        state->pc += 1;
        break;
    case 0x27: // DAA
        UndefinedInstruction(state);
        break;
    case 0x28: // NOP
        break;
    case 0x29: // DAD H
        uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)((state->h << 8) | (state->l));
        state->h = ans >> 8;
        state->l = ans & 0xFF;
        state->cc.cy = (ans > 0xFF);
        UndefinedInstruction(state);
        break;
    case 0x2A: // LHLD adr
        uint16_t offset = (opcode[2] << 8) | (opcode[1]);
        state->l =state->memory[offset];
        state->h =state->memory[offset + 1];
        state->pc += 2;
        break;
    case 0x2B: // DCX H
        uint16_t ans = (uint16_t)(state->h << 8) | (state->l) + (~(uint16_t)1 + 1);
        state->h = ans >> 8;
        state->l = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x2C: // INR L
        uint16_t ans = (uint16_t) state->l + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->l = ans & 0xFF;
        break;
    case 0x2D: // DCR L
        uint16_t ans = (uint16_t) state->l + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->l = ans & 0xFF;
        break;
    case 0x2E: // MVI L, D8
        state->l = opcode[1];
        state->pc += 1;
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
        uint16_t offset = (opcode[2] << 8) | (opcode[1]);
        state->memory[offset] = state->a;
        break;
    case 0x33: // INX SP
        state->sp += 1; // Double check to make sure it is correct
        break;
    case 0x34: // INR M
        uint16_t ans = (uint16_t)((state->h << 8) | (state->l)) + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->h = ans >> 8; /* REDFLAG DONT KNOW IF THIS WORKS */
        state->l = ans & 0xFF;
        break;
    case 0x35: // DCR M
        // Not sure if any of this is correct
        uint16_t offset = ((uint16_t)(state->h << 8) | (state->l));
        uint16_t ans = state->memory[offset] + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->h = ans >> 8;
        state->l = ans & 0xFF;
        break;
    case 0x36: // MVI M, D8
        uint16_t offset = (state->h << 8) | (state->l);
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
        uint16_t offset = (opcode[2] << 8) | (opcode[1]);
        state->a = state->memory[offset];
        state->pc += 2;
        break;
    case 0x3B: // DCX SP
        state->sp = state->sp + (~(uint16_t)1 + 1);
        break;
    case 0x3C: // INR A
        uint16_t ans = (uint16_t) state->a + (uint16_t)1;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x3D: // DCR A
        uint16_t ans = (uint16_t) state->a + (~(uint16_t)1 + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x3E: // MVI A, D8
        state->a = opcode[1];
        state->pc += 1;
        break;
    case 0x3F: // CMC
        state->cc.cy = ~(state->cc.cy);
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->b = state->memory[offset];
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->c = state->memory[offset];
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->d = state->memory[offset];
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->e = state->memory[offset];
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->h = state->memory[offset];
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
        state->l = state->h;
        break;
    case 0x6D: // MOV L, L
        // Set register to itself so just break
        break;
    case 0x6E: // MOV L, M
        uint16_t offset = (state->h << 8) | (state->l);
        state->l = state->memory[offset];
        break;
    case 0x6F: // MOV L, A
        state->l = state->a;
        break;
    case 0x70: // MOV M, B
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->b;
        break;
    case 0x71: // MOV M, C
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->c;
        break;
    case 0x72: // MOV M, D
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->d;
        break;
    case 0x73: // MOV M, E
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->e;
        break;
    case 0x74: // MOV M, H
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->h;
        break;
    case 0x75: // MOV M, L
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->l;
        break;
    case 0x76: // HLT
        break;
    case 0x77: // MOV M, A
        uint16_t offset = (state->h << 8) | (state->l);
        state->memory[offset] = state->a;
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
        uint16_t offset = (state->h << 8) | (state->l);
        state->a = state->memory[offset];
        break;
    case 0x7F: // MOV A, A
        // Set register to itself so just break
        break;
    case 0x80: // ADD B
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->b;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x81: // ADD C 
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->c;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x82: // ADD D
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->d;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x83: // ADD E
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->e;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x84: // ADD H
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->h;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x85: // ADD L
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->l;
        UpdateFlags(ans, &state->cc); 
        state->a = ans && 0xFF;
        break;
    case 0x86: // ADD M
        uint16_t offset = (uint16_t)((state->h << 8) | (state->l));
        uint16_t ans = (uint16_t) state->a + state->memory[offset];
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x87: // ADD A
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->a;
        UpdateFlags(ans, &state->cc);
        state->a = ans && 0xFF;
        break;
    case 0x88: // ADC B
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->b + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x89: // ADC C
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->c + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8A: // ADC D
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->d + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8B: // ADC E
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->e + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8C: // ADC H
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->h + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8D: // ADC L
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->l + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8E: // ADC M
        uint16_t offset = (uint16_t)((state->h << 8) | (state->l));
        uint16_t ans = (uint16_t) state->a + state->memory[offset];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x8F: // ADC A
        uint16_t ans = (uint16_t) state->a + (uint16_t) state->a + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x90: // SUB B
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->b + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x91: // SUB C
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->c + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x92: // SUB D
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->d + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
    case 0x93: // SUB E
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->e + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
    case 0x94: // SUB H
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->h + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x95: // SUB L
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->l + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x96: // SUB M
        uint16_t ans = (uint16_t) state->a + (~((uint16_t)(state->h << 8) | (state->l)) + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x97: // SUB A
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->a + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x98: // SBB B
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->b + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0x99: // SBB C
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->c + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9A: // SBB D
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->d + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9B: // SBB E
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->e + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9C: // SBB H
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->h + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9D: // SBB L
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->l + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9E: // SBB M
        uint16_t ans = (uint16_t) state->a + (~((uint16_t)(state->h << 8) | (state->l)) + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0x9F: // SBB A
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->a + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        UndefinedInstruction(state);
        break;
    case 0xA0: // ANA B
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->b;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA1: // ANA C
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->c;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA2: // ANA D
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->d;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA3: // ANA E
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->e;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA4: // ANA H
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->h;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA5: // ANA L
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->l;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA6: // ANA M
        uint16_t offset = (uint16_t)((state->h << 8) | (state->l));
        uint16_t ans = (uint16_t) state->a & state->memory[offset];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA7: // ANA A
        uint16_t ans = (uint16_t) state->a & (uint16_t) state->a;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA8: // XRA B
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->b;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xA9: // XRA C
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->c;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAA: // XRA D
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->d;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAB: // XRA E
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->e;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAC: // XRA H
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->h;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAD: // XRA L
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->l;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAE: // XRA M
        uint16_t offset = (uint16_t)((state->h << 8) | (state->l));
        uint16_t ans = (uint16_t) state->a | state->memory[offset];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xAF: // XRA A
        uint16_t ans = (uint16_t) state->a ^ (uint16_t) state->a;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB0: // ORA B
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->b;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB1: // ORA C
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->c;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB2: // ORA D
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->d;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB3: // ORA E
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->e;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB4: // ORA H
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->h;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB5: // ORA L
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->l;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB6: // ORA M
        uint16_t offset = (uint16_t)((state->h << 8) | (state->l));
        uint16_t ans = (uint16_t) state->a | state->memory[offset];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB7: // ORA A
        uint16_t ans = (uint16_t) state->a | (uint16_t) state->a;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xB8: // CMP B
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->b + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xB9: // CMP C
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->c + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xBA: // CMP D
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->d + 1);
        UpdateFlags(ans, &state->cc);
    case 0xBB: // CMP E
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->e + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xBC: // CMP H
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->h + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xBD: // CMP L
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->l + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xBE: // CMP M
        uint16_t offset = (uint16_t)(state->h << 8) | (state->l);
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->memory[offset] + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xBF: // CMP A
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) state->a + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xC0: // RNZ
        UndefinedInstruction(state);
        break;
    case 0xC1: // POP B
        UndefinedInstruction(state);
        break;
    case 0xC2: // JNZ adr 
        UndefinedInstruction(state);
        break;
    case 0xC3: // JMP adr
        state->pc = (uint16_t)((opcode[2] << 8) | (opcode[1]));
        break;
    case 0xC4: // CNZ adr
        UndefinedInstruction(state);
        break;
    case 0xC5: // PUSH B
        UndefinedInstruction(state);
        break;
    case 0xC6: // ADI D8
        uint16_t ans = (uint16_t) state->a + (uint16_t) opcode[1];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;        
        break;
    case 0xC7: // RST 0
        UndefinedInstruction(state);
        break;
    case 0xC8: // RZ
        UndefinedInstruction(state);
        break;
    case 0xC9: // RET
        UndefinedInstruction(state);
        break;
    case 0xCA: // JZ adr
        UndefinedInstruction(state);
        break;
    case 0xCB: // NOP
        break;
    case 0xCC: // CZ adr
        UndefinedInstruction(state);
        break;
    case 0xCD: // CALL adr
        UndefinedInstruction(state);
        break;
    case 0xCE: // ACI D8
        uint16_t ans = (uint16_t) state->a + (uint16_t) opcode[1] + (uint16_t) state->cc.cy;
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xCF: // RST 1
        UndefinedInstruction(state);
        break;
    case 0xD0: // RNC
        UndefinedInstruction(state);
        break;
    case 0xD1: // POP D
        UndefinedInstruction(state);
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
        UndefinedInstruction(state);
        break;
    case 0xD6: // SUI D8
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) opcode[1] + 1); // Make sure this is correct 
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xD7: // RST 2
        UndefinedInstruction(state);
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
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) opcode[1] + 1) + (~(uint16_t) state->cc.cy + 1);
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xDF: // RST 3
        UndefinedInstruction(state);
        break;
    case 0xE0: // RPO
        UndefinedInstruction(state);
        break;
    case 0xE1: // POP H
        UndefinedInstruction(state);
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
        UndefinedInstruction(state);
        break;
    case 0xE6: // ANI D8
        uint16_t ans = (uint16_t) state->a & (uint16_t) opcode[1];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xE7: // RST 4
        UndefinedInstruction(state);
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
        uint8_t tmp = state->h;
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
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xEF: // RST 5
        UndefinedInstruction(state);
        break;
    case 0xF0: // RP
        UndefinedInstruction(state);
        break;
    case 0xF1: // POP PSW
        UndefinedInstruction(state);
        break;
    case 0xF2: // JP adr
        UndefinedInstruction(state);
        break;
    case 0xF3: // DI
        UndefinedInstruction(state);
        break;
    case 0xF4: // CP adr
        UndefinedInstruction(state);
        break;
    case 0xF5: // PUSH PSW
        UndefinedInstruction(state);
        break;
    case 0xF6: // ORI D8
        uint16_t ans = (uint16_t) state->a | (uint16_t) opcode[1];
        UpdateFlags(ans, &state->cc);
        state->a = ans & 0xFF;
        break;
    case 0xF7: // RST 6
        UndefinedInstruction(state);
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
    case 0xFB: // RI
        UndefinedInstruction(state);
        break;
    case 0xFC: // CM adr
        UndefinedInstruction(state);
        break;
    case 0xFD: // NOP
        break;
    case 0xFE: // CPI D8
        uint16_t ans = (uint16_t) state->a + (~(uint16_t) opcode[1] + 1);
        UpdateFlags(ans, &state->cc);
        break;
    case 0xFF: // RST 7
        UndefinedInstruction(state);
        break;
    default:
        UndefinedInstruction(state);
        break;
    }
    state->pc += 1;
}

void UpdateFlags(uint16_t ans, ConditionCodes* cc)
{
    cc->z = ((ans & 0xFF) == 0);
    cc->s = ((ans & MSB_UINT8) != 0);
    cc->cy = (ans > 0xFF);

    // Worry about parity later
}