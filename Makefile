all:
	x86_64-w64-mingw32-g++ -I src/include -L src/lib -o main main.cpp -lSDL2main -lSDL2 -static-libgcc -static-libstdc++