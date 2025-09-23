/**
 * @file memory-map.h
 * @brief needed declarations for memory stuff
 * @author Edwin
 * @email emwiti658@gmail.com
 */


#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE (1024 * 64)             ///< 64KB in the MAX addressable memory
extern uint8_t HI_BYTE_MASK;                ///< for extracting the high byte
extern uint8_t LO_BYTE_MASK;                ///< for extracting the low byte

typedef struct mem {
    uint32_t size;
} Memory_type_t;

uint16_t* memory_initialize(Memory_type_t*);


#endif