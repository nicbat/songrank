#include "Song.h"
#include "Node.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


int main(int argc, char** argv) {
  // Song* songs = new Song[5];
  // songs[0] = Song("Better than Revenge", "Speak Now", "TS");
  // songs[1] = Song("Lavender Haze", "Midnights", "TS");
  // songs[2] = Song("Paper Rings", "Lover", "TS");
  // songs[3] = Song("Mr. Perfectly Fine", "Fearless", "TS");
  // songs[4] = Song("Welcome to New York", "1989", "TS");
  Song* songs = new Song[190];
  
  std::fstream fin;
  fin.open("TSSongs.csv", std::ios::in);
  if (fin.is_open()) {
    std::string line;
    std::string title, album;
    int j = 0;
    while (getline(fin, line)) {
      std::stringstream ss(line);
      getline(ss, title, ',');
      getline(ss, album, '\r');
      songs[j] = Song(title, album, "Taylor Swift");
      // std::cout << "Added song: " << songs[j] << std::endl;
      j += 1;
    }

    fin.close();
  } else {
    return EXIT_FAILURE;
  }

  // std::cout << "-----------------------" << std::endl;

  std::cout << "Warning: Answering any of the following questions will overwrite the rankings in output.txt" << std::endl;
  std::cout << "For the following questions, answer 1 or 2 (0 or a letter to exit)." << std::endl;
  Node* first = new Node(songs[0]);
  bool result;
  int i;
  for (i = 1; i < 190; i++) {
    result = first->insert(songs[i]);
    if (!result) {
      break;
    }
  }
  if (i > 1) {
    printRankings(*first);
  }
}
