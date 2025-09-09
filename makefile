all: build, run

build:
	g++ driver.cpp -o driver

run:
	./driver
