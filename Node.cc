#include "Node.h"
#include "Song.h"
#include <iostream>
#include <string>

using std::ostream;
using std::cin;
using std::endl;
using std::cout;

// helper function declarations
static void printRankingsHelper(Node* n, int* starting);

// function definitions

Node::Node() {
  song_ = NULL;
  left_ = NULL;
  right_ = NULL;
  height_ = 0;
}

Node::Node(Song& song) {
  song_ = new Song;
  *song_ = song;
  left_ = NULL;
  right_ = NULL;
  height_ = 0;
}

Node::Node(Song& song, Node& left, Node& right) {
  song_ = new Song;
  *song_ = song;
  left_ = &left;
  right_ = &right;
  height_ = 0;
}

Node::~Node() { 
  delete song_;
}

bool Node::insert(Song& song) {
  int result = compareto(song);
  if (result == 0) {
    return false;
  }
  if (result == 1) {
    if (right_ == NULL) {
      right_ = new Node(song);
    } else {
      return right_->insert(song);
    }
  } else {
    if (left_ == NULL) {
      left_ = new Node(song);
    } else {
      return left_->insert(song);
    }
  }
  return true;
}

int Node::compareto(Song& b) {
  cout << *get_song();
  cout << " or ";
  cout << b << endl;
  int choice;
  
  while (1) {
    cout << "Answer 1 or 2 (0 or a letter to exit): ";
    cin >> choice;
    if (choice == 1) {
      return 1;
    } else if (choice == 2) {
      return -1;
    } else if (choice == 0){
      return 0;
    }
  }
}

// ostream& operator<<(std::ostream& os, Node& n) {
//   
// }

void printRankings(Node& n) {
  int* ranking = new int;
  *ranking = 1;
  printRankingsHelper(&n, ranking);
  delete ranking;
}

static void printRankingsHelper(Node* n, int* starting) {
  if (n != NULL) {
    printRankingsHelper(n->get_left(), starting);
    cout << *starting << ". " << *n->get_song() << endl;
    *starting += 1;
    printRankingsHelper(n->get_right(), starting);
  }
}
