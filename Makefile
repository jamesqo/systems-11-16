all: main

main: main.o child_proc.o
	gcc -o main main.o child_proc.o

main.o: main.c
	gcc -c main.c

child_proc.o: child_proc.c
	gcc -c child_proc.c

clean:
	rm *.exe *~ *.o main

run: all
	./main
