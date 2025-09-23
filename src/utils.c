/**
* @file utils.c
 * @brief creates general utility functions
 * @author Edwin
*/

#include "utils.h"
#include "cpu.h"
#include "memory-map.h"

/**
 * @brief This function returns the opcode as a string
 * @param code opcode to convert to string
 * @return opcode as string - for debugging
 */
const char* cpu_opcode_to_str(Opcode code) {
    switch (code) {
        case ADC:
            return "ADC";    ///< add with carry
        case AND:
            return "AND";    ///< AND Memory with accumulator
        case ASL:
            return "ASL";    ///< shift one bit left
        case BCC:
            return "BCC";    ///< branch on carry clear
        case BCS:
            return "BCS";    ///< branch on carry set
        case BEQ:
            return "BEQ";    ///< branch on result zero
        case BIT:
            return "BIT";    ///< test memory bits with accumulator
        case BMI:
            return "BMI";    ///< branch on result minus
        case BNE:
            return "BNE";    ///< branch on result not zero
        case BPL:
            return "BPL";    ///< branch on result plus
        case BRA:
            return "BRA";    ///< branch always
        case BRK:
            return "BRK";    ///< force break
        case BVC:
            return "BVC";    ///< branch on overflow clear
        case BVS:
            return "BVS";    ///< branch on overflow set
        case CLC:
            return "CLC";    ///< clear carry flag
        case CLD:
            return "CLD";    ///< clear decimal mode
        case CLI:
            return "CLI";    ///< clear interrupt disable bit
        case CLV:
            return "CLV";    ///< clear overlow flag
        case CMP:
            return "CMP";    ///< compare memory and accumulator
        case CPX:
            return "CPX";    ///< compare memory and index X
        case CPY:
            return "CPY";    ///< compare memory and index Y
        case DEC:
            return "DEC";    ///< decrement by one
        case DEX:
            return "DEX";    ///< decrement index X by one
        case DEY:
            return "DEY";    ///< decrement index Y by one
        case EOR:
            return "EOR";    ///< Exclusive-or memory with accumulator
        case INC:
            return "INC";    ///< increment by one
        case INX:
            return "INX";    ///< increment index X by one
        case INY:
            return "INY";    ///< increment index Y by one
        case JMP:
            return "JMP";    ///< jump to new location
        case JSR:
            return "JSR";    ///< jump to new location saving return address
        case LDA:
            return "LDA";    ///< load accumulator with memory
        case LDX:
            return "LDX";    ///< load index X with memory
        case LDY:
            return "LDY";    ///< load index Y with memory
        case LSR:
            return "LSR";    ///< shift one bit right
        case NOP:
            return "NOP";    ///< no operation
        case ORA:
            return "ORA";    ///< OR memory with accumulator
        case PHA:
            return "PHA";    ///< push accumulator on stack
        case PHP:
            return "PHP";    ///< push processor status on stack
        case PHX:
            return "PHX";    ///< push index X on stack
        case PHY:
            return "PHY";    ///< push index Y on stack
        case PLA:
            return "PLA";    ///< pull accumulator from stack
        case PLP:
            return "PLP";    ///< pull processor status from stack
        case PLX:
            return "PLX";    ///< pull index Y from stack
        case PLY:
            return "PLY";    ///< pull index Y from stack
        case ROL:
            return "ROL";    ///< rotate one bit left
        case ROR:
            return "ROR";    ///< rotate one bit right
        case RTI:
            return "RTI";    ///< return from interrupt
        case RTS:
            return "RTS";    ///< return from subroutine
        case SBC:
            return "SBC";    ///< subtract memory from accumulator with borrow
        case SEC:
            return "SEC";    ///< set carry flag
        case SED:
            return "SED";    ///< set decimal mode
        case SEI:
            return "SEI";    ///< set interrupt disable bit
        case STA:
            return "STA";    ///< store accumulator in memory
        case STX:
            return "STX";    ///< store index X in memory
        case STY:
            return "STY";    ///< store index Y in memory
        case STZ:
            return "STZ";    ///< store zero in memory
        case STP:
            return "STP";
        case TAX:
            return "TAX";    ///< transfer accumulator to index X
        case TAY:
            return "TAY";    ///< transfer accumulator to index Y
        case TRB:
            return "TRB";    ///< test and reset memory bits with accumulator
        case TSB:
            return "TSB";    ///< test and set memory bits with accumulator
        case TSX:
            return "TSX";    ///< transfer stack pointer to index X
        case TXA:
            return "TXA";    ///< transfer index Y to accumulator
        case TXS:
            return "TXS";    ///< transfer index X to stack pointer
        case TYA:
            return "TYA";     ///< transfer index Y to accumulator
        case WAI:
            return "WAI";
        case INVLD:
            return "INVLD";   ///< invalid opcode
        case BBR0:
            return "BBR0";    ///< newer opcodes
        case BBR1:
            return "BBR1";
        case BBR2:
            return "BBR2";
        case BBR3:
            return "BBR3";
        case BBR4:
            return "BBR4";
        case BBR5:
            return "BBR5";
        case BBR6:
            return "BBR6";
        case BBR7:
            return "BBR7";
        case BBS0:
            return "BBS0";
        case BBS1:
            return "BBS1";
        case BBS2:
            return "BBS2";
        case BBS3:
            return "BBS3";
        case BBS4:
            return "BBS4";
        case BBS5:
            return "BBS5";
        case BBS6:
            return "BBS6";
        case BBS7:
            return "BBS7";
        case RMBO:
            return "RMBO";
        case RMB1:
            return "RMB1";
        case RMB2:
            return "RMB2";
        case RMB3:
            return "RMB3";
        case RMB4:
            return "RMB4";
        case RMB5:
            return "RMB5";
        case RMB6:
            return "RMB6";
        case RMB7:
            return "RMB7";
        case SMB0:
            return "SMB0";
        case SMB1:
            return "SMB1";
        case SMB2:
            return "SMB2";
        case SMB3:
            return "SMB3";
        case SMB4:
            return "SMB4";
        case SMB5:
            return "SMB5";
        case SMB6:
            return "SMB6";
        case SMB7:
            return "SMB7";
        default:
            return "OPCODE NOT FOUND";
    }
}

/**
 * @brief This function returns the addressing mode as a string
 * @param addr_mode addressing mode to convert to string
 * @return addressing mode as string - for debugging
 */
const char* cpu_addressing_mode_to_str(Addressing_mode addr_mode) {
    switch (addr_mode) {

        case ABS_A:
            return "Absolute a";                             /*!< a,  absolute */
        case ABS_INDX_IND:
            return "absolute indexed indirect (a,x)";         /*!< (a,x) absolute indexed indirect */
        case ABS_INDX_X:
            return "Absolute indexed with X a,x";             /*!< a,x absolute indexed with X */
        case ABS_INDX_Y:
            return "Absolute indexed with Y, a, y";           /*!< a,y absolute indexed with Y */
        case ABS_IND:
            return "Absolute indirect (a)";                   /*!< (a) absolute indirect */
        case ACC:
            return "Accumulator A";                           /*!< A accumulator */
        case IMM:
            return "Immediate #";                             /*!< # immediate */
        case IMP:
            return "Implied i";                               /*!< i implied */
        case PC_REL:
            return "Program counter relative r";              /*!< r program counter relative */
        case STK:
            return "Stack s";                                 /*!< s stack */
        case ZPG:
            return "Zero page zp";                            /*!< zp zero page */
        case ZPG_INDX_IND:
            return "Zero page indexed indirect (zp, x)";      /*!< (zp,x) zero page indexed indirect*/
        case ZPG_INDX_X:
            return "Zero page indexed with X, zp,x";          /*!< zp,x zero page indexed with X */
        case ZPG_INDX_Y:
            return "Zero page indexed with Y";                /*!< zp,y zero page indexed with Y */
        case ZPG_IND:
            return "Zero page indirect";                      /*!< (zp) zero page indirect */
        case ZPG_IND_INDX_Y:
            return "Zero page indirect indexed with Y";       /*!< (zp),y zero page indexed indirect with Y */
        case INV:
            return "Invalid adds mode";                      /*!< invalid mode */
        case II:
            return "Unknown mode II";                       // WHICH IS THIS?
    }
}
