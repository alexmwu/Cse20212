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

Source.o: Source.cpp Game.h
	$(COMPILER) Source.cpp -c
BoardPiece.o: BoardPiece.cpp BoardPiece.h Location.h Sprite.h
	$(COMPILER) BoardPiece.cpp -c
Game.o: Game.cpp Game.h BoardPiece.h Location.h Pokemon.h Sprite.h Type.h Move.h Pokeball.h Trainer.h
	$(COMPILER) Game.cpp -c
Location.o: Location.cpp Location.h
	$(COMPILER) Location.cpp -c
Move.o:	Move.cpp Move.h Type.h
	$(COMPILER) Move.cpp -c
Pokeball.o: Pokeball.cpp Pokeball.h Pokemon.h
	$(COMPILER) Pokeball.cpp -c
Pokemon.o: Pokemon.cpp Pokemon.h Move.h Type.h
	$(COMPILER) Pokemon.cpp -c
Sprite.o: Sprite.cpp Sprite.h
	$(COMPILER) Sprite.cpp -c
Type.o: Type.cpp Type.h
	$(COMPILER) Type.cpp -c
Trainer.o: Trainer.cpp Trainer.h
	$(COMPILER) Trainer.cpp Pokemon.h Sprite.h Location.h -c
clean:
	rm $(PROGRAM) *.o -f
love:
	@echo "not war"

