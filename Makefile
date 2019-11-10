CC=gcc

huffman:
	mkdir -p bin
	$(CC) commons.c huffman.c -o bin/huffman

all:
	mkdir -p bin
	$(CC) commons.c tree.c list.c huffman.c -o bin/huffman

.PHONY: clean

clean:
	rm bin/*
