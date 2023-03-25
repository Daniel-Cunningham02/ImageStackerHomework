/**
 * @file Stacker.cpp
 * @author Anthony Osborne
 * @date 2023-03-23
 * @brief Implementation of the stacker class
 * 
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "Stacker.h"

using namespace std;


/**IK i should implement others first but i was pretty sure i could load 
images more easily than i could implement the other functions.
*/
Stacker::Stacker(){
  width = 0;
  height = 0;
  max_color = 0;
}
Stacker::~Stacker(){
  
}

void Stacker::stackImage(string filename) {
  ifstream inFile(filename);
  string header;
  int cmp_width, cmp_height, cmp_max;
  inFile >> header;
  if(header != "P3") {
    cerr << "Error: file \"" << filename << "\" is not in PPM format" <<endl;
    return;
  } 
  inFile >> cmp_width >> cmp_height >> cmp_max;
  if(cmp_width != width || cmp_height != height) {
    cerr << "File dimensions do not match!\n";
    cerr.flush();
    return;
  }
  for(int i = 0; i < (width * height); i++) {
    int r, g, b;
    inFile >> r >> g >> b;
    pixels[i].red += r;
    pixels[i].green += g;
    pixels[i].blue += b;
  }

  inFile.close();
}

void Stacker::average(int numStack) {
  for(int i = 0; i < (width*height); i++) {
    pixels[i].red /= numStack;
    pixels[i].green /= numStack;
    pixels[i].blue /= numStack;
  }
}

void Stacker::addImage(string filename){
  ifstream infile(filename);
  // if(!infile.is_open()){
  //   cerr << "Error: could not open file \"" << filename << " \"" << endl;
  //   return;
  // }
  string magic_number;
  infile >> magic_number;
  if(magic_number != "P3"){
    cerr << "Error: file \"" << filename << "\" is not in PPM format" <<endl;
    return;
  }
  infile >> width >> height >> max_color;
  pixels.resize(width * height);
  for(int i = 0; i < width * height; i++){
    int r, g, b;
    infile >> r >> g >> b;
    pixels[i].red = r; /* We were declaring a Pixel on the stack which disappears after the method runs
			  here we are using the dynamically declared Pixel struct in the vector and just modifying it.
			  No extra memory management. No extra hassle. */
    pixels[i].green = g;
    pixels[i].blue = b;
  }
  
  infile.close();
}

void Stacker::writeOutput(string filename){
  ofstream outfile(filename);
  // if(outfile.open()){
  //   cerr << "Error: could not open file\"" << filename << "\"" << endl;
  //   return;
  //}
  outfile << "P3" << endl;
  outfile << width << " " << height << endl;
  outfile << max_color << endl;
  
  for(int i = 0; i < width * height; i++){
    
    outfile << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << " ";
  }
  
  outfile.close();
}
