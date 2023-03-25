/**
 * @file main.cpp
 * @author Anthony Osborne, Daniel Cunningham, 
 * @date 2023-03-23
 * @brief driver code 
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include "Stacker.h"
using namespace std;

int main() {
  string image;
  int numStack;
  cout <<"Please enter the folder path of the images you wish to stack: ";
  cin >> image;
  cout << endl;
  cout <<"Please enter the number of images: ";
  cin >> numStack;
  cout << endl;
  Stacker stacker;
  for(int i = 0; i < numStack - 1; i++){
    if(i != 0) {
      if(i < 10) {
        stacker.stackImage(image + "_00" + to_string(i) + ".ppm");  
      }
      else {
        stacker.stackImage(image + "_0" + to_string(i) + ".ppm");
      }
      
    }
    else {
      stacker.addImage(image + "_001.ppm");
    }
  }
  stacker.average(numStack);
  stacker.writeOutput("output.ppm");
  return 0;
}
