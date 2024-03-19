/*
The header file that list all the avilable methods for managing the Process control block simulation 
*/
#ifndef PCB_H
#define PCB_H



typedef enum Pcb_States {
    Ready =0 ,
    Blocked = 1,
    Running = 2
} PcbStates;

//defined in pcb.c in order to translate the enums from number to printable text  
extern const char* PcbStateNames[];

struct PcbManager {
    struct PCB** pcbarray;
    int size;
    int capacity;
};

struct PCB {
    int indexId;
    struct PCB * parent;
    struct ChildList * children;
    PcbStates state;
};

struct ChildList {
    struct ChildNode * head;  
    struct ChildNode * tail;
    int size;
};

struct ChildNode {
    struct ChildNode * next;
    struct ChildNode * prev;
    struct PCB* pcb;
};


/* This is to create the Manager to store the Manager of PCB processes from PCB[0] to PCB[n] */
struct PcbManager* CreatePcbManager();

/*adds PCB to the end of the array struct's PCBlist */
void AddPCBtoManager(  struct PcbManager* manager, struct PCB* pcb );

/* only should be called by CreatePCB, if the allocated list is more than the intial capacity of PCB[n]
   then createPCB calls this method which doubles the capacity of the Manager
*/
void ResizePcbManager( struct PcbManager* );

/*Free all the memory allocated to store the Manager of PCBs */
void DestroyPcbManager( struct PcbManager* Pcb );

/* This creates a new PCB. If argument passed is NULL, then the new PCB is the root PCB.
If a non null PCB is passed, then the new PCB returned is the child
The PCB parent passed will have an updated child list with the new PCB. 
*/
struct PCB* CreatePCB(struct PcbManager* manager, struct PCB *parent, PcbStates pcbstate );


/* helper function for create PCB,
 adds the newly created PCB (child) to the child list of the parent if it's not null */
void AddChildToPCB( struct PCB* parent, struct PCB* child);

/* for the parent PCB, it will recursively remove all the descendants and deallocate all the memory of each PCB */
void DestroyPCB( struct PCB *parent, struct PcbManager* manager);

/* loops through the Manager of PCB and calls print PCB for the PCB[n] and then for PCB[n]'s children*/
void PrintAllPcb( struct PcbManager * );

/* prints the PCB index, it's status, and it's state. */
void PrintPcbHeader( struct PCB * );

/*Loop through each child of the pcb and print out all of it's children's info*/
void PrintPcbChildren( struct PCB * singlePcb);
  

 
#endif