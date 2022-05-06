#pragma once
#ifndef __DEBUG_H
#define __DEBUG_H

#define DECOMPILE // Remove later 

#ifdef DECOMPILE
    #define PRINT_DECOMPILED( PC, fmt, args... ){ \
        fprintf(stdout, "%04X: ", PC);\
        fprintf(stdout, fmt, args);\
    }
#else 
    #define PRINT_DECOMPILED( ... ) do {} while (0);
#endif // DECOMPILE

#ifdef __8080_H
    #define PRINT_PROC_STATE(state) \
    { \
        fprintf(stdout, "\tC=%d, P=%d, Z=%d\n", state->PSW.cy, state->PSW.p, state->PSW.z); \
        fprintf(stdout, "\tA $%02X | BC $%04X | DE $%04X | HL $%04X | SP $%04X\n", \
            state->a, state->bc, state->de, state->hl, state->sp); \
    }
#else
    #define PRINT_PROC_STATE(args...) \
    { \
        fprintf(stdout, "Unable to print out proccessor state\n"); \
    }

#endif // __8080_H

#endif // __DEBUG_H