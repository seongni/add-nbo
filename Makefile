#Makefile
all: add-nbo

add-nbo: add.o main.o
	g++ -o add-nbo add.o main.o

clean:
	rm -f add-nbo
	rm -f *.o

