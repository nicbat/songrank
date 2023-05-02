#ifndef TREENODE_H_
#define TREENODE_H_

#include <ostream>
#include <string>
#include "Song.h"

class TreeNode {
 public:
  // ctors
  TreeNode();
  TreeNode(Song& song);
  TreeNode(Song& song, TreeNode& left, TreeNode& right);
  TreeNode(TreeNode& node);
  ~TreeNode();

  // methods
  int insert(Song& song);
  
  // getters
  Song* get_song() { return song_; }
  TreeNode* get_left() { return left_; }
  TreeNode* get_right() { return right_; }
  int get_height() { return height_; }
  
  int compareto(Song& b);

 private:
  Song* song_;
  TreeNode* left_;
  TreeNode* right_;
  int height_; // for avl nonsense later
};


// std::ostream& operator<<(std::ostream& os, TreeTreeNodeNode& n);

void printRankings(TreeNode& n, std::ofstream* f);

#endif // TREENODE_H_
