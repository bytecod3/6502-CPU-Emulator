/**
 * @file cpu.h
 * @brief creates needed header definitions for CPU
 * @author Edwin
 * @email emwiti658@gmail.com
 */

#include <stdint.h>
#include "types.h"
#include "memory-map.h"

/* status register bit masks */
#define N_MASK (1 << 7)
#define V_MASK (1 << 6)
#define IG_MASK (1 << 5)
#define B_MASK (1 << 4)
#define D_MASK (1 << 3)
#define I_MASK (1 << 2)
#define Z_MASK (1 << 1)
#define C_MASK (1 << 0)

/* 6502 CPU */
typedef struct  {
    uint16_t PC;    /* program counter */
    uint8_t AC;     /* accumulator */
    uint8_t X;      /* index register X */
    uint8_t Y;      /* index register Y */
    uint8_t SR;             /* status register */
    uint8_t SP;     /* stack pointer */

    uint32_t cycles;
} CPU_type_t;

/* addressing modes */
typedef enum addressing_modes {
    ABS_A,                          /*!< a,  absolute */
    ABS_INDX_IND,                    /*!< (a,x) absolute indexed indirect */
    ABS_INDX_X,                      /*!< a,x absolute indexed with X */
    ABS_INDX_Y,                      /*!< a,y absolute indexed with Y */
    ABS_IND,                        /*!< (a) absolute indirect */
    ACC,                             /*!< A accumulator */
    IMM,                           /*!< # immediate */
    IMP,                            /*!< i implied */
    PC_REL,                         /*!< r program counter relative */
    STK,                            /*!< s stack */
    ZPG,                           /*!< zp zero page */
    ZPG_INDX_IND,                  /*!< (zp,x) zero page indexed indirect*/
    ZPG_INDX_X,                         /*!< zp,x zero page indexed with X */
    ZPG_INDX_Y,                     /*!< zp,y zero page indexed with Y */
    ZPG_IND,                        /*!< (zp) zero page indirect */
    ZPG_IND_INDX_Y,                  /*!< (zp),y zero page indexed indirect with Y */
    INV,                             /*!< invalid mode */
    II              // WHICH IS THIS?
} Addressing_mode;

/*
 * @brief OpCodes
 * MOS6502 opcodes arranged alphabetically
 */
typedef enum OPCODES {
    ADC,    ///< add with carry
    AND,    ///< AND Memory with accumulator
    ASL,    ///< shift one bit left
    BCC,    ///< branch on carry clear
    BCS,    ///< branch on carry set
    BEQ,    ///< branch on result zero
    BIT,    ///< test memory bits with accumulator
    BMI,    ///< branch on result minus
    BNE,    ///< branch on result not zero
    BPL,    ///< branch on result plus
    BRA,    ///< branch always
    BRK,    ///< force break
    BVC,    ///< branch on overflow clear
    BVS,    ///< branch on overflow set
    CLC,    ///< clear carry flag
    CLD,    ///< clear decimal mode
    CLI,    ///< clear interrupt disable bit
    CLV,    ///< clear overlow flag
    CMP,    ///< compare memory and accumulator
    CPX,    ///< compare memory and index X
    CPY,    ///< compare memory and index Y
    DEC,    ///< decrement by one
    DEX,    ///< decrement index X by one
    DEY,    ///< decrement index Y by one
    EOR,    ///< Exclusive-or memory with accumulator
    INC,    ///< increment by one
    INX,    ///< increment index X by one
    INY,    ///< increment index Y by one
    JMP,    ///< jump to new location
    JSR,    ///< jump to new location saving return address
    LDA,    ///< load accumulator with memory
    LDX,    ///< load index X with memory
    LDY,    ///< load index Y with memory
    LSR,    ///< shift one bit right
    NOP,    ///< no operation
    ORA,    ///< OR memory with accumulator
    PHA,    ///< push accumulator on stack
    PHP,    ///< push processor status on stack
    PHX,    ///< push index X on stack
    PHY,    ///< push index Y on stack
    PLA,    ///< pull accumulator from stack
    PLP,    ///< pull processor status from stack
    PLX,    ///< pull index Y from stack
    PLY,    ///< pull index Y from stack
    ROL,    ///< rotate one bit left
    ROR,    ///< rotate one bit right
    RTI,    ///< return from interrupt
    RTS,    ///< return from subroutine
    SBC,    ///< subtract memory from accumulator with borrow
    SEC,    ///< set carry flag
    SED,    ///< set decimal mode
    SEI,    ///< set interrupt disable bit
    STA,    ///< store accumulator in memory
    STX,    ///< store index X in memory
    STY,    ///< store index Y in memory
    STZ,    ///< store zero in memory
    STP,
    TAX,    ///< transfer accumulator to index X
    TAY,    ///< transfer accumulator to index Y
    TRB,    ///< test and reset memory bits with accumulator
    TSB,    ///< test and set memory bits with accumulator
    TSX,    ///< transfer stack pointer to index X
    TXA,    ///< transfer index Y to accumulator
    TXS,    ///< transfer index X to stack pointer
    TYA,     ///< transfer index Y to accumulator
    WAI,
    INVLD,      ///< invalid opcode

    BBR0, ///< newer opcodes
    BBR1,
    BBR2,
    BBR3,
    BBR4,
    BBR5,
    BBR6,
    BBR7,
    BBS0,
    BBS1,
    BBS2,
    BBS3,
    BBS4,
    BBS5,
    BBS6,
    BBS7,
    RMBO,
    RMB1,
    RMB2,
    RMB3,
    RMB4,
    RMB5,
    RMB6,
    RMB7,
    SMB0,
    SMB1,
    SMB2,
    SMB3,
    SMB4,
    SMB5,
    SMB6,
    SMB7
} Opcode;

/**
 * @brief Instruction
 * An instruction is made up of the opcode and the
 */
typedef struct instruction {
    Opcode opcode;
    Addressing_mode addr_mode;
} Instruction;

Instruction instr;                      // to store the fetched instruction

/**
 * @brief addressing modes table
 * This table is a 16x16 array that stores the addressing mode for each instruction as defined
 * in the datasheet
 *
 * When an opcode is fetched from program memory, we cross-reference it with this table to find out
 * which addressing mode we are using
 *
 * The addressing mode will determine what the next byte fetched from memory represents
 *
 */
static Addressing_mode addressing_modes[16][16] = {
        /* HI/LOW               |      0            |       1         |        2          |       3      |         4      |   5             |     6              |     7     |      8           |      9     |          A           |     B      |       C      |            D    |            E     |         F       */
        /* 0 */                {STK,        ZPG_INDX_X,         INV,        INV,        ZPG,        ZPG,        ZPG,        ZPG,       STK,        IMM,        ACC,        INV,        ABS_A,      ABS_A,      ABS_A,          PC_REL },
        /* 1 */                 {PC_REL,    ZPG_INDX_Y,         ZPG,        INV,        ZPG,  ZPG_INDX_X,  ZPG_INDX_X,      ZPG,       IMP,        ABS_INDX_Y,  ACC,        INV,        ABS_A,      ABS_INDX_X, ABS_INDX_X,  PC_REL },
        /* 2 */                 {ABS_A,     ZPG_INDX_X,         INV,         INV,       ZPG,         ZPG,          ZPG,       ZPG,     STK,           IMM,      ACC,        INV,        ABS_A,       ABS_A,     ABS_A,         PC_REL },
        /* 3 */                 {PC_REL,    ZPG_INDX_Y,         ZPG,        INV,   ZPG_INDX_X,  ZPG_INDX_X,  ZPG_INDX_X,      ZPG,      II,     ABS_INDX_Y,       ACC,       INV,     ABS_INDX_X,   ABS_INDX_X, ABS_INDX_X,      PC_REL},
        /* 4 */                 {STK,      ZPG_INDX_X,         INV,        INV,          INV,         ZPG,        ZPG,        ZPG,     STK,          IMM,        ACC,       INV,       ABS_A,       ABS_A,        ABS_A,      PC_REL},
        /* 5 */                 {PC_REL,   ZPG_INDX_Y,          ZPG,        INV,         INV, ZPG_INDX_X, ZPG_INDX_X,         ZPG,     IMP,   ABS_INDX_Y,         STK,       INV,      ABS_IND,      ABS_A,      ABS_A,         PC_REL},
        /* 6 */                 {STK,      ZPG_INDX_X,          INV,        INV,        ZPG,        ZPG,        ZPG,        ZPG,       STK,          IMM,       ACC,        INV,      ABS_A,         ABS_A,       ABS_A,        PC_REL},
        /* 7 */                 {PC_REL,   ZPG_INDX_Y,          ZPG,        INV,  ZPG_INDX_X, ZPG_INDX_X, ZPG_INDX_X,       ZPG,       IMP,  ABS_INDX_Y,       STK,        INV,  ABS_INDX_X,    ABS_INDX_X, ABS_INDX_X,         PC_REL },
        /* 8 */                 {PC_REL,   ZPG_INDX_IND,          INV,      INV,        ZPG,         ZPG,        ZPG,       ZPG,       IMP,         IMM,       IMP,        INV,        ABS_A,       ABS_A,       ABS_A,          PC_REL },
        /* 9 */                 {PC_REL, ZPG_INDX_Y,          ZPG,        INV,   ZPG_INDX_X,  ZPG_INDX_X, ZPG_INDX_Y,       ZPG,       IMP,  ABS_INDX_Y,       IMP,        INV,         ACC,        ABS_A,        ABS_A,          PC_REL },
        /* A */                { IMM,    ZPG_INDX_Y,        ZPG,         IMM,          INV,         ZPG,        ZPG,       ZPG,        ZPG, IMP,            IMM,           IMP,         INV,        ACC,         ABS_A,         PC_REL },
        /* B */                 {PC_REL, ZPG_INDX_Y,        ZPG,         INV,    ZPG_INDX_X,  ZPG_INDX_X,  ZPG_INDX_Y,    ZPG,          IMP, ABS_INDX_Y,    IMP,            INV, ABS_INDX_X,   ABS_INDX_X,   ABS_INDX_Y,        PC_REL  },
        /* C */                {IMM,     ZPG_INDX_X,        INV,        INV,            ZPG,        ZPG,         ZPG,      ZPG,        IMP, IMM,            IMP,            II,      ABS_A,         ABS_A,        ABS_A,        PC_REL  },
        /* D */                {PC_REL,  ZPG_INDX_Y,        ZPG,        INV,            INV, ZPG_INDX_X,  ZPG_INDX_X,      ZPG,        IMP, ABS_INDX_Y,     STK,            II,         INV,    ABS_INDX_X,  ABS_INDX_Y,        PC_REL  },
        /* E */                {IMM,     ZPG_INDX_X,        INV,        INV,            ZPG,        ZPG,         ZPG,     ZPG,         IMP, IMM,            IMP,            INV,       ABS_A,       ABS_A,        ABS_A,        PC_REL },
        /* F */                { PC_REL, ZPG_INDX_Y,    ZPG_IND,        INV,            INV, ZPG_INDX_X,  ZPG_INDX_X,     ZPG,         IMP, ABS_INDX_Y,     STK,            INV,        INV,    ABS_INDX_X, ABS_INDX_X,         PC_REL }
};

/**
 * @brief this table stores the op codes in a 16x16 table
 */
static Opcode opcodes[16][16] = {
        /* HI/LOW   |   0  |               1   |              2   |            3    |          4           |   5           |   6    |          7   |           8  |            9   |           A    |          B      |               C            |     D     |    E  |               F       */
        /* 0 */ {BRK,       ORA,        INVLD,      INVLD,      TSB,        ORA,        ASL,        RMBO,       PHP,        ORA,        ASL,        INVLD,      TSB,        ORA,        ASL,        BBR0 },
        /* 1 */ {BPL,       ORA,        ORA,        INVLD,      TRB,        ORA,        ASL,        RMB1,       CLC,        ORA,        INC,        INVLD,      TRB,        ORA,        ASL,        BBR1 },
        /* 2 */ {JSR,       AND,        INVLD,      INVLD,      BIT,        AND,        ROL,        RMB2,       PLP,        AND,        ROL,        INVLD,      BIT,        AND,        ROL,        BBR2},
        /* 3 */ {BMI,       AND,        AND,        INVLD,      BIT,        AND,        ROL,        RMB3,       SEC,        AND,        DEC,        INVLD,      BIT,        AND,        ROL,        BBR2},
        /* 4 */ { RTI,      EOR,        INVLD,      INVLD,      INVLD,      EOR,        LSR,        RMB4,       PHA,        EOR,        LSR,        INVLD,      JMP,        EOR,        LSR,        BBR4 },
        /* 5 */ { BVC,      EOR,        EOR,        INVLD,      INVLD,      EOR,        LSR,        RMB5,       CLI,        EOR,        PHY,        INVLD,      INVLD,      EOR,        LSR,        BBR5 },
        /* 6 */ { RTS,      ADC,        INVLD,      INVLD,      STZ,        ADC,        ROR,        RMB6,       PLA,        ADC,        ROR,        INVLD,      JMP,        ADC,        ROR,        BBR6 },
        /* 7 */ { BVS,      ADC,        ADC,        INVLD,      STZ,        ADC,        ROR,        RMB7,       SEI,        ADC,        PLY,        INVLD,      JMP,        ADC,        ROR,        BBR7 },
        /* 8 */ { BRA,      STA,        INVLD,      INVLD,      STY,        STA,        STX,        SMB0,       DEY,        BIT,        TXA,        INVLD,      STY,        STA,        STX,        BBS0 },
        /* 9 */ { BCC,      STA,        STA,        INVLD,      STY,        STA,        STX,        SMB1,       TYA,        STA,        TXS,        INVLD,      STZ,        STA,        STZ,        BBS1 },
        /* A */ { LDY,      LDA,        LDX,        INVLD,      LDY,        LDA,        LDX,        SMB2,       TAY,        LDA,        TAX,        INVLD,      LDY,        LDA,        LDX,        BBS2 },
        /* B */ { BCS,      LDA,        LDA,        INVLD,      LDY,        LDA,        LDX,        SMB3,       CLV,        LDA,        TSX,        INVLD,      LDY,        LDA,        LDX,        BBS3 },
        /* C */ { CPY,      CMP,        INVLD,      INVLD,      CPY,        CMP,        DEC,        SMB4,       INY,        CMP,        DEX,        WAI,        CPY,        CMP,        DEC,        BBS4 },
        /* D */ { BNE,      CMP,        CMP,        INVLD,      INVLD,      CMP,        DEC,        SMB5,       CLD,        CMP,        PHX,        STP,        INVLD,      CMP,        DEC,        BBS5 },
        /* E */ { CPX,      SBC,        INVLD,      INVLD,      CPX,        SBC,        INC,        SMB6,       INX,        SBC,        NOP,        INVLD,      CPX,        SBC,        INC,        BBS6 },
        /* F */  { BEQ,         SBC,        SBC,    INVLD,      INVLD,      SBC,        INC,        SMB7,       SED,        SBC,        PLX,        INVLD,      INVLD,      SBC,        INC,        BBS7 }
};


/**
 * reset the CPU to after-reset register values
 * see datasheet
 */
void cpu_reset(CPU_type_t*);

/**
 * fetch instruction from memory at the address pointed to by PC
 * @param m memory
 * @param address address of the instruction in memory
 */
Instruction* cpu_fetch_instruction(CPU_type_t*, uint16_t* memory,  uint16_t address);

/**
 * @brief decodes instruction fetched from memory
 */
void cpu_decode_instruction();

