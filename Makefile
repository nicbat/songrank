# CXX = x86_64-w64-mingw32-g++
CXX = g++

all: SongRanker

SongRanker: SongRanker.o Node.o Song.o
	$(CXX) -Wall -g -std=c++17 -o SongRanker SongRanker.o Node.o Song.o

Node.o: Node.cc Node.h Song.h
	$(CXX) -Wall -g -std=c++17 -c Node.cc

Song.o: Song.cc Song.h
	$(CXX) -Wall -g -std=c++17 -c Song.cc

SongRanker.o: SongRanker.cc Node.h Song.h
	$(CXX) -Wall -g -std=c++17 -c SongRanker.cc

clean:
	rm -rf SongRanker *.o *~ *.dYSM
