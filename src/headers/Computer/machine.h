#pragma once
#ifndef __MACHINE_H
#define __MACHINE_H

#include <stdint.h>
#include "8080/structs.h"

uint8_t inb(State8080* state, uint8_t port);
void outb(State8080* state, uint8_t port);

#endif // __MACHINE_H