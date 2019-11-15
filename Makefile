CC=gcc

huffman:
	mkdir -p bin
	$(CC) commons.c huffman.c -o bin/huffman
	@./bin/huffman
	@rm -rf bin/*

all:
	mkdir -p bin
	$(CC) commons.c tree.c list.c huffman.c -o bin/huffman

.PHONY: clean

clean:
	rm bin/*
