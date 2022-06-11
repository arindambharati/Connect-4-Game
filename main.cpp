#include "Connect4.h"
#include "WelcomeScreen.h"

#include <bits/stdc++.h>
using namespace std;



int main() {
  WelcomeScreen message;
  char startGame;
  cout<<"Press 'Y' to start the game or 'N' to end the game : ";
  cin>>startGame;
  if(startGame == 'Y' || startGame == 'y') {
    message.GameStartAscii();
    Connect4 game;
    game.run();
    startGame = 'E';
  } else if(startGame == 'N' || startGame == 'n' ) {
    startGame = 'E';
  } 

  if(startGame == 'E') {
    message.GameEndAscii();
  }
}