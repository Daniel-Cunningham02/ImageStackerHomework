#ifndef STACKER_H
#define STACKER_H
#include <string>
#include <vector>


struct Pixel {
  int red;
  int green;
  int blue;
};

class Stacker {
private:
  std::string magic_number; // the P3 number
  int width; // the image width
  int height; // the image height
  int max_color; // max color depth 
  std::vector<Pixel> pixels; // storing color info
public:
  Stacker();
  ~Stacker();
  void addImage(std::string filename);
  void writeOutput(std::string filename);
};

#endif
