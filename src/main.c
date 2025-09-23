/**
 * @file main.c Main emulator file
 * @author Edwin
 * @email emwiti658@gmail.com
*/

#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "types.h"
#include "memory-map.h"
#include "cpu.h"
#include "utils.h"

int main() {
    CPU_type_t cpu_6502; // cpu instance
    Memory_type_t c_mem; // some memory

    CPU_type_t* cpu_6502_ptr = &cpu_6502;
    Memory_type_t* mem_ptr = &c_mem;

    /*
     * initialize
     * I am initializing the memory separately because memory is not a part of the CPU
     * alternatively we could have stored a memory object in the CPU and set it to zero on
     * CPU reset but this is not a standard implementation since memory is outside the
     * CPU
     */
    cpu_reset(cpu_6502_ptr);
    uint16_t* m_ptr = memory_initialize(mem_ptr);

    printf("%d\n", cpu_6502_ptr->PC);

    // simple program
    m_ptr[0xFFFC] = 0xA9;
    m_ptr[0xFFFD] = 0x34;
    m_ptr[0xFFFE] = 0x5A;
    // end simple program

    // fetch opcode and addressing mode
    Instruction i;
    Instruction* instr_ptr = &i;
    cpu_fetch_instruction(cpu_6502_ptr, m_ptr, cpu_6502_ptr->PC, instr_ptr);

    puts("Fetched instruction from memory\n");
    printf("%s, %s\n", cpu_opcode_to_str(instr_ptr->opcode), cpu_addressing_mode_to_str(instr_ptr->addr_mode));


    return 0;
}
