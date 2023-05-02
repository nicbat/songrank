# CXX = x86_64-w64-mingw32-g++
CXX = g++

all: SongRanker

SongRanker: SongRanker.o LinkedList.o ListNode.o TreeNode.o Song.o
	$(CXX) -static -Wall -g -std=c++17 -o SongRanker LinkedList.o ListNode.o SongRanker.o TreeNode.o Song.o

LinkedList.o: LinkedList.cc ListNode.h Song.h LinkedList.h
	$(CXX) -Wall -g -std=c++17 -c LinkedList.cc

ListNode.o: ListNode.cc ListNode.h Song.h
	$(CXX) -Wall -g -std=c++17 -c ListNode.cc

TreeNode.o: TreeNode.cc TreeNode.h Song.h
	$(CXX) -Wall -g -std=c++17 -c TreeNode.cc

Song.o: Song.cc Song.h
	$(CXX) -Wall -g -std=c++17 -c Song.cc

SongRanker.o: SongRanker.cc TreeNode.h Song.h
	$(CXX) -Wall -g -std=c++17 -c SongRanker.cc

clean:
	rm -rf SongRanker *.o *~ *.dYSM
