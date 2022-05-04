#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"

int main(int argc, char** argv)
{
    int running = 1;
    State8080* state = Init8080(ROM_OFFSET, &InvadersIn, &InvadersOut);
    InvaderWindow* mainWindow = InitInvaderWindow();
    
    if (mainWindow == 0x0) {
        fprintf(stderr, "Error initializing space invaders window\n");
        exit(-1);  
    }  

    InitGamePorts();
    
    LoadSpaceInvaders(state);
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
    free(state->memory.base);
    free(state);

    return 0;
}