#include "pcb.h"
#include <stdio.h>


int main( ) {

    // create a dynamic array of structs to store all the PCB processes from PCB[0] to PCB[n]
    //  made it a struct so I could include size attribute 
    struct PcbManager*  manager = CreatePcbManager();
    //FIRST PCB HAS Manager as PARENT, SO I PASS NULL AS PARRENT, State = Ready (enum)
    //create[0]     // create parent process 
    struct PCB* rootPcb = CreatePCB( manager, NULL, Ready);
    //create[1]     // creates 1st child of PCB[0] at PCB[1]
    struct PCB* pcbOne = CreatePCB( manager, rootPcb, Ready); 
    //create[2]     // creates 2nd child of PCB[0] at PCB[2]
    struct PCB* pcbTwo = CreatePCB( manager, rootPcb, Ready);
    //create[3]     // creates 1st child of PCB[2] at PCB[3] 
    struct PCB* pcbThree = CreatePCB( manager, pcbTwo, Ready);
    //create[4]     // creates 3rd child of PCB[0] at PCB[4] 
    struct PCB* pcbFour = CreatePCB( manager, rootPcb, Ready); 

    printf("PRINTING ALL PCB'S AND CHILDREN AFTER CREATION\n");
    PrintAllPcb( manager);

    DestroyPCB( rootPcb,manager);
    printf("CALLED DESTROY ON PCB[0] PRINTING WHAT'S LEFT\n");
    PrintAllPcb( manager);

    //free anything left in the manager array
    DestroyPcbManager( manager ); 
    //so compiler doesn't complain about unused variables
    pcbOne= NULL;
    pcbThree= NULL;
    pcbFour = NULL; 

    return 0; 
}