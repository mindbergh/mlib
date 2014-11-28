CFLAGS = -Wall -g -I../
LDFLAGS = -L../
CC = gcc
objects = mtest.o mlist.o mslist.o mqueue.o





test: $(objects)
	$(CC) -o $@ $^ $(LDFLAGS)

mtest.o: mtest.c mlist.h mutil.h mtypes.h mslist.h mqueue.h
mlist.o: mlist.c mlist.h mutil.h mtypes.h
mslist.o: mslist.c mslist.h mutil.h mtypes.h
mqueue.o: mqueue.c mqueue.h mutil.h mtypes.h


%.o: %.ce
	$(CC) -c $(CFLAGS) -o $@ $<