CC = gcc
CFLAGS = -Wall
DEPS = oss.c workers.c
OBJ = oss.o workers.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

main: $(OBJ)
	gcc $(CFLAGS) -o $@ $^
.PHONY: clean
clean:
	/bin/rm -f *.o *~ main
