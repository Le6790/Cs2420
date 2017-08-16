all: wordLadder

debug: 
	g++ -ggdb3 -std=c++11 -c *.cpp
	g++ -ggdb3 -std=c++11 *.o -o a.out
	
wordLadder: testLadder game
	g++ -std=c++11 *.o -o a.out
	
testLadder:
	g++ -std=c++11 -c testLadder.cpp
	
game:
	g++ -std=c++11 -c game.cpp 
	
clean:
	rm *o 
