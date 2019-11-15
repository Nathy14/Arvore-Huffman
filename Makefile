CC=gcc

huffman:
	mkdir -p bin
	$(CC) src/commons.c src/huffman.c -o bin/huffman
	@./bin/huffman
	@rm -rf bin/*

.PHONY: clean

clean:
	rm bin/*
