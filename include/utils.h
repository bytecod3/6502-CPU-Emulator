/**
* @file utils.h
 * @brief creates general utility functions
 * @author Edwin
 *
*/

#ifndef UTILS_H
#define UTILS_H

#include "cpu.h"

/**
 * @brief This function returns the opcode as a string
 * @param code opcode to convert to string
 * @return opcode as string - for debugging
 */
const char* cpu_opcode_to_str(Opcode code);

/**
 * @brief This function returns the addressing mode as a string
 * @param addr_mode addressing mode to convert to string
 * @return addressing mode as string - for debugging
 */
const char* cpu_addressing_mode_to_str(Addressing_mode addr_mode);

#endif

