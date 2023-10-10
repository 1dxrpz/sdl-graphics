COMPILER32=i686-w64-mingw32-gcc
COMPILER64=x86_64-w64-mingw32-g++

EXE=main
ENTRY=main
LIBS32=-I src/x32/include -L src/x32/lib
LIBS64=-I src/x64/include -L src/x64/lib
FLAGS=-lSDL2main -lSDL2 -static-libgcc -static-libstdc++

DEBUG=$(ENTRY).cpp $(FLAGS) -o $(EXE)

all:
	$(COMPILER64) $(LIBS64) $(FLAGS) -c main.cpp src/lib/*.cpp
	x86_64-w64-mingw32-g++ *.o -o main64 -I src/x64/include -L src/x64/lib -lSDL2main -lSDL2 -static-libgcc -static-libstdc++

def:
	g++ -c main.cpp src/lib/*.cpp
	g++ *.o
	rm -f *.o

debug64:
	$(COMPILER64) $(LIBS64) $(DEBUG)_x64

release64:
	debug64 -mwindows

debug32:
	$(COMPILER32) $(LIBS32) $(DEBUG)_x32

release32:
	debug32 -mwindows