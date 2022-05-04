#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"

int main(int argc, char** argv)
{
    int running = 1;
    State8080* state = Init8080(ROM_OFFSET, STACK_START, &InvadersIn, &InvadersOut);
    LoadSpaceInvaders(state);

    if (InitializeInvaderWindow() != WINDOW_INIT_SUCCESS)
    {
        fprintf(stderr, "Error initializing space invaders window\n");
        exit(-1);  
    } 

    uint32_t prevTick = SDL_GetTicks();
    while (running) {
        if((SDL_GetTick() - prevTick) != TICK) {
            prevTick = SDL_GetTick();

            

            InvadersInputHandler();
            DrawVideoRAM(state);
        }
        // if (!state->halt && ExecuteInstruction(state) == 1) {

        // } else {
        //     state->halt = 1;
        //     running = 0;
        // }        
    }
    return 0;
}