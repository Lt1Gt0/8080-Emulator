#include "spaceinvaders.h"

int InitializeSpaceInvaders()
{   
    WindowInfo* winfo = {NULL};
    // For space invaders I need to initialize
    // SDL_INIT_VIDEO
    // SDL_INIT_TIMER
    // SDL_INIT_JOYSTICK (I think)
    // SDL_INIT_AUDIO (later)

    // If anything I could just run
    // SDL_INIT_EVERYTHING and hope it works

    if (SDL_Init(SDL_INIT_VIDEO) == -1) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(-1);
    }

    // SDL_SetVide()
    return 0;        
}