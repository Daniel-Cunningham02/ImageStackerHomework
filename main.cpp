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
  cout <<"Please enter the image you wish to stack: ";
  cin >> image;
  cout << endl;
  cout <<"Please enter the number of images: ";
  cin >> numStack;
  cout << endl;
  Stacker stacker;
  for(int i = 0; i < numStack; i++){
    stacker.addImage(image);
    stacker.writeOutput("output.ppm");
  }
  
  return 0;
}
