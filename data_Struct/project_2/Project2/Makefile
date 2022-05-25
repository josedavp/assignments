all: project2-main.o schedule.o
	gcc project2-main.o schedule.o -o myprogram
project2-main.o: project2-main.c schedule.h
	gcc -c project2-main.c
schedule.o: schedule.c schedule.h
	gcc -c schedule.c
clean:
	rm -rf *.o
	rm myprogram
