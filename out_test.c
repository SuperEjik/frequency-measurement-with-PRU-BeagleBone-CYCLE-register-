#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#include <unistd.h>
#define MAXCH 4

#define PRU_ADDR        0x4A300000      // Start of PRU memory Page 184 am335x TRM
#define PRU_LEN         0x80000         // Length of PRU memory
#define PRU0_DRAM       0x00000         // Offset to DRAM
#define PRU1_DRAM       0x02000
#define PRU_SHAREDMEM   0x10000         // Offset to shared memory

unsigned int    *pru0DRAM_32int_ptr;        // Points to the start of local DRAM
unsigned int    *pru1DRAM_32int_ptr;        // Points to the start of local DRAM
unsigned int    *prusharedMem_32int_ptr;    // Points to the start of the shared memory
unsigned int    *T;

int start_pwm_count(int ch, int countOn, int countOff) {
    unsigned int *pruDRAM_32int_ptr = pru0DRAM_32int_ptr;

    // write to PRU shared memory
    printf("\n");
    printf("%lf\n",1/(pruDRAM_32int_ptr[2*(ch)+0]*2.5*pow(10,-10)) );  // On time
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    //while(1){
    unsigned int    *pru;       // Points to start of PRU memory.
    int fd;
    int countF = 0;
    double F = 0.0;
    //while(countF < 1000)
    //{
    fd = open ("/dev/mem", O_RDWR | O_SYNC);
 if (fd == -1) {
        printf ("ERROR: could not open /dev/mem.\n\n");
        return 1;
    }
    pru = mmap (0, PRU_LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, PRU_ADDR);
    if (pru == MAP_FAILED) {
        printf ("ERROR: could not map memory.\n\n");
        return 1;
    }
    close(fd);
 pru0DRAM_32int_ptr =     pru + PRU0_DRAM/4 + 0x200/4;   // Points to 0x200 of PRU0 memory
    pru1DRAM_32int_ptr =     pru + PRU1_DRAM/4 + 0x200/4;   // Points to 0x200 of PRU1 memory
    prusharedMem_32int_ptr = pru + PRU_SHAREDMEM/4; // Points to start of shared memory

    int i;
    //start_pwm_count(i, i+1, 20-(i+1));

    unsigned int *pruDRAM_32int_ptr = pru0DRAM_32int_ptr;

    F = 1/(pruDRAM_32int_ptr[0]*49.83240366*pow(10,-10));

    //printf("\n");
    printf("%lf\n",F);
    //printf("%d\n",pruDRAM_32int_ptr[0]);
    //printf("\n");

    //countF++;
    //}
    //printf("\n");
    //printf("%lf\n",F/1000 );
    //printf("\n");

    /*printf("\n");
    printf("%lf\n",1/(pruDRAM_32int_ptr[0]*2.5*pow(10,-10)) );
    printf("\n");*/
    //sleep(1);
    //}
}
