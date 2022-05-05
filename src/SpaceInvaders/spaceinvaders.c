#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>

#include "SpaceInvaders/spaceinvaders.h"

static PortIO gamePorts;

int main() 
{
    State8080* state = Init8080(ROM_OFFSET, &InvadersIn, &InvadersOut);
    InvaderWindow* mainWindow = InitInvaderWindow();
    
    if (mainWindow->window == 0x0) {
        fprintf(stderr, "Error initializing space invaders window\n");
        exit(-1);  
    }  

    gamePorts.port0 = 0x0E;
    gamePorts.port1 = 0x09;
    gamePorts.port2 = 0x03;

    if (mainWindow->surface->format->format != SDL_PIXELFORMAT_RGB888) {
        fprintf(stderr, "Window is not using SDL_PIXELFORMAT_RGB888");
    }

    int romfd = LoadSpaceInvaders(state);
    
    uint32_t* pixels = mainWindow->surface->pixels;
    for (uint32_t y = 0; y < WINDOW_HEIGHT; y++) {
        for (uint32_t x = 0; x < WINDOW_WIDTH; x++) {
            SetPixel(pixels, x, y, 1);
        }
    }
    
    SDL_UpdateWindowSurface(mainWindow->window);
    mainWindow->vRAMTimer = SDL_AddTimer(VRAM_DELAY, UpdateVRAM, NULL);

    while (!mainWindow->quit) {
        if (!state->halt && ExecuteInstruction(state) == 1) {

        } else {
            state->halt = 1;
        }

        if (SDL_PollEvent(&(mainWindow->event))) {
            InvaderEventHandler(state, mainWindow);
        }
    }

    DestroyWindow(mainWindow);
    close(romfd);
    free(state->memory.base);
    free(state);

    return 0;
}

int LoadSpaceInvaders(State8080* state)
{
    int fd;
    PrepareROM(state);

    if ((fd = open("ROM/invaders", O_RDONLY)) == -1) {
        fprintf(stderr, "Error opening invaders rom\n");
        return 0;
    }

    state->memory.base = aligned_alloc(1<<16, 65535);
    if (read(fd, state->memory.base + ROM_OFFSET, state->ROMSize) == 0) {
        fprintf(stderr, "Unable to load ROM into memory\n");
        return 0;
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

InvaderWindow* InitInvaderWindow()
{
    // Initialize space for window
    InvaderWindow* mainWindow = (InvaderWindow*)calloc(1, sizeof(InvaderWindow));

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "Error: Could not initialize SDL - %s\n", SDL_GetError());
        return 0x0;
    }

    mainWindow->window = SDL_CreateWindow("Space Invaders", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        WINDOW_HEIGHT, WINDOW_WIDTH, 0); // No flags for now

    if (!mainWindow->window) {
        fprintf(stderr, "Error: Could not intialize main window - %s\n", SDL_GetError());
        SDL_Quit();
        return 0x0;
    }

    mainWindow->surface = SDL_GetWindowSurface(mainWindow->window);
    if (mainWindow->surface == NULL) {
        fprintf(stderr, "Error: Could not initialize window surface - %s\n", SDL_GetError());
        exit(-1);
    }

    mainWindow->pixels = mainWindow->surface->pixels;
    return mainWindow;
}

void InvadersInputHandler(SDL_KeyboardEvent event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.keysym.sym) {
        case SDLK_c: // coin in
            gamePorts.port1 |= 1;
            break;
        case SDLK_s: // P1 Start
            gamePorts.port1 |= 1 << 2;
            break;
        case SDLK_w: // P1 Shoot
            gamePorts.port1 |= 1 << 4;
            break;
        case SDLK_a: // P1 Left
            gamePorts.port1 |= 1 << 5;
            break;
        case SDLK_d: // P1 Right
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
        default:
            break;
        }
    } else {
        switch (event.keysym.sym) {
        case SDLK_c: // coin in
            gamePorts.port1 &= ~(1);
            break;
        case SDLK_s: // P1 Start
            gamePorts.port1 &= ~(1 << 2);
            break;
        case SDLK_w: // P1 Shoot
            gamePorts.port1 &= ~(1 << 4);
            break;
        case SDLK_a: // P1 Left
            gamePorts.port1 &= ~(1 << 5);
            break;
        case SDLK_d: // P1 Right
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
        default:
            break;
        }
    }
    fprintf(stderr, "GamePorts after: %d | %d\n", gamePorts.port1, gamePorts.port2);
}

void InvaderEventHandler(State8080* state, InvaderWindow* window)
{
    switch (window->event.type) {
    case SDL_QUIT:
        window->quit = 1;
        break;
    case SDL_USEREVENT:
        if (window->event.user.code == 0) {
            state->int_pend |= (uintptr_t)(window->event.user.data1);

            // Update app window for every full update
            if ((uintptr_t)(window->event.user.data1) == FULL_2) {
                DrawVideoRAM(state, window->pixels);
                SDL_UpdateWindowSurface(window->window);
            }
        }

        break;
    case SDL_KEYDOWN:
        fprintf(stderr, "Key [%c] pressed, isfake %X\n", window->event.key.keysym.sym, window->event.key.repeat);
        if (!window->event.key.repeat) {
            InvadersInputHandler(window->event.key);
        }

        break;
    case SDL_KEYUP:
        fprintf(stderr, "Key: %c realeased\n", window->event.key.keysym.sym);
        InvadersInputHandler(window->event.key);
        break;
    default:
        fprintf(stderr, "Unhandled Event type: %X\n", window->event.type);
    }
}

uint8_t InvadersIn(uint8_t port)
{
    // fprintf(stderr, "Invaders IN - Port: %X\n", port);
    switch (port) {
    case 0:
        return gamePorts.port0;
    case 1:
        return gamePorts.port1;
    case 2:
        return gamePorts.port2;
    case 3:
        assert(gamePorts.shiftConfig <= 7);
        uint8_t tmp = (uint8_t)((gamePorts.hiddenReg) >> (8 - gamePorts.shiftConfig));
        return tmp;
    default:
        fprintf(stderr, "UNKNOWN PORT: %X", port);
        exit(-1);
    }
    return 0;
}

void InvadersOut(uint8_t port, uint8_t data)
{
    // fprintf(stderr, "Invaders OUT - Port: %X, Data: %X\n", port, data);
    switch (port) {
    case 2:
        assert(data <= 7);
        gamePorts.shiftConfig = data;
        break;
    case 3:
        gamePorts.port3 = data;
        break;
    case 4:
        gamePorts.y = gamePorts.x;
        gamePorts.x = data;
        break;
    case 5:
        gamePorts.port5 = data;
        break;
    case 6:
        break;
    default:
        fprintf(stderr, "UNKNOWN PORT: %X", port);
        exit(-1);
    }
}

void SetPixel(uint32_t* pix, uint32_t x, uint32_t y, uint8_t state)
{
    pix[x + y * WINDOW_WIDTH] = state ? PIX_GREEN : PIX_BLACK;
}

void DrawVideoRAM(State8080* state, uint32_t* pixels)
{
    uint32_t index = 0;
    uintptr_t vramStart = (uintptr_t)MemRef(&state->memory, VRAM_OFFSET);
    uintptr_t vramEnd = vramStart + VRAM_SIZE;
    uint8_t vramData;

    static uint32_t temp[WINDOW_WIDTH * WINDOW_HEIGHT];
    for (; vramStart < vramEnd; vramStart++) {
        vramData = *(uint8_t*)(vramStart);
        temp[index++] = (vramData & 0x1) ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x2) >> 1 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x4) >> 2 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x8) >> 3 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x16) >> 4 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x32) >> 5 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x64) >> 6 ? PIX_GREEN : PIX_BLACK;
        temp[index++] = (vramData & 0x128) >> 7 ? PIX_GREEN : PIX_BLACK;
    }

    // Rotation moment
    index = 0;
    for (int16_t x = (WINDOW_WIDTH - 1); x >= 0; x--) {
        for (uint16_t y = 0; y < WINDOW_HEIGHT; y++) {
            pixels[index++] = temp[x + (y * WINDOW_WIDTH)];
        }
    }
}

uint32_t UpdateVRAM(uint32_t interval, UNUSED void* param)
{
    static uintptr_t updateState = HALF_1;

    SDL_Event event;
    SDL_UserEvent uEvent;

    uEvent.type = SDL_USEREVENT;
    uEvent.code = 0;
    uEvent.data1 = (void*)updateState;

    event.type = SDL_USEREVENT;
    event.user = uEvent;

    SDL_PushEvent(&event);

    updateState = (updateState == HALF_1) ? FULL_2 : HALF_1;

    return(interval);
}

void DestroyWindow(InvaderWindow* window)
{
    SDL_DestroyWindow(window->window);
    free(window);
    SDL_Quit();
}