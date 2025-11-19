CC=gcc
CFLAGS=-g -Wall -Wextra -Wpedantic -std=c89


SRC= $(wildcard src/*.c)
DEST = $(SRC:src/%.c=%)

all: $(DEST)

%: src/%.c
	$(CC) $(CFLAGS) -o dest/$@ $<

clean:
	@rm -rfv dest/*
