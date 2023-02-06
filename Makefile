CC      = gcc
CFLAGS  = -g
TARGET  = oss worker
OBJS    = oss.o worker.o


.DEFAULT_GOAL: ALL
ALL: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
worker.o: worker.c
	$(CC) -fpic -c worker.c
.c.o:
	$(CC) $(CFLAGS) -c $<
.PHONY: clean
clean:
	/bin/rm -f *.o *~ $(TARGET)CC = gcc
