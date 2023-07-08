#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <ostream>
#include <string>
#include "TreeNode.h"

class AVLTree {
 public:
  AVLTree();
  ~AVLTree();
  int insert(Song& song);
 private:
  TreeNode* rotate(TreeNode* node);
  TreeNode* rotateLeft(TreeNode* node);
  TreeNode* rotateRight(TreeNode* node);

  TreeNode* root_;
};

#endif // AVLTREE_H_
