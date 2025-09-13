#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define MEMORY_SIZE (1024 * 64) // 64KB

typedef struct mem {
    uint16_t size;
} Memory_type_t;

uint16_t* memory_initialize(Memory_type_t*);


#endif