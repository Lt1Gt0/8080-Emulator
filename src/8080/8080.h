#pragma once
#ifndef __8080_H
#define __8080_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "instuctions.h"

State8080* Init8080();

void UndefinedInstruction(State8080* state);
int Emulate8080p(State8080* state);

#endif // __8080_H