g = g++
flags = -Wall -c

all: bin/main


bin/main: build/src/main.o build/src/draw.o
	$(g) $^ -o bin/main

build/src/main.o:
	$(g)  $(flags) src/main.cpp -o $@

build/src/draw.o:
	$(g)  $(flags) src/draw.cpp -o $@

run:
	bin/main
