/**
 * @file Stacker.h
 * @author Anthony Osborne, Daniel Cunningham, Colin Douglas
 * @date 2023-03-24
 * @brief Header file for Stacker
 * 
 * contains the functions for the stacker class and the Pixel struct
 */

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
  void average(int numStack);
  void stackImage(std::string filename); // added this to differentiate between adding base images and stacked images
  void writeOutput(std::string filename);
};

#endif
