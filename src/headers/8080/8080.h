#pragma once
#ifndef __8080_H
#define __8080_H

#include "cpu.h"

State8080* Init8080(uint16_t pc, uint8_t(*in)(uint8_t), void(*out)(uint8_t, uint8_t));
int ExecuteInstruction(State8080* state);

uint8_t ioIN(UNUSED uint8_t port);
void ioOUT(UNUSED uint8_t port, UNUSED uint8_t data);

#endif // __8080_H