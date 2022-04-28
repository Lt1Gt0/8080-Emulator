#pragma once
#ifndef __DEBUG_H
#define __DEBUG_H

#ifdef __DECOMPILE_H
    #define PRINT_DECOMPILED(PC, fmt, args...) \
    { \
        fprintf(stdout, "%04x: ", PC);\
        fprintf(stdout, fmt, args); \
    }
#else 
    #define PRINT_DECOMPILED(...) do {} while (0);
#endif // __DECOMPILE_H

#ifdef __CPU8080_H
    #define PRINT_PROC_STATE(state) \
    { \
        fprintf(stdout, "\tC=%d, P=%d, Z=%d\n", state->cy, state->p, state->z); \
        fprintf(stdout, "\tA $%02x | BC $%04x | DE $%04x | HL $%04x | SP $%04x | PC %04x\n\n", \
            state->a, state->bc, state->de, state->hl, state->sp, state->pc); \
    }
#else
    #define PRINT_PROC_STATE(args...) \
    { \
        fprintf(stdout, "Unable to print out proccessor state"); \
    }

#endif // __CPU8080_H

#endif // __DEBUG_H