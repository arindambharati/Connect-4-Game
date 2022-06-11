#include "Player.h"
#include <iostream>
using namespace std;

Player :: Player() {
  totalPlayers = 2;
}

int Player :: getTotalPlayers() {
  return totalPlayers;
}


char Player :: selectPlayerCharacter(int playerIndex) {
  char character;
  if(playerIndex == 0) {
    character = 'R';
  } else {
    character = 'B';
  }
  return character;
} 

int Player :: makeMove(char playerCharacter) {
  int col;
  string playerColor;
  if(playerCharacter == 'R') {
    playerColor = "Red";
  }

  if(playerCharacter == 'B') {
    playerColor = "Blue";
  }
  
  std::cout<<"\n\nEnter the column number to push " << playerColor << " Player : ";
  std::cin>>col;
  return col;
}
