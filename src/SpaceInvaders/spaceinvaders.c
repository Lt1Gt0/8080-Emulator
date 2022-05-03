#include "SpaceInvaders/spaceinvaders.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

static PortIO gamePorts;
static InvaderWindow mainWindow;

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

int InitializeInvaderWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Error: Could not initialize SDL - %s\n", SDL_GetError());
        exit(-1);
    }

    mainWindow.window = SDL_CreateWindow("Space Invaders", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, 0); // No flags for now

    if (!mainWindow.window) {
        fprintf(stderr, "Error: Could not intialize main window - %s\n", SDL_GetError());
        exit(-1);
    }

    mainWindow.windowSurface = SDL_GetWindowSurface(mainWindow.window);

    if (!mainWindow.windowSurface) {
        fprintf(stderr, "Error: Could not initialize window surface - %s\n", SDL_GetError());
        exit(-1);
    }

    mainWindow.surface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_WIDTH, 32, 0, 0, 0, 0);

    return WINDOW_INIT_SUCCESS;
}

void InvaderInputHandler()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            exit(0);
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case 'c': // coin in
                gamePorts.port1 |= 1;
                break;
            case 's': // P1 Start
                gamePorts.port1 |= 1 << 2;
                break;
            case 'w': // P1 Shoot
                gamePorts.port1 |= 1 << 4;
                break;
            case 'a': // P1 Left
                gamePorts.port1 |= 1 << 5;
                break;
            case 'd': // P1 Right
                gamePorts.port1 |= 1 << 6;
                break;
            case SDLK_LEFT: // P2 Left
                gamePorts.port2 |= 1 << 5;
                break;
            case SDLK_RIGHT: // P2 Right
                gamePorts.port2 |= 1 << 6;
                break;
            case SDLK_RETURN: // P2 Start
                gamePorts.port1 |= 1 << 1;
                break;
            case SDLK_UP: // P2 Shoot
                gamePorts.port2 |= 1 << 4;
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
            case 'c': // coin in
                gamePorts.port1 &= ~(1);
                break;
            case 's': // P1 Start
                gamePorts.port1 &= ~(1 << 2);
                break;
            case 'w': // P1 Shoot
                gamePorts.port1 &= ~(1 << 4);
                break;
            case 'a': // P1 Left
                gamePorts.port1 &= ~(1 << 5);
                break;
            case 'd': // P1 Right
                gamePorts.port1 &= ~(1 << 6);
                break;
            case SDLK_LEFT: // P2 Left
                gamePorts.port2 &= ~(1 << 5);
                break;
            case SDLK_RIGHT: // P2 Right
                gamePorts.port2 &= ~(1 << 6);
                break;
            case SDLK_RETURN: // P2 Start
                gamePorts.port1 &= ~(1 << 1);
                break;
            case SDLK_UP: // P2 Shoot
                gamePorts.port2 &= ~(1 << 4);
                break;
            }
            break;
        default:
            break;
        }
    }
    return 0;
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