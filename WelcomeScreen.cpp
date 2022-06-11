#include "WelcomeScreen.h"
#include "printAscii.hpp"

#include <iostream>
using namespace std;

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define YELLOW  "\033[33m"      /* Yellow */
#define MAGENTA "\x1b[35m";

WelcomeScreen :: WelcomeScreen() {
  cout<<endl;
  cout<<MAGENTA;
  printAscii("WelcomeToConnect4.txt");
  cout<<YELLOW<<"\n\n\nRules:\n1. Two Player Game (Red {"<<RED<<"R"<<YELLOW<<"} & Blue {"<<BLUE<<"B"<<YELLOW<<"})\n2. Board Size is 6 rows x 7 Columns.\n3. A player wins if he/she is able to connect 4 dots horizontally, vertically or diagonally.\n4. Its a Draw if the board is fully filled.\n\n\nHow To Play:\n1. Game will always start with player-1 i.e. Red(R)\n2. In each turn choose the column number in which you want to drop the ball.\n3. rows will be filled from bottom to top in every column.\n\n\n";
}

void WelcomeScreen :: GameStartAscii() {
  cout<<RED;
  printAscii("GameStarts.txt");
  cout << WHITE << "\n\n";
}

void WelcomeScreen :: GameEndAscii() {
  cout<<RED;
  printAscii("GameEnd.txt");
  cout << WHITE << "\n\n";
}