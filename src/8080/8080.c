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
    case 0x00:
        UndefinedInstuction(state);
        break;
    case 0x01:
        UndefinedInstuction(state);
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
    case 0x30:
        UndefinedInstuction(state);
        break;
    case 0x41:
        UndefinedInstuction(state);
        break;
    case 0x42:
        UndefinedInstuction(state);
        break;
    case 0x43:
        UndefinedInstuction(state);
        break;
    case 0x44:
        UndefinedInstuction(state);
        break;
    case 0x45:
        UndefinedInstuction(state);
        break;
    case 0x46:
        UndefinedInstuction(state);
        break;
    case 0x47:
        UndefinedInstuction(state);
        break;
    case 0x48:
        UndefinedInstuction(state);
        break;
    case 0x49:
        UndefinedInstuction(state);
        break;
    case 0x4A:
        UndefinedInstuction(state);
        break;
    case 0x4B:
        UndefinedInstuction(state);
        break;
    case 0x4C:
        UndefinedInstuction(state);
        break;
    case 0x4D:
        UndefinedInstuction(state);
        break;
    case 0x4E:
        UndefinedInstuction(state);
        break;
    case 0x4F:
        UndefinedInstuction(state);
        break;
    case 0x50:
        UndefinedInstuction(state);
        break;
    case 0x51:
        UndefinedInstuction(state);
        break;
    case 0x52:
        UndefinedInstuction(state);
        break;
    case 0x53:
        UndefinedInstuction(state);
        break;
    case 0x54:
        UndefinedInstuction(state);
        break;
    case 0x55:
        UndefinedInstuction(state);
        break;
    case 0x56:
        UndefinedInstuction(state);
        break;
    case 0x57:
        UndefinedInstuction(state);
        break;
    case 0x58:
        UndefinedInstuction(state);
        break;
    case 0x59:
        UndefinedInstuction(state);
        break;
    case 0x5A:
        UndefinedInstuction(state);
        break;
    case 0x5B:
        UndefinedInstuction(state);
        break;
    case 0x5C:
        UndefinedInstuction(state);
        break;
    case 0x5D:
        UndefinedInstuction(state);
        break;
    case 0x5E:
        UndefinedInstuction(state);
        break;
    case 0x5F:
        UndefinedInstuction(state);
        break;
    case 0x60:
        UndefinedInstuction(state);
        break;
    case 0x61:
        UndefinedInstuction(state);
        break;
    case 0x62:
        UndefinedInstuction(state);
        break;
    case 0x63:
        UndefinedInstuction(state);
        break;
    case 0x64:
        UndefinedInstuction(state);
        break;
    case 0x65:
        UndefinedInstuction(state);
        break;
    case 0x66:
        UndefinedInstuction(state);
        break;
    case 0x67:
        UndefinedInstuction(state);
        break;
    case 0x68:
        UndefinedInstuction(state);
        break;
    case 0x69:
        UndefinedInstuction(state);
        break;
    case 0x6A:
        UndefinedInstuction(state);
        break;
    case 0x6B:
        UndefinedInstuction(state);
        break;
    case 0x6C:
        UndefinedInstuction(state);
        break;
    case 0x6D:
        UndefinedInstuction(state);
        break;
    case 0x6E:
        UndefinedInstuction(state);
        break;
    case 0x6F:
        UndefinedInstuction(state);
        break;
    case 0x70:
        UndefinedInstuction(state);
        break;
    case 0x71:
        UndefinedInstuction(state);
        break;
    case 0x72:
        UndefinedInstuction(state);
        break;
    case 0x73:
        UndefinedInstuction(state);
        break;
    case 0x74:
        UndefinedInstuction(state);
        break;
    case 0x75:
        UndefinedInstuction(state);
        break;
    case 0x76:
        UndefinedInstuction(state);
        break;
    case 0x77:
        UndefinedInstuction(state);
        break;
    case 0x78:
        UndefinedInstuction(state);
        break;
    case 0x79:
        UndefinedInstuction(state);
        break;
    case 0x7A:
        UndefinedInstuction(state);
        break;
    case 0x7B:
        UndefinedInstuction(state);
        break;
    case 0x7C:
        UndefinedInstuction(state);
        break;
    case 0x7D:
        UndefinedInstuction(state);
        break;
    case 0x7E:
        UndefinedInstuction(state);
        break;
    case 0x7F:
        UndefinedInstuction(state);
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
}