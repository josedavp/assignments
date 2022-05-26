# Makefile comments
PROGRAMS = driver
CC = gcc
CFLAGS = -Wall -g
all: $(PROGRAMS)
clean:
	rm -f *.o
# C compilations
answer3.o: answer3.c
	$(CC) $(CFLAGS) -c answer3.c
driver.o: driver.c answer3.c
	$(CC) $(CFLAGS) -c driver.c
# Executable programs
driver: driver.o 
	$(CC) $(CFLAGS) -o driver driver.o 

