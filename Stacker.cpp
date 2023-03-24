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
    Pixel pix = new Pixel;
    pix.red = r;
    pix.green = g;
    pix.blue = b;
    pixels.push_back(pix);
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
