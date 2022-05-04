#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"

int main(int argc, char** argv)
{
    int running = 1;
    State8080* state = Init8080(ROM_OFFSET, STACK_START, &InvadersIn, &InvadersOut);
    LoadSpaceInvaders(state);
    InvaderWindow* mainWindow = InitInvaderWindow();
    
    if (mainWindow == 0x0) {
        fprintf(stderr, "Error initializing space invaders window\n");
        exit(-1);  
    }  

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