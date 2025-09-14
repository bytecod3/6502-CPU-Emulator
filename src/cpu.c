#include "cpu.h"
#include "memory-map.h"
#include <stdint.h>

/**
 * store the reset memory addresses.
 * the stack will always reside in the address space of 0x0100 - 0x01FF
 * we only need to store the LSB since this address will always start with 0x01
 * Around 7 cycles are used to get the SP to 0xFF but since I am not
 * emulating a cycle accurate CPU, I jump to the final values of the registers
 * @param cpu
 */
void cpu_reset(CPU_type_t* cpu) {
    cpu->PC = 0xFFFC; // load PC with the reset
    cpu->SP = 0xFF;
    cpu->SR = 0x00;
    cpu->AC = 0x00;
    cpu->X = 0x00;
    cpu->Y = 0x00;
}

/**
 * fetch instruction from memory at the address pointed to by PC
 * effectively, increment the PC so it points to the next address
 * decrement the number of CPU cycles needed to fetch this instruction
 */
//void cpu_fetch_instruction(CPU_type_t* cpu) {
//    uint8_t opcode =
//}