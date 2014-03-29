#object files
OBJECTS=BoardPiece.o Game.o Location.o Move.o Pokeball.o Pokemon.o Source.o Sprite.o Type.o
#compiler flags to be used
COMPILERFLAGS=-lSDL -lSDL_image -lSDL_mixer -o
#compiler to be used
COMPILER=g++
#program name
PROGRAM=pokemon

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(COMPILERFLAGS) $(PROGRAM)

Source.o: Source.cpp
	$(COMPILER) Source.cpp Game.h -c
BoardPiece.o: BoardPiece.cpp
	$(COMPILER) BoardPiece.cpp Location.h Sprite.h -c
Game.o: Game.cpp
	$(COMPILER) Game.cpp BoardPiece.h Location.h Pokemon.h Sprite.h Type.h Move.h Pokeball.h Trainer.h -c
Location.o: Location.cpp
	$(COMPILER) Location.cpp -c
Move.o:	Move.cpp
	$(COMPILER) Move.cpp  Type.h -c
Pokeball.o: Pokeball.cpp
	$(COMPILER) Pokeball.cpp Pokemon.h -c
Pokemon.o: Pokemon.cpp
	$(COMPILER) Pokemon.cpp Move.h Type.h -c
Sprite.o: Sprite.cpp
	$(COMPILER) Sprite.cpp -c
Type.o: Type.cpp
	$(COMPILER) Type.cpp -c
Trainer.o: Trainer.cpp
	$(COMPILER) Trainer.cpp Pokemon.h Sprite.h Location.h -c
clean:
	rm $(PROGRAM) *.o -f
love:
	echo "not war"

