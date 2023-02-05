CC      = gcc
CFLAGS  = -g
TARGET  = oss worker
OBJS    = oss.o workers.o
LIBOBJS = workers.o

.DEFAULT_GOAL: ALL
ALL: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
$(LIB): $(LIBOBJS)
	$(CC) -shared -Wl,-soname,$@ -o $@ $(LIBOBJS)
workers.o: workers.c
	$(CC) -fpic -c square.c
.c.o:
	$(CC) $(CFLAGS) -c $<
.PHONY: clean
clean:
	/bin/rm -f *.o *~ $(TARGET)CC = gcc