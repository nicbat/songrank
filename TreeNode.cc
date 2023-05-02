#include "TreeNode.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include <string>

using std::ostream;
using std::cin;
using std::endl;
using std::cout;
using std::ofstream;

// helper function declarations
static void printRankingsHelper(TreeNode* n, int* starting, ofstream* f);

// function definitions

TreeNode::TreeNode() {
  song_ = NULL;
  left_ = NULL;
  right_ = NULL;
  height_ = 0;
}

TreeNode::TreeNode(Song& song) {
  song_ = new Song;
  *song_ = song;
  left_ = NULL;
  right_ = NULL;
  height_ = 0;
}

TreeNode::TreeNode(Song& song, TreeNode& left, TreeNode& right) {
  song_ = new Song;
  *song_ = song;
  left_ = &left;
  right_ = &right;
  height_ = 0;
}

TreeNode::TreeNode(TreeNode& node) {
  song_ = node.get_song();
  left_ = node.get_left();
  right_ = node.get_right();
  height_ = node.get_height();
}

TreeNode::~TreeNode() { 
  delete song_;
}

int TreeNode::insert(Song& song) {
  int result = compareto(song);
  if (result == 0) {
    return 0;
  }
  if (result == 1) {
    if (right_ == NULL) {
      right_ = new TreeNode(song);
    } else {
      return right_->insert(song);
    }
  } else if (result == 2) {
    if (left_ == NULL) {
      left_ = new TreeNode(song);
    } else {
      return left_->insert(song);
    }
  } else {
    return -1;
  }
  return 1;
}

int TreeNode::compareto(Song& b) {
  cout << *get_song();
  cout << " or ";
  cout << b << endl;
  int choice;
  
  while (1) {
    // cout << "Answer 1 or 2 (0 or a letter to exit): ";
    cout << "Answer: ";
    cin >> choice;
    if (choice == 1) {
      return 1;
    } else if (choice == 2) {
      return 2;
    } else if (choice == 0){
      return 0;
    } else if (choice == 3) {
      return 3;
    }
  }
}

// ostream& operator<<(std::ostream& os, TreeNode& n) {
//   
// }

void printRankings(TreeNode& n, ofstream* f) {
  int* ranking = new int;
  *ranking = 1;
  printRankingsHelper(&n, ranking, f);
  delete ranking;
}

static void printRankingsHelper(TreeNode* n, int* starting, ofstream* f) {
  if (n != NULL) {
    printRankingsHelper(n->get_left(), starting, f);
    *f << *starting << ". " << *n->get_song() << "\n";
    *starting += 1;
    printRankingsHelper(n->get_right(), starting, f);
  }
}
