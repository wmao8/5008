all: build run clean

build: node.h node.c deque.c
	gcc node.c deque.c  -o a4
run: build
	./a4
clean:
	rm a4

