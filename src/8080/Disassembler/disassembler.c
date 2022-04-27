#include "8080/Disassembler/disassembler.h"

int DecodeInstruction(unsigned char* buffer, int pc)
{
    unsigned char* opcode = &buffer[pc];
    int opBytes = 1;
    printf("%04x: ", pc);

    switch (*opcode) {
    case 0x00: 
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x01:
        PrintRegMultipleOperands("LXI", "B", opcode, 3);
        opBytes = 3;
        break;
    case 0x02:
        PrintOpcodeReg("STAX", "B", opcode[0]);
        break;
    case 0x03:
        PrintOpcodeReg("INX", "B", opcode[0]);
        break;
    case 0x04:
        PrintOpcodeReg("INR", "B", opcode[0]);
        break;
    case 0x05:
        PrintOpcodeReg("DCR", "B", opcode[0]);
        break;
    case 0x06:
        PrintRegMultipleOperands("MVI", "B", opcode, 2);
        opBytes = 2;
        break;
    case 0x07:
        PrintOpcode("RLC", opcode[0]);
        break;
    case 0x08:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x09:
        PrintOpcodeReg("DAD", "B", opcode[0]);
        break;
    case 0x0A:
        PrintOpcodeReg("LDAX", "B", opcode[0]);
        break;
    case 0x0B:
        PrintOpcodeReg("DCX", "B", opcode[0]);
        break;
    case 0x0C:
        PrintOpcodeReg("INR", "C", opcode[0]);
        break;
    case 0x0D:
        PrintOpcodeReg("DCR", "C", opcode[0]);
        break;
    case 0x0E:
        PrintRegMultipleOperands("MVI", "C", opcode, 2);
        opBytes = 2;
        break;
    case 0x0F:
        PrintOpcode("RRC", opcode[0]);
        break;
    case 0x10:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x11:
        PrintRegMultipleOperands("LXI", "D", opcode, 3);
        opBytes = 3;
        break;
    case 0x12:
        PrintOpcodeReg("STAX", "D", opcode[0]);
        break;
    case 0x13: 
        PrintOpcodeReg("INX", "D", opcode[0]);
        break;
    case 0x14:
        PrintOpcodeReg("INR", "D", opcode[0]);
        break;
    case 0x15:
        PrintOpcodeReg("DCR", "D", opcode[0]);
        break;
    case 0x16:
        PrintRegMultipleOperands("MVI", "D", opcode, 2);
        opBytes = 2;
        break;
    case 0x17:
        PrintOpcode("RAL", opcode[0]);
        break;
    case 0x18:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x19:
        PrintOpcodeReg("DAD", "D", opcode[0]);
        break;
    case 0x1A:
        PrintOpcodeReg("LDAX", "D", opcode[0]);
        break;
    case 0x1B:
        PrintOpcodeReg("DCX", "D", opcode[0]);
        break;
    case 0x1C:
        PrintOpcodeReg("INR", "E", opcode[0]);
        break;
    case 0x1D:
        PrintOpcodeReg("DCR", "E", opcode[0]);
        break;
    case 0x1E:
        PrintRegMultipleOperands("MVI", "E", opcode, 2);
        opBytes = 2;
        break;
    case 0x1F:
        PrintOpcode("RAR", opcode[0]);
        break;
    case 0x20:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x21:
        PrintRegMultipleOperands("LXI", "H", opcode, 3);
        opBytes = 3;
        break;
    case 0x22:
        PrintMultipleOperands("SHLD", opcode, 3);
        opBytes = 3;
        break;
    case 0x23:
        PrintOpcodeReg("INX", "H", opcode[0]);
        break;
    case 0x24:
        PrintOpcodeReg("INR", "H", opcode[0]);
        break;
    case 0x25:
        PrintOpcodeReg("DCR", "H", opcode[0]);
        break;
    case 0x26: 
        PrintRegMultipleOperands("MVI", "H", opcode, 2);
        opBytes = 2;
        break;
    case 0x27:
        PrintOpcode("DAA", opcode[0]);
        break;
    case 0x28:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x29:
        PrintOpcodeReg("DAD", "H", opcode[0]);
        break;
    case 0x2A:
        PrintMultipleOperands("LHLD", opcode, 2);
        opBytes = 3;
        break;
    case 0x2B:
        PrintOpcodeReg("DCX", "H", opcode[0]);
        break;
    case 0x2C:
        PrintOpcodeReg("INR", "L", opcode[0]);
        break;
    case 0x2D:
        PrintOpcodeReg("DCR", "L", opcode[0]);
        break;
    case 0x2E:
        PrintRegMultipleOperands("MVI", "L", opcode, 2);
        opBytes = 2;
        break;
    case 0x2F:
        PrintOpcode("CMA", opcode[0]);
        break;
    case 0x30:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x31: 
        PrintRegMultipleOperands("LXI", "SP", opcode, 3);
        opBytes = 3;
        break;
    case 0x32:
        PrintMultipleOperands("STA", opcode, 3);
        opBytes = 3;
        break;
    case 0x33:
        PrintOpcodeReg("INX", "SP", opcode[0]);
        break;
    case 0x34:
        PrintOpcodeReg("INR", "M", opcode[0]);
        break;
    case 0x35:
        PrintOpcodeReg("DCR", "M", opcode[0]);
        break;
    case 0x36:
        PrintRegMultipleOperands("MVI", "M", opcode, 2);
        opBytes = 2;
        break;
    case 0x37:
        PrintOpcode("STC", opcode[0]);
        break;
    case 0x38:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0x39: 
        PrintOpcodeReg("DAD", "SP", opcode[0]);
        break;
    case 0x3A:
        PrintMultipleOperands("LDA", opcode, 3);
        opBytes = 3;
        break;
    case 0x3B:
        PrintOpcodeReg("DCX", "SP", opcode[0]);
        break;
    case 0x3C:
        PrintOpcodeReg("INR", "A", opcode[0]);
        break;
    case 0x3D:
        PrintOpcodeReg("DCR", "A", opcode[0]);
        break;
    case 0x3E:
        PrintRegMultipleOperands("MVI", "A", opcode, 2);
        opBytes = 2;
        break;
    case 0x3F:
        PrintOpcode("CMC", opcode[0]);
        break;
    case 0x40:
        PrintOpcodeReg("MOV", "B, B", opcode[0]);
        break;
    case 0x41:
        PrintOpcodeReg("MOV", "B , C", opcode[0]);
        break;
    case 0x42:
        PrintOpcodeReg("MOV", "B, D", opcode[0]);
        break;
    case 0x43:
        PrintOpcodeReg("MOV", "B, E", opcode[0]);
        break;
    case 0x44:
        PrintOpcodeReg("MOV", "B, H", opcode[0]);
        break;
    case 0x45:
        PrintOpcodeReg("MOV", "B, L", opcode[0]);
        break;
    case 0x46:
        PrintOpcodeReg("MOV", "B, M", opcode[0]);
        break;
    case 0x47:
        PrintOpcodeReg("MOV", "B, A", opcode[0]);
        break;
    case 0x48:
        PrintOpcodeReg("MOV", "C, B", opcode[0]);
        break;
    case 0x49:
        PrintOpcodeReg("MOV", "C, C", opcode[0]);
        break;
    case 0x4A:
        PrintOpcodeReg("MOV", "C, D", opcode[0]);
        break;
    case 0x4B:
        PrintOpcodeReg("MOV", "C, E", opcode[0]);
        break;
    case 0x4C: 
        PrintOpcodeReg("MOV", "C, H", opcode[0]);
        break;
    case 0x4D:
        PrintOpcodeReg("MOV", "C, L", opcode[0]);
        break;
    case 0x4E:
        PrintOpcodeReg("MOV", "C, M", opcode[0]);
        break;
    case 0x4F:
        PrintOpcodeReg("MOV", "C, A", opcode[0]);
        break;
    case 0x50:
        PrintOpcodeReg("MOV", "C, B", opcode[0]);
        break;
    case 0x51:
        PrintOpcodeReg("MOV", "D, C", opcode[0]);
        break;
    case 0x52:
        PrintOpcodeReg("MOV", "D, D", opcode[0]);
        break;
    case 0x53:
        PrintOpcodeReg("MOV", "D, E", opcode[0]);
        break;
    case 0x54:
        PrintOpcodeReg("MOV", "D, H", opcode[0]);
        break;
    case 0x55:
        PrintOpcodeReg("MOV", "D, H", opcode[0]);
        break;
    case 0x56:
        PrintOpcodeReg("MOV", "D, M", opcode[0]);
        break;
    case 0x57:
        PrintOpcodeReg("MOV", "D, A", opcode[0]);
        break;
    case 0x58:
        PrintOpcodeReg("MOV", "E, B", opcode[0]);
        break;
    case 0x59:
        PrintOpcodeReg("MOV", "E, C", opcode[0]);
        break;
    case 0x5A:
        PrintOpcodeReg("MOV", "E, D", opcode[0]);
        break;
    case 0x5B:
        PrintOpcodeReg("MOV", "E, E", opcode[0]);
        break;
    case 0x5C:
        PrintOpcodeReg("MOV", "E, H", opcode[0]);
        break;
    case 0x5D:
        PrintOpcodeReg("MOV", "E, L", opcode[0]);
        break;
    case 0x5E:
        PrintOpcodeReg("MOV", "E, M", opcode[0]);
        break;
    case 0x5F: 
        PrintOpcodeReg("MOV", "E, A", opcode[0]);
        break;
    case 0x60:
        PrintOpcodeReg("MOV", "H, B", opcode[0]);
        break;
    case 0x61:
        PrintOpcodeReg("MOV", "H, C", opcode[0]);
        break;
    case 0x62:
        PrintOpcodeReg("MOV", "H, D", opcode[0]);
        break;
    case 0x63:
        PrintOpcodeReg("MOV", "H, E", opcode[0]);
        break;
    case 0x64:
        PrintOpcodeReg("MOV", "H, H", opcode[0]);
        break;
    case 0x65:
        PrintOpcodeReg("MOV", "H, L", opcode[0]);
        break;
    case 0x66:
        PrintOpcodeReg("MOV", "H, M", opcode[0]);
        break;
    case 0x67:
        PrintOpcodeReg("MOV", "H, A", opcode[0]);
        break;
    case 0x68:
        PrintOpcodeReg("MOV", "L, B", opcode[0]);
        break;
    case 0x69:
        PrintOpcodeReg("MOV", "L, C", opcode[0]);
        break;
    case 0x6A:
        PrintOpcodeReg("MOV", "L, D", opcode[0]);
        break;
    case 0x6B:
        PrintOpcodeReg("MOV", "L, E", opcode[0]);
        break;
    case 0x6C:
        PrintOpcodeReg("MOV", "L, H", opcode[0]);
        break;
    case 0x6D:
        PrintOpcodeReg("MOV", "L, L", opcode[0]);
        break;
    case 0x6E:
        PrintOpcodeReg("MOV", "L, M", opcode[0]);
        break;
    case 0x6F:
        PrintOpcodeReg("MOV", "L, A", opcode[0]);
        break;
    case 0x70:
        PrintOpcodeReg("MOV", "M, B", opcode[0]);
        break;
    case 0x71:
        PrintOpcodeReg("MOV", "M, C", opcode[0]);
        break;
    case 0x72:
        PrintOpcodeReg("MOV", "M, D", opcode[0]);
        break;
    case 0x73:
        PrintOpcodeReg("MOV", "M, E", opcode[0]);
        break;
    case 0x74:
        PrintOpcodeReg("MOV", "M, H", opcode[0]);
        break;
    case 0x75:
        PrintOpcodeReg("MOV", "M, L", opcode[0]);
        break;
    case 0x76:
        PrintOpcode("HLT", opcode[0]);
        break;
    case 0x77:
        PrintOpcodeReg("MOV", "M, A", opcode[0]);
        break;
    case 0x78:
        PrintOpcodeReg("MOV", "A, B", opcode[0]);
        break;
    case 0x79:
        PrintOpcodeReg("MOV", "A, C", opcode[0]);
        break;
    case 0x7A:
        PrintOpcodeReg("MOV", "A, D", opcode[0]);
        break;
    case 0x7B:
        PrintOpcodeReg("MOV", "A, E", opcode[0]);
        break;
    case 0x7C:
        PrintOpcodeReg("MOV", "A, H", opcode[0]);
        break;
    case 0x7D:
        PrintOpcodeReg("MOV", "A, L", opcode[0]);
        break;
    case 0x7E:
        PrintOpcodeReg("MOV", "A, M", opcode[0]);
        break;
    case 0x7F:
        PrintOpcodeReg("MOV", "A, A", opcode[0]);
        break;
    case 0x80:
        PrintOpcodeReg("ADD", "B", opcode[0]);
        break;
    case 0x81:
        PrintOpcodeReg("ADD", "C", opcode[0]);
        break;
    case 0x82:
        PrintOpcodeReg("ADD", "D", opcode[0]);
        break;
    case 0x83:
        PrintOpcodeReg("ADD", "E", opcode[0]);
        break;
    case 0x84:
        PrintOpcodeReg("ADD", "H", opcode[0]);
        break;
    case 0x85:
        PrintOpcodeReg("ADD", "L", opcode[0]);
        break;
    case 0x86:
        PrintOpcodeReg("ADD", "M", opcode[0]);
        break;
    case 0x87:
        PrintOpcodeReg("ADD", "A", opcode[0]);
        break;
    case 0x88:
        PrintOpcodeReg("ADC", "B", opcode[0]);
        break;
    case 0x89:
        PrintOpcodeReg("ADC", "C", opcode[0]);
        break;
    case 0x8A:
        PrintOpcodeReg("ADC", "D", opcode[0]);
        break;
    case 0x8B:
        PrintOpcodeReg("ADC", "E", opcode[0]);
        break;
    case 0x8C:
        PrintOpcodeReg("ADC", "H", opcode[0]);
        break;
    case 0x8D:
        PrintOpcodeReg("ADC", "L", opcode[0]);
        break;
    case 0x8E:
        PrintOpcodeReg("ADC", "M", opcode[0]);
        break;
    case 0x8F:
        PrintOpcodeReg("ADC", "A", opcode[0]);
        break;
    case 0x90:
        PrintOpcodeReg("SUB", "B", opcode[0]);
        break;
    case 0x91:
        PrintOpcodeReg("SUB", "C", opcode[0]);
        break;
    case 0x92:
        PrintOpcodeReg("SUB", "D", opcode[0]);
        break;
    case 0x93:
        PrintOpcodeReg("SUB", "E", opcode[0]);
        break;
    case 0x94:
        PrintOpcodeReg("SUB", "H", opcode[0]);
        break;
    case 0x95:
        PrintOpcodeReg("SUB", "L", opcode[0]);
        break;
    case 0x96:
        PrintOpcodeReg("SUB", "M", opcode[0]);
        break;
    case 0x97:
        PrintOpcodeReg("SUB", "A", opcode[0]);
        break;
    case 0x98:
        PrintOpcodeReg("SBB", "B", opcode[0]);
        break;
    case 0x99:
        PrintOpcodeReg("SBB", "C", opcode[0]);
        break;
    case 0x9A:
        PrintOpcodeReg("SBB", "D", opcode[0]);
        break;
    case 0x9B:
        PrintOpcodeReg("SBB", "E", opcode[0]);
        break;
    case 0x9C:
        PrintOpcodeReg("SBB", "H", opcode[0]);
        break;
    case 0x9D:
        PrintOpcodeReg("SBB", "L", opcode[0]);
        break;
    case 0x9E:
        PrintOpcodeReg("SBB", "M", opcode[0]);
        break;
    case 0x9F:
        PrintOpcodeReg("SBB", "A", opcode[0]);
        break;
    case 0xA0:
        PrintOpcodeReg("ANA", "B", opcode[0]);
        break;
    case 0xA1:
        PrintOpcodeReg("ANA", "C", opcode[0]);
        break;
    case 0xA2:
        PrintOpcodeReg("ANA", "D", opcode[0]);
        break;
    case 0xA3:
        PrintOpcodeReg("ANA", "E", opcode[0]);
        break;
    case 0xA4:
        PrintOpcodeReg("ANA", "H", opcode[0]);
        break;
    case 0xA5:
        PrintOpcodeReg("ANA", "L", opcode[0]);
        break;
    case 0xA6:
        PrintOpcodeReg("ANA", "M", opcode[0]);
        break;
    case 0xA7:
        PrintOpcodeReg("ANA", "A", opcode[0]);
        break;
    case 0xA8:
        PrintOpcodeReg("XRA", "B", opcode[0]);
        break;
    case 0xA9:
        PrintOpcodeReg("XRA", "C", opcode[0]);
        break;
    case 0xAA:
        PrintOpcodeReg("XRA", "D", opcode[0]);
        break;
    case 0xAB:
        PrintOpcodeReg("XRA", "E", opcode[0]);
        break;
    case 0xAC:
        PrintOpcodeReg("XRA", "H", opcode[0]);
        break;
    case 0xAD:
        PrintOpcodeReg("XRA", "L", opcode[0]);
        break;
    case 0xAE:
        PrintOpcodeReg("XRA", "M", opcode[0]);
        break;
    case 0xAF:
        PrintOpcodeReg("XRA", "A", opcode[0]);
        break;
    case 0xB0:
        PrintOpcodeReg("ORA", "B", opcode[0]);
        break;
    case 0xB1:
        PrintOpcodeReg("ORA", "C", opcode[0]);
        break;
    case 0xB2:
        PrintOpcodeReg("ORA", "D", opcode[0]);
        break;
    case 0xB3:
        PrintOpcodeReg("ORA", "E", opcode[0]);
        break;
    case 0xB4:
        PrintOpcodeReg("ORA", "H", opcode[0]);
        break;
    case 0xB5:
        PrintOpcodeReg("ORA", "L", opcode[0]);
        break;
    case 0xB6:
        PrintOpcodeReg("ORA", "M", opcode[0]);
        break;
    case 0xB7:
        PrintOpcodeReg("ORA", "A", opcode[0]);
        break;
    case 0xB8:
        PrintOpcodeReg("CMP", "B", opcode[0]);
        break;
    case 0xB9:
        PrintOpcodeReg("CMP", "C", opcode[0]);
        break;
    case 0xBA:
        PrintOpcodeReg("CMP", "D", opcode[0]);
        break;
    case 0xBB:
        PrintOpcodeReg("CMP", "E", opcode[0]);
        break;
    case 0xBC:
        PrintOpcodeReg("CMP", "H", opcode[0]);
        break;
    case 0xBD:
        PrintOpcodeReg("CMP", "L", opcode[0]);
        break;
    case 0xBE:
        PrintOpcodeReg("CMP", "M", opcode[0]);
        break;
    case 0xBF:
        PrintOpcodeReg("CMP", "A", opcode[0]);
        break;
    case 0xC0:
        PrintOpcode("RNZ", opcode[0]);
        break;
    case 0xC1:
        PrintOpcodeReg("POP", "B", opcode[0]);
        break;
    case 0xC2:
        PrintMultipleOperands("JNZ", opcode, 3);
        opBytes = 3;
        break;
    case 0xC3:
        PrintMultipleOperands("JMP", opcode, 3);
        opBytes = 3;
        break;
    case 0xC4:
        PrintMultipleOperands("CNZ", opcode, 3);
        opBytes = 3;
        break;
    case 0xC5:
        PrintOpcodeReg("PUSH", "B", opcode[0]);
        break;
    case 0xC6:
        PrintMultipleOperands("ADI", opcode, 2);
        opBytes = 2;
        break;
    case 0xC7:
        PrintOpcodeReg("RST", "0", opcode[0]);
        break;
    case 0xC8:
        PrintOpcode("RZ", opcode[0]);
        break;
    case 0xC9:
        PrintOpcode("RET", opcode[0]);
        break;
    case 0xCA:
        PrintMultipleOperands("JZ", opcode, 3);
        opBytes = 3;
        break;
    case 0xCB:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0xCC:
        PrintMultipleOperands("CZ", opcode, 3);
        opBytes = 3;
        break;
    case 0xCD:
        PrintMultipleOperands("CALL", opcode, 3);
        opBytes = 3;
        break;
    case 0xCE:
        PrintMultipleOperands("ACI", opcode, 2);
        opBytes = 2;
        break;
    case 0xCF:
        PrintOpcodeReg("RST", "1", opcode[0]);
        break;
    case 0xD0:
        PrintOpcode("RNC", opcode[0]);
        break;
    case 0xD1:
        PrintOpcodeReg("POP", "D", opcode[0]);
        break;
    case 0xD2:
        PrintMultipleOperands("JNC", opcode, 3);
        opBytes = 3;
        break;
    case 0xD3:
        PrintMultipleOperands("OUT", opcode, 2);
        printf("OUT $%02x", opcode[1]);
        opBytes = 2;
        break;
    case 0xD4:
        PrintMultipleOperands("CNC", opcode, 3);
        opBytes = 3;
        break;
    case 0xD5:
        PrintOpcodeReg("PUSH", "D", opcode[0]);
        break;
    case 0xD6:
        PrintMultipleOperands("SUI", opcode, 2);
        opBytes = 2;
        break;
    case 0xD7:
        PrintOpcodeReg("RST", "2", opcode[0]);
        break;
    case 0xD8:
        PrintOpcode("RC", opcode[0]);
        break;
    case 0xD9:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0xDA:
        PrintMultipleOperands("JC", opcode, 3);
        opBytes = 3;
        break;
    case 0xDB:
        PrintMultipleOperands("IN", opcode, 2);
        opBytes = 2;
        break;
    case 0xDC:
        PrintMultipleOperands("CC", opcode, 2);
        opBytes = 3;
        break;
    case 0xDD:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0xDE:
        PrintMultipleOperands("SBI", opcode, 2);
        opBytes = 2;
        break;
    case 0xDF:
        PrintOpcodeReg("RST", "3", opcode[0]);
        break;
    case 0xE0:
        PrintOpcode("RPO", opcode[0]);
        break;
    case 0xE1:
        PrintOpcodeReg("POP", "H", opcode[0]);
        break;
    case 0xE2:
        PrintMultipleOperands("JPO", opcode, 3);
        opBytes = 3;
        break;
    case 0xE3:
        PrintOpcode("XTHL", opcode[0]);
        break;
    case 0xE4:
        PrintMultipleOperands("CPO", opcode, 3);
        opBytes = 3;
        break;
    case 0xE5:
        PrintOpcodeReg("PUSH", "H", opcode[0]);
        break;
    case 0xE6:
        PrintMultipleOperands("ANI", opcode, 2);
        opBytes = 2;
        break;
    case 0xE7:
        PrintOpcodeReg("RST", "4", opcode[0]);
        break;
    case 0xE8:
        PrintOpcode("RPE", opcode[0]);
        break;
    case 0xE9:
        PrintOpcode("PCHL", opcode[0]);
        break;
    case 0xEA:
        PrintMultipleOperands("JPE", opcode, 3);
        opBytes = 3;
        break;
    case 0xEB:
        PrintOpcode("XCHG", opcode[0]);
        break;
    case 0xEC:
        PrintMultipleOperands("CPE", opcode, 3);
        opBytes = 3;
        break;
    case 0xED:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0xEE:
        PrintMultipleOperands("XRI", opcode, 2);
        opBytes = 2;
        break;
    case 0xEF:
        PrintOpcodeReg("RST", "5", opcode[0]);
        break;
    case 0xF0:
        PrintOpcode("RP", opcode[0]);
        break;
    case 0xF1:
        PrintOpcodeReg("POP", "PSW", opcode[0]);
        break;
    case 0xF2:
        PrintMultipleOperands("JP", opcode, 3);
        opBytes = 3;
        break;
    case 0xF3:
        PrintOpcode("DI", opcode[0]);
        break;
    case 0xF4:
        PrintMultipleOperands("CP", opcode, 3);
        opBytes = 3;
        break;
    case 0xF5:
        PrintOpcodeReg("PUSH", "PSW", opcode[0]);
        break;
    case 0xF6:
        PrintMultipleOperands("OR!", opcode, 2);
        opBytes = 2;
        break;
    case 0xF7:
        PrintOpcodeReg("RST", "6", opcode[0]);
        break;
    case 0xF8:
        PrintOpcode("RM", opcode[0]);
        break;
    case 0xF9:
        PrintOpcode("SPHL", opcode[0]);
        break;
    case 0xFA:
        PrintMultipleOperands("JM", opcode, 3);
        opBytes = 3;
        break;
    case 0xFB:
        PrintOpcode("EI", opcode[0]);
        break;
    case 0xFC:
        PrintMultipleOperands("CM", opcode, 3);
        opBytes = 3;
        break;
    case 0xFD:
        PrintOpcode("NOP", opcode[0]);
        break;
    case 0xFE:
        PrintMultipleOperands("CPI", opcode, 2);
        opBytes = 2;
        break;
    case 0xFF:
        PrintOpcodeReg("RST", "7", opcode[0]);
        break;
    default:
        PrintOpcode(UNDEFINED_OP_CODE, opcode[0]);
        break;
    }

    printf("\n");
    return opBytes;
}

void PrintHexBuffer(const unsigned char* buffer, size_t buflen)
{
    size_t i;
    for (i = 0; i < buflen; i++) {
        printf("%02x", buffer[i]);
        if (i % 16 == 15)
            putchar('\n');
        else if (i % 2 == 1)
            putchar(' ');
    }
    
    if (i % 16 == 0)
        putchar('\n');
}

void ReadFile(State8080* state, const char* filename, uint32_t offset)
{
    FILE* fp = fopen(filename, "r+b");

    if (fp == NULL) {
        printf("ERROR: Could not open [%s]", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    rewind(fp);

    uint8_t* buf = &state->memory[offset];
    fread(buf, filesize, 1, fp);
    fclose(fp);
}

void PrintOpcode(const char* opcodeStr, const unsigned char opcode)
{
    printf("%02x\t\t\t\t\t%s\t\t\t", opcode, opcodeStr);
}

void PrintOpcodeReg(const char* opcodeStr, const char* reg, const unsigned char opcode)
{
    printf("%02x\t\t\t\t\t%s\t\t\t%s", opcode, opcodeStr, reg);
}

void PrintMultipleOperands(const char* opcodeStr, const unsigned char* opcodes, int opCount)
{
    if (opCount == 2) {
        printf("%02x %02x\t\t\t\t%s\t\t\t$%02x", opcodes[0], opcodes[1], opcodeStr, opcodes[1]);
    } else if (opCount == 3) {
        printf("%02x %02x %02x\t\t%s\t\t\t$%02x%02x", opcodes[0], opcodes[1], opcodes[2], opcodeStr, opcodes[2], opcodes[1]);
    }
}

void PrintRegMultipleOperands(const char* opcodeStr, const unsigned char* reg, const unsigned char* opcodes, int opCount)
{
    if (opCount == 2) {
        printf("%02x %02x\t\t\t\t%s\t\t\t%s, $%02x", opcodes[0], opcodes[1], opcodeStr, reg, opcodes[1]);
    } else if (opCount == 3) {
        printf("%02x %02x %02x\t\t%s\t\t\t%s, $%02x%02x", opcodes[0], opcodes[1], opcodes[2], opcodeStr, reg, opcodes[2], opcodes[1]);
    }
}