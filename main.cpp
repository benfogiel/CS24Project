// main.cpp
// Author: Benjamin Fogiel

#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"

using namespace std;

int main(int argv, char *argc[2]){
	string file1, file2;
  if(argv != 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail()){
    cout << "Could not open file " << argc[1];
    return 1;
  }

  if (cardFile2.fail()){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // Create two objects of the class you defined 
  // to contain two sets of cards in two input files
  cards l1;
  cards l2;

  // Read each file and store cards
  while (getline (cardFile1, line) && (line.length() > 0)){
  	l1.append(line[0], line[2]);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
  	l2.append(line[0], line[2]);
  }
  cardFile2.close();

  l1.play(l1,l2,0,0,0); //start the game

  cout << endl; // for test formating needs

  cout << "Alice's cards:\n" << l1 << endl; // prints Alice's cards

  cout << "Bob's cards:\n" << l2; // prints Bob's cards

  return 0;
}