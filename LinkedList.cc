#include "ListNode.h"
#include "LinkedList.h"
#include "Song.h"
#include <fstream>

LinkedList::LinkedList() {
  front_ = NULL;
  back_ = NULL;
  size_ = 0;
}

LinkedList::LinkedList(LinkedList& list) {
  front_ = list.get_front();
  back_ = list.get_back();
  size_ = list.get_size();
}

LinkedList::~LinkedList() {
  if (front_ != NULL) {
    delete front_;
  }
  if (back_ != NULL) {
    delete back_;
  }
}

void LinkedList::append(Song& song) {
  ListNode* node = new ListNode(song);
  size_ += 1;
  if (back_ == NULL) {
    back_ = node;
    front_ = node;
  } else {
    back_->set_next(node);
    back_ = node;
  }
}

void LinkedList::printList(std::ofstream* f) {
  ListNode* curr = front_;
  int ranking = 1;
  while (curr != NULL) {
    *f << ranking << ". " << *curr->get_song() << "\n";
    ranking += 1;
    curr = curr->get_next();
  }
}
