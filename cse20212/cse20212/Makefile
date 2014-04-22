OBJS=BoardPiece.o Game.o Location.o Move.o Pokeball.o Pokemon.o Sprite.o Type.o

all: pokemon

pokemon: $(OBJS) Source.o
	g++ $(OBJS) Source.o -o pokemon

Source.o: Source.cpp
	g++ Souce.cpp -c

BoardPiece.o: BoardPiece.h BoardPiece.cpp
	g++ BoardPiece.cpp -c

Game.o: Game.h Game.cpp
	g++ Game.cpp -c

Location.o: Location.h Location.cpp
	g++ Location.cpp -c

Move.o: Move.h Move.cpp
	g++ Move.cpp -c

Pokeball.o: Pokeball.h Pokeball.cpp
	g++ Pokeball.cpp -c

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ Pokemon.cpp -c

Sprite.o: Sprite.h Sprite.cpp
	g++ Sprite.cpp -c

Type.o: Type.h Type.cpp
	g++ Type.cpp -c

love:
	clear; echo "not war"

clean:
	rm pokemon *.o -f	
