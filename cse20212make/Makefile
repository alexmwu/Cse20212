#object files
OBJECTS=BoardPiece.o Game.o Location.o Move.o Pokeball.o Pokemon.o Source.o Sprite.o Type.o
#compiler flags to be used
COMPILERFLAGS=-lSDL -lSDL_image -lSDL_mixer -o
#compiler to be used
COMPILER=g++
#program name
PROGRAM=pokemongame

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILERFLAGS) $(PROGRAM)

Source.o: Source.cpp
	$(COMPILER) Source.cpp -c
BoardPiece.o: BoardPiece.cpp
	$(COMPILER) BoardPiece.cpp -c
Game.o: Game.cpp
	$(COMPILER) Game.cpp -c
Location.o: Location.cpp
	$(COMPILER) Location.cpp -c
Move.o:	Move.cpp
	$(COMPILER) Move.cpp -c
Pokeball.o: Pokeball.cpp
	$(COMPILER) Pokeball.cpp -c
Pokemon.o: Pokemon.cpp
	$(COMPILER) Pokemon.cpp -c
Sprite.o: Sprite.cpp
	$(COMPILER) Sprite.cpp -c
Type.o: Type.cpp
	$(COMPILER) Type.cpp -c
clean:
	rm $(PROGRAM) *.o -f
love:
	echo "not war"

