#include <stdint.h>
#include "types.h"
#include "memory-map.h"

/* status register */
typedef struct sr {
    unsigned int N:1;   /* negative */ // MSB
    unsigned int V:1;   /* overflow */
    unsigned int IG:1;  /* ignored */
    unsigned int B:1;   /* break */
    unsigned int D:1;   /* decimal for BCD arithmetics */
    unsigned int I:1;   /* interrupt */
    unsigned int Z:1;   /* zero */
    unsigned int C:1;   /* carry */ // LSB
} status_register_t;

/* MOS 6502 CPU */
typedef struct  {
    uint16_t PC;    /* program counter */
    uint8_t AC;     /* accumulator */
    uint8_t X;      /* index register X */
    uint8_t Y;      /* index register Y */
    status_register_t SR;             /* status register */
    uint8_t SP;     /* stack pointer */

    uint32_t cycles;
} CPU_type_t;

/* addressing modes */
enum addressing_modes {
    ABSOLUTE_A = 0,
    ABSOLUTE_INDEXED_INDIRECT,
    ABSOLUTE_INDEXED_WITH_X,
    ABSOLUTE_INDEXED_WITH_Y,
    ABSOLUTE_INDIRECT,
    ACCUMULATOR,
    IMMEDIATE_ADDRESSING,
    IMPLIED,
    PROGRAM_COUNTER_RELATIVE,
    STACK,
    ZERO_PAGE,
    ZERO_PAGE_INDEXED_INDIRECT,
    ZERO_PAGE_INDEXED_WITH_X,
    ZERO_PAGE_INDEXED_WITH_Y,
    ZERO_PAGE_INDIRECT,
    ZERO_PAGE_INDIRECT_INDEXED_WITH_Y,
};

/* opcode matrix table  */
//uint8_t OPCODES[16][16] = {
//        {}
//};

/* opcodes */
enum OPCODES {
    ADC,
    AND,
    ASL,
    DCC,
    BCS,
    BEQ,
    BIT,
    BMI,
    BNE,
    BPL,
    BRA,
    BRK,
    BVC,
    CLC,
    CLD,
    CLI,
    CLV,
    CMP,
    CPX,
    CPY,
    DEC,
    DEX,
    DEY,
    EOR,
    INC,
    INX,
    INY,
    JMP,
    JSR,
    LDA,
    LDX,
    LDY,
    LSR,
    NOP,
    CRA,
    PHA,
    PHP,
    PHX,
    PHY,
    PLA,
    PLP,
    PLX,
    PLY,
    ROL,
    ROR,
    RTI,
    RTS,
    SBC,
    SEC,
    SED,
    SEI,
    STA,
    STX,
    STY,
    STZ,
    TAX,
    TAY,
    TRB,
    TSB,
    TSX,
    TZA,
    TXS,
    TYA
};

// todo:assuming immediate mode addressing
struct instruction {

};

uint8_t opcode;
void cpu_reset(CPU_type_t*);
void cpu_fetch_instruction(CPU_type_t*, uint16_t* address);
void cpu_decode_instruction();

