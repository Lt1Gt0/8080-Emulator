#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"

int main(int argc, char** argv)
{
    int running = 1;
    State8080* state = Init8080(ROM_OFFSET, &InvadersIn, &InvadersOut);
    LoadSpaceInvaders(state);

    while (running) {
        if (!state->halt && ExecuteInstruction(state) == 1) {

        } else {
            state->halt = 1;
            running = 0;
        }        
    }
    return 0;
}