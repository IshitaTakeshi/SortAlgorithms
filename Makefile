CC=gcc
CFLAGS=-g

LIBS=lib/*.c
SORT=sort/*.c
SEARCH=search/*.c

all: sort_test search_test

sort_test: test/sort_test.c $(SORT)
	$(CC) -o $@ $< $(LIBS) $(SORT) $(CFLAGS)

search_test: test/search_test.c $(SEARCH)
	$(CC) -o $@ $< $(LIBS) $(SEARCH) $(CFLAGS)

array_test: test/array_test.c $(LIBS)
	$(CC) -o $@ $< $(LIBS) $(CFLAGS)

clean:
	rm -f sort_test search_test
