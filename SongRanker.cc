#include "LinkedList.h"
#include "Song.h"
#include "TreeNode.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

void printResults(TreeNode* node, LinkedList* list);

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
  int i = 0;
  int result;
  TreeNode* first;
  LinkedList* list = new LinkedList();
  while (i < 190) {
    std::cout << "Do you know this song? (1 for yes, anything else for no): " << songs[i] << std::endl;
    std::cout << "Answer: ";
    std::cin >> result;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      result = 0;
    }
    // std::cout << std::endl;
    if (result == 1) {
      first = new TreeNode(songs[i]);
      i++;
      break;
    } else {
      list->append(songs[i]);
      result = 0;
    }
    i++;
  }
  if (i < 190) {
    std::cout << "----------------------------" << std::endl;
    std::cout << "For the following questions, answer 1 or 2 (0 or a letter to exit, 3 for don't know)." << std::endl;
  }
  while (i < 190) {
    result = first->insert(songs[i]);
    if (result == 0) {
      break;
    } else if (result == -1) {
      // add to don't know list
      list->append(songs[i]);
    }
    if (i % 10 == 0) {
      printResults(first, list);
    }
    i++;
  }
  if (i > 1) {
    printResults(first, list);
  }
}

void printResults(TreeNode* node, LinkedList* list) {
  std::ofstream* output_file = new std::ofstream;
  output_file->open("output.txt");
  printRankings(*node, output_file);
  *output_file << "---------------\nUnknown Songs:\n";
  list->printList(output_file);
  output_file->close();
  delete output_file;
}
