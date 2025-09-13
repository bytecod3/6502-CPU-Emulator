/**
 * @file memory.c
 * @author Edwin
 */

/**
 * 6502 can address a total of 64KB (65536 bytes) of memory
 * we need to allocate this memory to mimic the addressing space
 * of the CPU
 */

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "memory-map.h"

/**
 * create a memory area and initialize it to 0
 * @param m memory struct
 * @return pointer to the memory area
 */
uint16_t* memory_initialize(Memory_type_t* m) {
    m->size = MEMORY_SIZE;
    uint16_t* mem_ptr = (uint16_t*) malloc(m->size);

    if(mem_ptr != NULL) {
        memset(mem_ptr, 0, m->size);
    }

    return mem_ptr;
}