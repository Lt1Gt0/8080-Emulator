#include "8080/8080.h"
#include "8080/opcodes.h"
#include "Debug/debug.h"
// #include "SpaceInvaders/spaceinvaders.h"

State8080* Init8080(uint16_t pc, uint8_t(*in)(uint8_t), void(*out)(uint8_t, uint8_t))
{
    State8080* state = (State8080*)calloc(1, sizeof(State8080));
    state->pc = pc;
    state->sp = 0xF000;

    state->ProcIN = (in == NULL) ? &ioIN : in;
    state->ProcOUT = (out == NULL) ? &ioOUT : out;

    return state;
}

int ExecuteInstruction(State8080* state)
{
    // Check for intterupt handler
    if (state->int_enable && state->int_pend) {
        state->int_enable = 0;
        uint8_t i = 0;
        for (uint16_t mask = 0x1; mask <= 0x8; mask <<= 1) {
            if (state->int_pend & mask) {
                uint8_t opcode = 0xC7 | (i << 3);
                state->int_pend &= (~mask);
                return RST(state, 0xFFFF, opcode);
            }
            i++;
        }
        abort();
    }

    uint8_t opcode = MemRead(&state->memory, state->pc);
    uint16_t prevPC = state->pc;
    state->pc += opcodeLookUp[opcode].size;

    int status = opcodeLookUp[opcode].targetFunc(state, prevPC, opcode);
    // state->cycles += opcodeLookUp[opcode].cycleCount;
    PRINT_PROC_STATE(state);

    return status;
}

uint8_t ioIN(UNUSED uint8_t port)
{
    fprintf(stderr, "UNIMPLEMENTED IN INSTRUCTION");
    return 0;
}

void ioOUT(UNUSED uint8_t port, UNUSED uint8_t data)
{
    fprintf(stderr, "UNIMPLEMENTED OUT INSTRUCTION");
    return;
}