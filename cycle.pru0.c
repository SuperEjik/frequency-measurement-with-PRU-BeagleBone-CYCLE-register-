// Access the CYCLE and STALL registers
#include <stdint.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <pru_iep.h>
#include <pru_ctrl.h>
#include "resource_table_empty.h"
#include "prugpio.h"
#include <time.h>

#define PRU0_DRAM       0x00000         // Offset to DRAM
// Skip the first 0x200 byte of DRAM since the Makefile allocates
// 0x100 for the STACK and 0x100 for the HEAP.
volatile unsigned int *pru0_dram = (unsigned int *) (PRU0_DRAM + 0x200);

volatile register uint32_t __R30;
volatile register uint32_t __R31;

#define P9_31 (1 << 0)
#define P8_15 (1 << 15)

void main(void)
{
    int i = 0;
    int t;

    uint32_t cycle;

    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

    //PRU0_CTRL.CTRL_bit.CTR_EN = 1;
    //PRU0_CTRL.CYCLE = cycle;

    while (1)
    {
        PRU0_CTRL.CTRL_bit.CTR_EN = 1;
        PRU0_CTRL.CYCLE = cycle;
        while(__R31 & P8_15)
        {
        }

        while((__R31 & P8_15)==0)
        {
        }

        cycle = PRU0_CTRL.CYCLE;
        pru0_dram[2*0 ] = 1000000/(cycle/200);
    }
}
