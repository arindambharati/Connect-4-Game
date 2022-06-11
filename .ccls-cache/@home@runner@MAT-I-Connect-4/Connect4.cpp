#include "Connect4.h"
#include <bits/stdc++.h>
using namespace std;


Connect4 :: Connect4(){
  isGameOver = false;
}


int Connect4 :: getInput() {
  return input;
}

void Connect4 :: setInput(int value) {
  input = value;  
}

void Connect4 :: update() {
  int playerIndex = 0;
  int totalPlayers = players.getTotalPlayers();
  int col = board.getMaxColumn();
  
  
  while(isGameOver == false) {
    char playerCharacter = players.selectPlayerCharacter(playerIndex);
    int playedMove = players.makeMove(playerCharacter);
    
    if(playedMove == 0 || playedMove > col) {
      cout<<"\n\nYou made a wrong move!! Out of Range Move!!\n\n";
      continue;
    } 

    board.playGame(playedMove,playerCharacter);    

    if(board.getRowNumber() == -1) {
      cout<<"\n\nThe column is filled!! Please change the column number!\n\n";
      continue;
    }
    
    if(board.checkGameOver() == true) 
      isGameOver = true;
    
    playerIndex = (playerIndex + 1) % totalPlayers;
  }

}

void Connect4 :: run() {
  while(!isGameOver) {
      update();
    } 
}
