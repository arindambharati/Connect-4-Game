#include "Board.h"
#include <iostream>

using namespace std;

#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */

Board :: Board() {
  //VARIABLE INITIALIZATION, MAKING && CALLING THE EMPTY BOARD
  maxRow = 6, maxColumn = 7;
  makeBoard();
  rowNumber = placeMarker(-1,' ');
  printBoard();
  noOfConnects = 0;
  columnFilled = 0;
  gameOver = false;
}

int Board :: getRowNumber() {
  return rowNumber;
}

int Board :: getMaxColumn() {
  return maxColumn;
}

void Board :: makeBoard() {
  board = new char*[maxRow];
  for(int i = 0; i < maxRow; i++) {
    board[i] = new char[maxColumn];
  }

  for( int i = 0; i < maxRow; i++ ) {
    for( int j = 0; j < maxColumn; j++ ) {   
        board[i][j] = ' ';
    }
  }
} 


void Board :: printColumnNumbers() {
    for(int i = 0; i < maxColumn; i++) {
        cout<<"|"<<i+1;    
    }
    cout<<"|"<<endl;

    for(int i = 0; i < maxColumn; i++) {
        cout<<" -";    
    }
    cout<<endl;
}

void Board :: printBoard() {
    cout<<endl;
    printColumnNumbers();
    for( int i = 0; i < maxRow; i++ ) {
      for( int j = 0; j < maxColumn; j++ ) {      
        cout<<WHITE<<"|";
        
        if(board[i][j] == 'R') {
          cout<<RED;
        } else if(board[i][j] == 'B') {
          cout<<BLUE;
        }
        
        cout<<board[i][j];
      }
      cout<<WHITE<<"|"<<endl;
    }

    for(int i = 0; i < maxColumn; i++) {
        cout<<" -";    
    }
    cout<<endl;
}

int Board:: placeMarker(int input, char playerCharacter) {  
  
  if( (board[0][input-1] != ' ') && (input != -1) ) {
    return -1;
  }
  
  int row;
  for(row = maxRow-1; row >= 0; row--) {
    if(board[row][input-1] == ' ') {
        board[row][input-1] = playerCharacter;
        break;
    }
  }
  
  return row;
}

void Board :: playGame(int input, char playerCharacter) {
  //play the game here
  rowNumber = placeMarker(input,playerCharacter); 
  if(rowNumber == -1) {
    return;
  }
  
  printBoard();  
  gameOver = checkWinConditions(rowNumber,input,playerCharacter);
}


int Board :: horizontalWinCheck (int rowNumber, int input, char playerCharacter) {
  noOfConnects = 0;
  
  for(int col = input-1; col < maxColumn; col++) {
    if(board[rowNumber][col] == playerCharacter) {
      noOfConnects++;
    } else { break; }
  }

  for(int col = input-2; col >= 0; col--) {
    if(board[rowNumber][col] == playerCharacter) {
      noOfConnects++;
      } else { break; }
  }

  return noOfConnects;
}


int Board :: verticalWinCheck(int rowNumber, int input, char playerCharacter) {
  noOfConnects = 0;
  
  for(int row = rowNumber; row < maxRow; row++) {
    if(board[row][input-1] == playerCharacter) {
      noOfConnects++;
    } else { break; }
  }

  return noOfConnects;
} 

int Board :: diagonalWinCheck(int rowNumber,int input, int playerCharacter) {
  noOfConnects = 0; 
  int col = input - 1;

  for(int row = rowNumber; row >= 0; row-- ) {
    if(board[row][col] == playerCharacter) {
      noOfConnects++;
      ++col;
    } else { break; }
  }
   

  col = input - 2;
  for(int row = rowNumber+1; row < maxRow; row++ ) {   
    if(board[row][col] == playerCharacter) {
      noOfConnects++;
      --col;
    } else { break; }
  }
  

  if(noOfConnects >= 4)  {
    return noOfConnects;
  } 

  noOfConnects = 0;

  col = input - 1;
  for(int row = rowNumber; row >= 0; row-- ) {
    if(board[row][col] == playerCharacter) {
      noOfConnects++;
      --col;
    } else { break; }
  }

  col = input;

  for(int row = rowNumber+1; row < maxRow; row++ ) {

    if(board[row][col] == playerCharacter) {
      noOfConnects++;
      ++col;
    } else { break; }
  }
    
  return noOfConnects;
}

int Board :: drawGameCheck() {
  ++columnFilled;
  return columnFilled;
}

bool Board :: checkWinConditions(int rowNumber, int input,char playerCharacter) {  
  string playerColor;
  if(playerCharacter == 'R') {
    playerColor = "Red";
  }

  if(playerCharacter == 'B') {
    playerColor = "Blue";
  }

  if( (drawGameCheck() >= maxRow*maxColumn ) && (gameOver!=true)) {
     cout<<"\n\nDraw Game!!\n\n";
    gameOver = true;
  }
  
  if(horizontalWinCheck(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\nHorizontal check win!! for " << playerColor << " Player\n\n";
    gameOver = true;
  }

  if(verticalWinCheck(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\nVertical check win!! for " << playerColor << " Player\n\n";
    gameOver = true;
  } 
  
  if(diagonalWinCheck(rowNumber,input,playerCharacter) >= 4 && (gameOver!=true)) {
    cout<<"\n\nDiagonal check win!! for " << playerColor << " Player\n\n";
    gameOver = true;
  } 
  
  return gameOver;
}


bool Board :: checkGameOver() {
  return gameOver;
}

Board :: ~Board() {
  delete[] board;
}