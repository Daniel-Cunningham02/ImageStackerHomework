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
  string temp = image.substr(image.find('/') + 1); // Finds the string from the first slash to the null character
  string imageName = temp.substr(0, image.find('/') + 1); // Finds the string from the beginning of the first string slice(temp) to the second slash. This becomes the output name
  cout << endl;
  cout <<"Please enter the number of images: ";
  cin >> numStack;
  cout << endl;
  Stacker stacker;
  for(int i = 0; i < numStack; i++){
    if(i != 0) {
      if((i+1) < 10) {
        stacker.stackImage(image + "_00" + to_string(i + 1) + ".ppm");  // String concatenation to get the correct image file
        cout << "\t" << image << "_00" << i + 1 << ".ppm" << endl;
      }
      else {
        stacker.stackImage(image + "_0" + to_string(i + 1) + ".ppm"); // String concatenation to get the correct image file
        cout << "\t" << image << "_0" << i + 1 << ".ppm" << endl;
      }
      
    }
    else {
      stacker.addImage(image + "_001.ppm");
      cout << "Stacking images:\n\t" << image << "_001.ppm" << endl;  
    }
  }
  stacker.average(numStack);
  cout << "Stacking succeeded.";
  stacker.writeOutput(imageName + ".ppm");
  cout << "Output written to: " << imageName << ".ppm" << endl;
  return 0;
}
