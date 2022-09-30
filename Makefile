all:
	g++ -I src/include -L src/lib -o main main.cpp game.cpp object.cpp field.cpp playersTurn.cpp button.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf 