all:
	g++ -o exec main.cpp framebuffer.cpp point2.cpp input.c file.c -lm -std=c++11 -fpermissive
    
run:
	sudo ./exec
