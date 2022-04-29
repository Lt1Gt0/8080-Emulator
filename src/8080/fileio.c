#include "8080/fileio.h"
// #include <stdio.h>
// #include "memory.h"
// #include "SpaceInvaders/spaceinvaders.h"

/* MISC */
// void ReadFile(State8080* state, const char* filename, uint32_t offset)
// {
    // FILE* fp = fopen(filename, "r+b");

    // if (fp == NULL) {
        // printf("ERROR: Could not open [%s]", filename);
        // exit(1);
    // }

    // fseek(fp, 0, SEEK_END);
    // size_t filesize = ftell(fp);
    // rewind(fp);

    // state->memory.base = aligned_alloc(1<<16, 65536);
    // fread(buf, filesize, 1, fp);
    // fclose(fp);
// }