#include "Song.h"
#include "ListNode.h"

ListNode::ListNode() {
  song_ = NULL;
  next_ = NULL;
}

ListNode::ListNode(Song& song) {
  song_ = new Song;
  *song_ = song;
  next_ = NULL;
}

ListNode::ListNode(ListNode& node) {
  song_ = node.get_song();
  next_ = node.get_next();
}

ListNode::~ListNode() {
  delete song_;
}
