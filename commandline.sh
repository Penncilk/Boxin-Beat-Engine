#I didn't make a makefile because this is easier for now
#I will make one in the future

g++ -g -c src/main.cpp -o obj/CL/main.o
g++ -g -c src/draw.cpp -o obj/CL/draw.o
g++ -g -c src/input.cpp -o obj/CL/input.o
gcc obj/CL/main.o obj/CL/draw.o obj/CL/input.o lib/libraylib.a -s -Wall -lm -lpthread -ldl -lrt -lX11 -o main
./main
