#object files
OBJECTS=BoardPiece.o Game.o Item.o Location.o Move.o Pokeball.o Pokemon.o Potion.o Source.o Sprite.o Timer.o Trainer.o Type.o 
#need to add trainer in objects after it works
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
Game.o: Game.cpp Game.h BoardPiece.h Location.h Pokemon.h Sprite.h Type.h Move.h Pokeball.h Timer.h #Trainer.h
	$(COMPILER) Game.cpp -c
Item.o: Item.cpp Item.h
	$(COMPILER) Item.cpp -c
Location.o: Location.cpp Location.h
	$(COMPILER) Location.cpp -c
Move.o:	Move.cpp Move.h Type.h
	$(COMPILER) Move.cpp -c
Pokeball.o: Pokeball.cpp Pokeball.h Pokemon.h
	$(COMPILER) Pokeball.cpp -c
Pokemon.o: Pokemon.cpp Pokemon.h Move.h Type.h
	$(COMPILER) Pokemon.cpp -c
Potion.o: Potion.cpp Potion.h
	$(COMPILER) Potion.cpp -c
Sprite.o: Sprite.cpp Sprite.h
	$(COMPILER) Sprite.cpp -c
Timer.o: Timer.cpp Timer.h
	$(COMPILER) Timer.cpp -c
Type.o: Type.cpp Type.h
	$(COMPILER) Type.cpp -c
Trainer.o: Trainer.cpp Trainer.h
	$(COMPILER) Trainer.cpp -c
clean:
	rm $(PROGRAM) *.o *.gch -f
love:
	@echo "not war"

