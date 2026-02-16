CC = $(CROSS_COMPILE)gcc

all: writer

writer: writer.c
	$(CC) -c writer.c -o writer.o
	$(CC) writer.o -o writer

clean:
	rm -f writer *.o