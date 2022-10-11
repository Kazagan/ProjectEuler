CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
LIBS=-lm

main:
	$(CC) $(CFLAGS) -o $1 $1.c $(LIBS)

library:
	$(CC) $(CFLAGS) -o $.o $1.h $(LIBS)

euler19:
	$(CC) $(CFLAGS) -o euler19 tens/euler19.c tens/Date.o
