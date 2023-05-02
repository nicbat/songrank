#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <ostream>
#include <string>
#include "Song.h"

class ListNode {
 public:
  // ctors
  ListNode();
  ListNode(Song& song);
  ListNode(ListNode& node);
  ~ListNode();

  // methods
  // int append(Song& song);
  
  // getters
  Song* get_song() { return song_; }
  ListNode* get_next() { return next_; }

  void set_next(ListNode* next) { next_ = next; }

 private:
  Song* song_;
  ListNode* next_;
};

#endif // LISTNODE_H_
