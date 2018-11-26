

CC = g++

all: main.o CList.o
	$(CC) -o main main.cpp CList.cpp

main.o: main.cpp
	$(CC) -c main.cpp

CList.p: CList.cpp
	$(CC) -c CList.cpp

clean: 
	rm -f core *.o

