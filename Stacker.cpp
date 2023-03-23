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

void Stacker::addImage(string filename){
  ifstream infile(filename);
  if(infile.is_open()){
    cerr << "Error: could not open file \"" << filename << " \"" << endl;
    return;
  }
}

