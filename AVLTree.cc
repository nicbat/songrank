#include "AVLTree.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"

AVLTree::AVLTree() {
  root_ = NULL;
}

AVLTree::~AVLTree() { }

int AVLTree::insert(Song& song) {
  TreeNode* prev = NULL;
  TreeNode* current = root_;
  LinkedList* stack = new LinkedList();
}

TreeNode* AVLTree::rotate(TreeNode* node) {

}

TreeNode* AVLTree::rotateLeft(TreeNode* node) {

}

TreeNode* AVLTree::rotateRight(TreeNode* node) {

}
