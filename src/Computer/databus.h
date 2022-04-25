#pragma once
#ifndef __DATA_BUS_H
#define __DATA_BUS_H

#include <stdint.h>


/**
 * D0 (INTA*)
 * Aknowledge interrupt signal request.
 * Signal should be used to gate a RST instruction onto
 * the databus when DBIN is active
 * ----------
 * D1 (WO (inverse))
 * Indicates that the operation in the current machine cycle 
 * will be a WRITE memory or OUTPUT function (WO (inverse) = 0).
 * Otherwise a READ memory or INPUT operation will execute
 * ----------
 * D2 (STACK)
 * Indicates the address bus holds the pushdown stack address
 * from the Stack Pointer
 * ----------
 * D3 (HLTA)
 * Aknowledge signal for HALT instruction
 * ----------
 * D4 (OUT)
 * Indicates the address bus contains the address of an output device
 * and the data bus will contain output data
 * when WR(inverse) is active
 * ----------
 * D5 (M1)
 * Provides a signal to indicate that the CPU is in
 * the fetch cycle for the first byte of an instruction
 * ----------
 * D6 (INP*)
 * Indicates that the address bus contains the address
 * of an input device and the input data should be place
 * on the data bus when DBIN is active
 * ----------
 * D7 (MEMR*)
 * Designates that the data bus will be used for 
 * memory read data
 */
typedef struct DataBus {
    uint8_t D0 : 1;
    uint8_t D1 : 1;    
    uint8_t D2 : 1;    
    uint8_t D3 : 1;    
    uint8_t D4 : 1;    
    uint8_t D5 : 1;    
    uint8_t D6 : 1;    
    uint8_t D7 : 1;    
}DataBus;

#endif // __DATA_BUS_H