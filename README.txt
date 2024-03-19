# Simulating Process Control Blocks with C

Implementing the destroy and create child of process control blocks

## Core features
1. Create(PCB), adds a new PCB to the Manager’s array
2. Destroy(Manager[0]), Destroys all descendants of 0, but doesn’t destroy 0 itself

## Details

I decided to implement the PCB array, using an array of pointers to PCBs. Each
PCB has a linked list to all its children. Create a new PCB, requires you to pass in which parent
is creating the new PCB so that the new PCB’s parent can be assigned. Destroying a PCB
destroys everything but the caller itself. So DestroyManager makes sure everything is deleted
when the program terminates. When you print all the PCBs, it also prints the children of the
CPB indicated by an indentation and “->” in the terminal screenshot. 

## Use

- Compile with Make
- run with ./pcb_simul