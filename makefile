CC = g++
CFLAGS = -g -Wall

shapeanim: Node.o main.o
	$(CC) $(CFLAGS) Node.o main.o
Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp
main.o: main.cpp Node.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *o shapeanim

run:
	./shapeanim
