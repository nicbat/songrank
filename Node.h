#ifndef NODE_H_
#define NODE_H_

#include <ostream>
#include <string>
#include "Song.h"

class Node {
 public:
  // ctors
  Node();
  Node(Song& song);
  Node(Song& song, Node& left, Node& right);
  Node(Node& node);
  ~Node();

  // methods
  bool insert(Song& song);
  
  // getters
  Song* get_song() { return song_; }
  Node* get_left() { return left_; }
  Node* get_right() { return right_; }
  int get_height() { return height_; }
  
  int compareto(Song& b);

 private:
  Song* song_;
  Node* left_;
  Node* right_;
  int height_; // for avl nonsense later
};


// std::ostream& operator<<(std::ostream& os, Node& n);

void printRankings(Node& n);

#endif // NODE_H_
