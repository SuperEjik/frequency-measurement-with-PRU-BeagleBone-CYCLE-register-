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
volatile unsigned int *pru0_dram = (unsigned int *) (PRU0_DRAM + 0x200);
//volatile double *pru0_dram = (double *) (PRU0_DRAM + 0x200);

//volatile register uint32_t __R30;
volatile register uint32_t __R31;

#define P8_15 (1 << 15)

void main(void)
{
    uint32_t cycle;
    uint32_t zero;
    int count=0;

    //CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

    while(__R31 & P8_15)
    {
    }

    while((__R31 & P8_15)==0)
    {
    }

    PRU0_CTRL.CTRL_bit.CTR_EN = 1;
    while (1)
    {
        //if(__R31 & P8_15)
        //{

        //while(count<1000)
        //{
            //PRU0_CTRL.CTRL_bit.CTR_EN = 1;
            PRU0_CTRL.CYCLE = zero;
            while(__R31 & P8_15)
            {
            }
            while((__R31 & P8_15)==0)
            {
            }
            cycle = PRU0_CTRL.CYCLE;
        //}
        //count=0;
        pru0_dram[2*0 ] = (cycle);
    }
}
