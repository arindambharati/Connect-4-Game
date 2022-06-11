#pragma once
#include <bits/stdc++.h>
using namespace std;

class Board {
  private:
    //VARIABLE DECLARATION
    char** board;         //dynamic array initialization   //int* arr = new int[m * n];

    int maxRow;
    int maxColumn;
    int noOfConnects;
    int rowNumber;
    int columnFilled;

    bool gameOver;

    //FUNCTIONS
    void printColumnNumbers();
    void printBoard();
    void makeBoard();

    int placeMarker(int , char);
    int horizontalWinCheck(int,int,char);
    int verticalWinCheck(int,int,char);
    int diagonalWinCheck(int,int, int);
    int drawGameCheck();

    bool checkWinConditions(int,int,char);
    
  public:
    Board();
    ~Board();

    void playGame(int,char);

    int getMaxColumn();
    int getRowNumber();

    bool checkGameOver();
   
};