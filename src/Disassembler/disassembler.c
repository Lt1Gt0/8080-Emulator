#include "disassembler.h"

int DecodeInstruction(int* buffer, int pc)
{
    int code = *(buffer + pc);
    int opBytes = 1;
    fprintf(stderr, "OPCODE: %02x\n", code);
    char* opcodeStr;
    switch (code) {
    case 0x00: 
        opcodeStr = "NOP";
        break;
    case 0x01:
        opcodeStr = "";
        opBytes = 3;
        break;
    case 0x02:
        opcodeStr = "";
        break;
    case 0x03:
        opcodeStr = "";
        break;
    case 0x04:
        opcodeStr = "";
        break;
    case 0x05:
        opcodeStr = "";
        break;
    case 0x06:
        opcodeStr = "";
        break;
    case 0x07:
        opcodeStr = "";
        break;
    case 0x08:
        opcodeStr = "";
        break;
    case 0x09:
        opcodeStr = "";
        break;
    case 0x0A:
        opcodeStr = "";
        break;
    case 0x0B:
        opcodeStr = "";
        break;
    case 0x0C:
        opcodeStr = "";
        break;
    case 0x0D:
        opcodeStr = "";
        break;
    case 0x0E:
        opcodeStr = "";
        break;
    case 0x0F:
        opcodeStr = "";
        break;
    case 0x10:
        opcodeStr = "";
        break;
    case 0x11:
        opcodeStr = "";
        break;
    case 0x12:
        opcodeStr = "";
        break;
    case 0x13: 
        opcodeStr = "";
        break;
    case 0x14:
        opcodeStr = "";
        break;
    case 0x15:
        opcodeStr = "";
        break;
    case 0x16:
        opcodeStr = "";
        break;
    case 0x17:
        opcodeStr = "";
        break;
    case 0x18:
        opcodeStr = "";
        break;
    case 0x19:
        opcodeStr = "";
        break;
    case 0x1A:
        opcodeStr = "";
        break;
    case 0x1B:
        opcodeStr = "";
        break;
    case 0x1C:
        opcodeStr = "";
        break;
    case 0x1D:
        opcodeStr = "";
        break;
    case 0x1E:
        opcodeStr = "";
        break;
    case 0x1F:
        opcodeStr = "";
        break;
    case 0x20:
        opcodeStr = "";
        break;
    case 0x21:
        opcodeStr = "";
        break;
    case 0x22:
        opcodeStr = "";
        break;
    case 0x23:
        opcodeStr = "";
        break;
    case 0x24:
        opcodeStr = "";
        break;
    case 0x25:
        opcodeStr = "";
        break;
    case 0x26: 
        opcodeStr = "";
        break;
    case 0x27:
        opcodeStr = "";
        break;
    case 0x28:
        opcodeStr = "";
        break;
    case 0x29:
        opcodeStr = "";
        break;
    case 0x2A:
        opcodeStr = "";
        break;
    case 0x2B:
        opcodeStr = "";
        break;
    case 0x2C:
        opcodeStr = "";
        break;
    case 0x2D:
        opcodeStr = "";
        break;
    case 0x2E:
        opcodeStr = "";
        break;
    case 0x2F:
        opcodeStr = "";
        break;
    case 0x30:
        opcodeStr = "";
        break;
    case 0x31:
        opcodeStr = "";
        break;
    case 0x32:
        opcodeStr = "";
        break;
    case 0x33:
        opcodeStr = "";
        break;
    case 0x34:
        opcodeStr = "";
        break;
    case 0x35:
        opcodeStr = "";
        break;
    case 0x36:
        opcodeStr = "";
        break;
    case 0x37:
        opcodeStr = "";
        break;
    case 0x38:
        opcodeStr = "";
        break;
    case 0x39: 
        opcodeStr = "";
        break;
    case 0x3A:
        opcodeStr = "";
        break;
    case 0x3B:
        opcodeStr = "";
        break;
    case 0x3C:
        opcodeStr = "";
        break;
    case 0x3D:
        opcodeStr = "";
        break;
    case 0x3E:
        opcodeStr = "";
        break;
    case 0x3F:
        opcodeStr = "";
        break;
    case 0x40:
        opcodeStr = "";
        break;
    case 0x41:
        opcodeStr = "";
        break;
    case 0x42:
        opcodeStr = "";
        break;
    case 0x43:
        opcodeStr = "";
        break;
    case 0x44:
        opcodeStr = "";
        break;
    case 0x45:
        opcodeStr = "";
        break;
    case 0x46:
        opcodeStr = "";
        break;
    case 0x47:
        opcodeStr = "";
        break;
    case 0x48:
        opcodeStr = "";
        break;
    case 0x49:
        opcodeStr = "";
        break;
    case 0x4A:
        opcodeStr = "";
        break;
    case 0x4B:
        opcodeStr = "";
        break;
    case 0x4C: 
        opcodeStr = "";
        break;
    case 0x4D:
        opcodeStr = "";
        break;
    case 0x4E:
        opcodeStr = "";
        break;
    case 0x4F:
        opcodeStr = "";
        break;
    case 0x50:
        opcodeStr = "";
        break;
    case 0x51:
        opcodeStr = "";
        break;
    case 0x52:
        opcodeStr = "";
        break;
    case 0x53:
        opcodeStr = "";
        break;
    case 0x54:
        opcodeStr = "";
        break;
    case 0x55:
        opcodeStr = "";
        break;
    case 0x56:
        opcodeStr = "";
        break;
    case 0x57:
        opcodeStr = "";
        break;
    case 0x58:
        opcodeStr = "";
        break;
    case 0x59:
        opcodeStr = "";
        break;
    case 0x5A:
        opcodeStr = "";
        break;
    case 0x5B:
        opcodeStr = "";
        break;
    case 0x5C:
        opcodeStr = "";
        break;
    case 0x5D:
        opcodeStr = "";
        break;
    case 0x5E:
        opcodeStr = "";
        break;
    case 0x5F: 
        opcodeStr = "";
        break;
    case 0x60:
        opcodeStr = "";
        break;
    case 0x61:
        opcodeStr = "";
        break;
    case 0x62:
        opcodeStr = "";
        break;
    case 0x63:
        opcodeStr = "";
        break;
    case 0x64:
        opcodeStr = "";
        break;
    case 0x65:
        opcodeStr = "";
        break;
    case 0x66:
        opcodeStr = "";
        break;
    case 0x67:
        opcodeStr = "";
        break;
    case 0x68:
        opcodeStr = "";
        break;
    case 0x69:
        opcodeStr = "";
        break;
    case 0x6A:
        opcodeStr = "";
        break;
    case 0x6B:
        opcodeStr = "";
        break;
    case 0x6C:
        opcodeStr = "";
        break;
    case 0x6D:
        opcodeStr = "";
        break;
    case 0x6E:
        opcodeStr = "";
        break;
    case 0x6F:
        opcodeStr = "";
        break;
    case 0x70:
        opcodeStr = "";
        break;
    case 0x71:
        opcodeStr = "";
        break;
    case 0x72:
        opcodeStr = "";
        break;
    case 0x73:
        opcodeStr = "";
        break;
    case 0x74:
        opcodeStr = "";
        break;
    case 0x75:
        opcodeStr = "";
        break;
    case 0x76:
        opcodeStr = "";
        break;
    case 0x77:
        opcodeStr = "";
        break;
    case 0x78:
        opcodeStr = "";
        break;
    case 0x79:
        opcodeStr = "";
        break;
    case 0x7A:
        opcodeStr = "";
        break;
    case 0x7B:
        opcodeStr = "";
        break;
    case 0x7C:
        opcodeStr = "";
        break;
    case 0x7D:
        opcodeStr = "";
        break;
    case 0x7E:
        opcodeStr = "";
        break;
    case 0x7F:
        opcodeStr = "";
        break;
    case 0x80:
        opcodeStr = "";
        break;
    case 0x81:
        opcodeStr = "";
        break;
    case 0x82:
        opcodeStr = "";
        break;
    case 0x83:
        opcodeStr = "";
        break;
    case 0x84:
        opcodeStr = "";
        break;
    case 0x85:
        opcodeStr = "";
        break;
    case 0x86:
        opcodeStr = "";
        break;
    case 0x87:
        opcodeStr = "";
        break;
    case 0x88:
        opcodeStr = "";
        break;
    case 0x89:
        opcodeStr = "";
        break;
    case 0x8A:
        opcodeStr = "";
        break;
    case 0x8B:
        opcodeStr = "";
        break;
    case 0x8C:
        opcodeStr = "";
        break;
    case 0x8D:
        opcodeStr = "";
        break;
    case 0x8E:
        opcodeStr = "";
        break;
    case 0x8F:
        opcodeStr = "";
        break;
    case 0x90:
        opcodeStr = "";
        break;
    case 0x91:
        opcodeStr = "";
        break;
    case 0x92:
        opcodeStr = "";
        break;
    case 0x93:
        opcodeStr = "";
        break;
    case 0x94:
        opcodeStr = "";
        break;
    case 0x95:
        opcodeStr = "";
        break;
    case 0x96:
        opcodeStr = "";
        break;
    case 0x97:
        opcodeStr = "";
        break;
    case 0x98:
        opcodeStr = "";
        break;
    case 0x99:
        opcodeStr = "";
        break;
    case 0x9A:
       opcodeStr = "";
        break;
    case 0x9B:
        opcodeStr = "";
        break;
    case 0x9C:
        opcodeStr = "";
        break;
    case 0x9D:
        opcodeStr = "";
        break;
    case 0x9E:
        opcodeStr = "";
        break;
    case 0x9F:
        opcodeStr = "";
        break;
    case 0xA0:
        opcodeStr = "";
        break;
    case 0xA1:
        opcodeStr = "";
        break;
    case 0xA2:
        opcodeStr = "";
        break;
    case 0xA3:
        opcodeStr = "";
        break;
    case 0xA4:
        opcodeStr = "";
        break;
    case 0xA5:
        opcodeStr = "";
        break;
    case 0xA6:
        opcodeStr = "";
        break;
    case 0xA7:
        opcodeStr = "";
        break;
    case 0xA8:
        opcodeStr = "";
        break;
    case 0xA9:
        opcodeStr = "";
        break;
    case 0xAA:
        opcodeStr = "";
        break;
    case 0xAB:
        opcodeStr = "";
        break;
    case 0xAC:
        opcodeStr = "";
        break;
    case 0xAD:
        opcodeStr = "";
        break;
    case 0xAE:
        opcodeStr = "";
        break;
    case 0xAF:
        opcodeStr = "";
        break;
    case 0xB0:
        opcodeStr = "";
        break;
    case 0xB1:
        opcodeStr = "";
        break;
    case 0xB2:
        opcodeStr = "";
        break;
    case 0xB3:
        opcodeStr = "";
        break;
    case 0xB4:
        opcodeStr = "";
        break;
    case 0xB5:
        opcodeStr = "";
        break;
    case 0xB6:
        opcodeStr = "";
        break;
    case 0xB7:
        opcodeStr = "";
        break;
    case 0xB8:
        opcodeStr = "";
        break;
    case 0xB9:
        opcodeStr = "";
        break;
    case 0xBA:
        opcodeStr = "";
        break;
    case 0xBB:
        opcodeStr = "";
        break;
    case 0xBC:
        opcodeStr = "";
        break;
    case 0xBD:
        opcodeStr = "";
        break;
    case 0xBE:
        opcodeStr = "";
        break;
    case 0xBF:
        opcodeStr = "";
        break;
    case 0xC0:
        opcodeStr = "";
        break;
    case 0xC1:
        opcodeStr = "";
        break;
    case 0xC2:
        opcodeStr = "";
        break;
    case 0xC3:
        opcodeStr = "";
        break;
    case 0xC4:
        opcodeStr = "";
        break;
    case 0xC5:
        opcodeStr = "";
        break;
    case 0xC6:
        opcodeStr = "";
        break;
    case 0xC7:
        opcodeStr = "";
        break;
    case 0xC8:
        opcodeStr = "";
        break;
    case 0xC9:
        opcodeStr = "";
        break;
    case 0xCA:
        opcodeStr = "";
        break;
    case 0xCB:
        opcodeStr = "";
        break;
    case 0xCC:
        opcodeStr = "";
        break;
    case 0xCD:
        opcodeStr = "";
        break;
    case 0xCE:
        opcodeStr = "";
        break;
    case 0xCF:
        opcodeStr = "";
        break;
    case 0xD0:
        opcodeStr = "";
        break;
    case 0xD1:
        opcodeStr = "";
        break;
    case 0xD2:
        opcodeStr = "";
        break;
    case 0xD3:
        opcodeStr = "";
        break;
    case 0xD4:
        opcodeStr = "";
        break;
    case 0xD5:
        opcodeStr = "";
        break;
    case 0xD6:
        opcodeStr = "";
        break;
    case 0xD7:
        opcodeStr = "";
        break;
    case 0xD8:
        opcodeStr = "";
        break;
    case 0xD9:
        opcodeStr = "";
        break;
    case 0xDA:
        opcodeStr = "";
        break;
    case 0xDB:
        opcodeStr = "";
        break;
    case 0xDC:
        opcodeStr = "";
        break;
    case 0xDD:
        opcodeStr = "";
        break;
    case 0xDE:
        opcodeStr = "";
        break;
    case 0xDF:
        opcodeStr = "";
        break;
    case 0xE0:
        opcodeStr = "";
        break;
    case 0xE1:
        opcodeStr = "";
        break;
    case 0xE2:
        opcodeStr = "";
        break;
    case 0xE3:
        opcodeStr = "";
        break;
    case 0xE4:
        opcodeStr = "";
        break;
    case 0xE5:
        opcodeStr = "";
        break;
    case 0xE6:
        opcodeStr = "";
        break;
    case 0xE7:
        opcodeStr = "";
        break;
    case 0xE8:
        opcodeStr = "";
        break;
    case 0xE9:
        opcodeStr = "";
        break;
    case 0xEA:
        opcodeStr = "";
        break;
    case 0xEB:
        opcodeStr = "";
        break;
    case 0xEC:
        opcodeStr = "";
        break;
    case 0xED:
        opcodeStr = "";
        break;
    case 0xEE:
        opcodeStr = "";
        break;
    case 0xEF:
        opcodeStr = "";
        break;
    case 0xF0:
        opcodeStr = "";
        break;
    case 0xF1:
        opcodeStr = "";
        break;
    case 0xF2:
        opcodeStr = "";
        break;
    case 0xF3:
        opcodeStr = "";
        break;
    case 0xF4:
        opcodeStr = "";
        break;
    case 0xF5:
        opcodeStr = "";
        break;
    case 0xF6:
        opcodeStr = "";
        break;
    case 0xF7:
        opcodeStr = "";
        break;
    case 0xF8:
        opcodeStr = "";
        break;
    case 0xF9:
        opcodeStr = "";
        break;
    case 0xFA:
        opcodeStr = "";
        break;
    case 0xFB:
        opcodeStr = "";
        break;
    case 0xFC:
        opcodeStr = "";
        break;
    case 0xFD:
        opcodeStr = "";
        break;
    case 0xFE:
        opcodeStr = "";
        break;
    case 0xFF:
        opcodeStr = "";
        break;
    default:
        opcodeStr = UNDEFINED_OP_CODE;
        break;
    }


    printf("%s\n", opcodeStr);
    return opBytes;
}

void PrintHexBuffer(const int* buffer, size_t buflen)
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

unsigned int* ReadFileToHexBuffer(FILE* fp, size_t* filesize)
{
    unsigned int* buffer;
    size_t i;
    int c;

    fseek(fp, 0, SEEK_END);
    *filesize = ftell(fp);
    rewind(fp);

    buffer = (unsigned int*)malloc(sizeof(unsigned int) * (*filesize));
    for (i = 0; i < *filesize && (c = fgetc(fp)) != EOF; i++) {
        *(buffer + i) = c;
    }

    return buffer;
}


int main(int argc, char** argv)
{
    if (argc < 2) {
        printf("Invalid Argument Count\n");
        return -1;
    }

    FILE* fp = fopen(argv[1], "r+b");
    
    if (fp == NULL) {
        printf("Invalid File Input\n");
        fclose(fp);
        return -1;
    }
    
    size_t filesize;
    unsigned int* buffer = ReadFileToHexBuffer(fp, &filesize);
    // PrintHexBuffer(buffer, filesize);
    fclose(fp);
    
    int opBytes = 0;
    // while (buffer != NULL) {
    //     opBytes += DecodeInstruction(buffer, opBytes);
    //     buffer += opBytes;
    // }

    for (size_t i = 0; opBytes <= filesize; i++) {
        opBytes += DecodeInstruction(buffer, opBytes);
    }

    // int bufSize = 10;
    // int* buf = (int*)malloc(sizeof(int) * bufSize);

    // for (int i = 0; i < bufSize; i++) {
    //     *(buf + i) = i;
    // }
    
    // for (int i = 0; i < bufSize; i++) {
    //     printf("%d\n", *(buf + i));
    // }

    

    return 0;
}