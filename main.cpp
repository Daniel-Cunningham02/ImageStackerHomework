/**
 * @file main.cpp
 * @author Anthony Osborne, Daniel Cunningham, Colin Douglas
 * @date 2023-03-23
 * @brief driver code 
 * This is the main code for running the stacker program
 * The desired file must have it's path specified
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
  string imageName = image.substr(image.find('/') + 1); // Finds the string from the first slash to the null character
  cout << endl;
  cout <<"Please enter the number of images: ";
  cin >> numStack;
  cout << endl;
  Stacker stacker;
  for(int i = 0; i < numStack; i++){
    if(i != 0) {
      if((i+1) < 10) {
        stacker.stackImage(image + "/" + imageName + "_00" + to_string(i + 1) + ".ppm");  // String concatenation to get the correct image file
        cout << "\t" << image << "/" << imageName << "_00" << i + 1 << ".ppm" << endl;
      }
      else {
        stacker.stackImage(image + "/" + imageName + "_0" + to_string(i + 1) + ".ppm"); // String concatenation to get the correct image file
        cout << "\t" << image << "/" << imageName << "_0" << i + 1 << ".ppm" << endl;
      }
      
    }
    else {
      stacker.addImage(image + "/" + imageName + "_001.ppm");
      cout << "Stacking images:\n\t" << image << "/" << imageName << "_001.ppm" << endl;  
    }
  }
  stacker.average(numStack);
  cout << "Stacking succeeded.\n";
  stacker.writeOutput(imageName + ".ppm");
  cout << "Output written to: " << imageName << ".ppm" << endl;
  return 0;
}
