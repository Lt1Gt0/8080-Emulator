#pragma once
#ifndef __8080_H
#define __8080_H

#include "cpu.h"

State8080* Init8080();
int Emulate8080p(State8080* state);
int ExecuteInstruction(State8080* state);

#endif // __8080_H