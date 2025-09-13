#include <stdint.h>
#include "types.h"

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
    status_register_t  SR;             /* status register */
    uint8_t SP;     /* stack pointer */
} CPU_type_t;

void cpu_reset(CPU_type_t*);

