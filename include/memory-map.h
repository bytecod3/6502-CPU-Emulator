/**
 * @file memory-map.h
 * @brief needed declarations for memory stuff
 * @author Edwin
 * @email emwiti658@gmail.com
 */


#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE (1024 * 64) // 64KB

typedef struct mem {
    uint32_t size;
} Memory_type_t;

uint16_t* memory_initialize(Memory_type_t*);


#endif