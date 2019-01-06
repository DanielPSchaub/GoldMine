_playGame: playGame.cpp GoldMine.o twoDim.o
	g++ -o _playGame playGame.cpp GoldMine.o twoDim.o

GoldMine.o: GoldMine.cpp GoldMine.h
	g++ -c GoldMine.cpp

twoDim.o: twoDim.cpp twoDim.h
	g++ -c twoDim.cpp

clean:
	rm *.o _playGame
