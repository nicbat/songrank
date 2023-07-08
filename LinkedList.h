#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "ListNode.h"
#include "Song.h"
#include <fstream>

class LinkedList {
 public:
  LinkedList();
  LinkedList(LinkedList& list);
  ~LinkedList();
  
  // getters
  ListNode* get_front() { return front_; }
  ListNode* get_back() { return back_; }
  int get_size() { return size_; }

  void printList(std::ofstream* f);

  void append(Song& song);
  void prepend(Song& song);
  Song* remove_front();

 private:
  ListNode* front_;
  ListNode* back_;
  int size_;
};

#endif // LINKEDLIST_H_
