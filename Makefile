.PHONY: build
build:
	clang++ -Wall -std=c++20 src/logger.cpp src/static.cpp src/entity.cpp src/myentity.cpp src/oop.cpp src/virtual_fn.cpp src/visibility.cpp src/arrays.cpp src/strings.cpp src/main.cpp

run:
	./a.out

clean:
	rm -rf a.out

all: clean build run

asm:
	clang++ -Wall -std=c++20 -S src/strings.cpp