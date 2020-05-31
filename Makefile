g = g++
flags = -Wall -c

all: bin/main


bin/main: build/src/main.o build/src/move.o build/src/draw.o
	$(g) $^ -o bin/main

build/src/main.o:
	$(g)  $(flags) src/main.cpp -o $@

build/src/move.o:
	$(g)  $(flags) src/move.cpp -o $@

build/src/draw.o:
	$(g)  $(flags) src/draw.cpp -o $@

run:
	bin/main

clean:
	rm build/src/*.o
