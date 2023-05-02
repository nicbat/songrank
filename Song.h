#ifndef SONG_H_
#define SONG_H_

#include <string>
#include <ostream>

class Song {
 public:
  // ctors
  Song();
  Song(std::string everything);
  Song(std::string title, std::string album, std::string artist);
  Song(Song& song);
  ~Song();

  // getters
  std::string get_title() { return title_; }
  std::string get_album() { return album_; }
  std::string get_artist() { return artist_; }
  
 private:
  std::string title_;
  std::string album_;
  std::string artist_;
};

std::ostream& operator<<(std::ostream& os, Song& song);

#endif // SONG_H_
