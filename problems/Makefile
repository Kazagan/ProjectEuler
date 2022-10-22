LAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
LIBS=-lm

main:
	$(CC) $(CFLAGS) -o $1 $1.c $(LIBS)

library:
	$(CC) $(CFLAGS) -o $(file).h $(file).c

euler19:
	$(CC) $(CFLAGS) -o euler19 tens/euler19.c $(LIBS) tens/Date.c
	./euler19
	rm ./euler19
