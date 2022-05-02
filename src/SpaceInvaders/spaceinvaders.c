#include "SpaceInvaders/spaceinvaders.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

static PortIO gamePorts;

int LoadSpaceInvaders(State8080* state)
{
    int fd;
    PrepareROM(state);

    if ((fd = open("ROM/invaders", O_RDONLY)) == -1) {
        fprintf(stderr, "Error opening invaders rom\n");
        exit(-1);
    }

    state->memory.base = aligned_alloc(1<<16, 65536);
    if (read(fd, state->memory.base + ROM_OFFSET, state->ROMSize) == 0) {
        fprintf(stderr, "Unable to load ROM into memory\n");
        exit(-1);
    }

    return fd;
}

void PrepareROM(State8080* state)
{
    FILE* FinalROM = fopen("ROM/invaders", "wb+");
    char* ROMFileNames[4] = {"ROM/invaders.h", "ROM/invaders.g", "ROM/invaders.f", "ROM/invaders.e"};
    FILE* fp;
    size_t filesize;
    unsigned char* buf;

    for (int i = 0; i < TOTAL_ROM_FILES; i++) {
        fp = fopen(ROMFileNames[i], "rb");

        if (fp == NULL) {
            fprintf(stderr, "ERROR: Could not open [%s]\nExiting...\n", ROMFileNames[i]);
            exit(-1);
        }

        fseek(fp, 0, SEEK_END);
        filesize = ftell(fp);
        rewind(fp);

        buf = (unsigned char*)malloc(sizeof(unsigned char) * filesize);
        fread(buf, filesize, 1, fp);

        fwrite(buf, filesize, sizeof(unsigned char), FinalROM);
    }

    fseek(FinalROM, 0, SEEK_END);
    state->ROMSize = ftell(FinalROM);
    rewind(FinalROM);
}

uint8_t InvadersIn(uint8_t port)
{
    switch (port) {
    case 0:
        return gamePorts.port0;
    case 1:
        return gamePorts.port1;
    case 2:
        return gamePorts.port2;
    case 3:
        assert(gamePorts.shiftConfig <= 7);

        uint8_t tmp = (uint8_t)(gamePorts.hiddenReg)>>(8 - gamePorts.shiftConfig);
        return tmp;
    default:
        fprintf(stderr, "UNKNOWN PORT: %X", port);
        exit(-1);
    }
    return 0;
}

void InvadersOut(uint8_t port, uint8_t data)
{
    fprintf(stdout, "Invaders OUT: Port: %X, Data: %X", port, data);
    switch (port) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        fprintf(stderr, "UNKNOWN PORT: %X", port);
        exit(-1);
    }
}