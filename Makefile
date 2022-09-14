all:
	g++ -I src/include -L src/lib -o main main.cpp game.cpp object.cpp -lmingw32 -lSDL2main -lSDL2