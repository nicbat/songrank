#include "Song.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;

Song::Song() {
  title_ = "";
  album_ = "";
  artist_ = "";
}

Song::Song(string everything) {
  title_ = everything;
  album_ = everything;
  artist_ = everything;
}

Song::Song(string title, string album, string artist) {
  title_ = title;
  album_ = album;
  artist_ = artist;
}

Song::Song(Song& song) {
  title_ = song.get_title();
  album_ = song.get_album();
  artist_ = song.get_artist();
}

Song::~Song() { }

std::ostream& operator<<(std::ostream& os, Song& song) {
  os << "\"" << song.get_title() << "\"";
  os << " (" << song.get_album() << ")";
  return os;
}
