/**
 * @file main.c Main emulator file
 * @author Edwin Mwiti
*/

#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "types.h"
#include "memory-map.h"
#include "cpu.h"

int main() {
    CPU_type_t cpu_6502; // cpu instance
    Memory_type_t c_mem; // some memory

    CPU_type_t* p_6502 = &cpu_6502;
    Memory_type_t* p_mem = & c_mem;

    /*
     * initialize
     * I am initializing the memory separately because memory is not a part of the CPU
     * alternatively we could have stored a memory object in the CPU and set it to zero on
     * CPU reset but this is not a standard implementation since memory is outside the
     * CPU
     */
    cpu_reset(p_6502);
    uint16_t* m = memory_initialize(p_mem);

    // simple program

    m[0xFFFC] = 0xA9;
    m[0xFFFD] = 0x34;

    // end simple program


    return 0;
}
