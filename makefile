#!make

build:
	g++ main.cpp -o build
clean:
	rm ./build
dev:
	g++ main.cpp -o dev
	./dev
	rm ./dev