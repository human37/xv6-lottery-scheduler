# XV6 Operating System
xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern RISC-V multiprocessor using ANSI C.
I added a lottery ticket scheduler, in addition to the default 
"round-robin" schduler found on xv6. This lottery ticket scheduler
assigns every process a number of tickets, and then draws a ticket,
and the process that owns the winning ticket is the next process to run. 

# Building and Running XV6
You will need a RISC-V "newlib" tool chain from
https://github.com/riscv/riscv-gnu-toolchain, and qemu compiled for
riscv64-softmmu. Once they are installed, and in your shell
search path, you can run "make qemu".

# Testing the New Lottery Scheduler
For the default round-robin scheduler:

    $ make qemu 

For lottery scheduler and equal ticket number assignment:

    $ make qemu SCHEDPOLICY=RANDOM

For lottery scheduler and random ticket number assignment: 

    $ make qemu SCHEDPOLICY=RANDOM RANDOMTICKETNUMBER=RANDOMTICKETTRUE


