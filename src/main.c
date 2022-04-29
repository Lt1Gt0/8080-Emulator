#include "8080/8080.h"
#include "8080/memory.h"
#include "SpaceInvaders/spaceinvaders.h"

int main(int argc, char** argv)
{
    State8080* state = Init8080();
    LoadSpaceInvaders(state);

    while (state->pc < state->ROMSize) {
        ExecuteInstruction(state);
    }

    return 0;
}