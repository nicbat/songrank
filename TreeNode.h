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
  // int insert(Song& song);
  void updateHeight();
  
  // getters
  Song* get_song() { return song_; }
  TreeNode* get_left() { return children[0]; }
  TreeNode* get_right() { return children[1]; }
  int get_height() { return height_; }
  int get_balance();
  int get_childHeight(int child);
  TreeNode* get_child(int child) { return children[child]; }
  
  // setters
  void set_child(TreeNode* child, int lr) { children[lr] = child; }
  
  int compareto(Song& b);

 private:
  Song* song_;
  // TreeNode* left_;
  // TreeNode* right_;
  TreeNode** children;
  int height_; // for avl nonsense later
};


// std::ostream& operator<<(std::ostream& os, TreeTreeNodeNode& n);

void printRankings(TreeNode& n, std::ofstream* f);

#endif // TREENODE_H_
