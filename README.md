Each PRU has a CYCLE register which counts the number of cycles since the PRU was enabled. They also have a STALL register that counts how many times the PRU stalled fetching an instruction. 

Running a Program and configuring Pins:
https://beagleboard.org/static/prucookbook/#_running_a_program_configuring_pins

Start program:

config-pin p8_15 pruin
make TARGET=cycle.pru0.c;
gcc out_test.c -o out_test
