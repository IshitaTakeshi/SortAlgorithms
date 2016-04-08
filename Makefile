FLAGS=-g
LIBS=lib/*.c
SORT=sort/*.c
SEARCH=search/*.c
CC=gcc

all: sort_test search_test

sort_test: test/sort_test.c $(SORT)
	$(CC) -o $@ $< $(LIBS) $(SORT) $(FLAGS)

search_test: test/search_test.c $(SEARCH)
	$(CC) -o $@ $< $(LIBS) $(SEARCH) $(FLAGS)
