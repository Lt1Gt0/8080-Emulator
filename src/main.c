#include "8080/8080.h"
#include "8080/Disassembler/disassembler.h"
#include <stdint.h>

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
    unsigned char* buffer = ReadFileToHexBuffer(fp, &filesize);
    // PrintHexBuffer(buffer, filesize);
    
    State8080* state = Init8080();

    size_t progCount = 0;
    while (progCount < filesize) {
        // Emulate8080p(state);
        progCount += DecodeInstruction(buffer, progCount);
    }

    return 0;
}