pcb_simul: pcb.o main.o 
	gcc -g -Wall pcb.o main.o -o pcb_simul

main.o: pcb.o main.c 
	gcc -g -Wall -c main.c -o main.o

pcb.o:  pcb.c
	gcc -g -Wall -c pcb.c -o pcb.o


clean:
	rm -f *.o pcb_simul