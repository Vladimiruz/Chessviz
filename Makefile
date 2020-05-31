g = g++
flags = -Wall -c
GOOGLE = thirdparty/googletest


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

clang:
	clang-format -i ./src/*.h
	clang-format -i ./src/*.cpp
	clang-format -i ./test/*.cpp

test: gtestlib bin/test

gtestlib:
	g++ -std=c++11 -isystem ${GOOGLE}/include -I ${GOOGLE} -pthread -c ${GOOGLE}/src/gtest-all.cc -o build/test/gtest-all.o
	ar -rv build/test/libgtest.a build/test/gtest-all.o

bin/test: build/test/test.o build/test/move.o
	g++ -std=c++11 -isystem ${GOOGLE}/include -pthread $^ build/test/libgtest.a -o $@

build/test/test.o:
	g++ -std=c++11 -c -Wall test/test/test.cpp -I $(GOOGLE)/include -o $@

build/test/move.o:
	$(g)  $(flags) src/move.cpp -o $@

testrun:
	bin/test

cleantest:
	rm build/test/*.o
