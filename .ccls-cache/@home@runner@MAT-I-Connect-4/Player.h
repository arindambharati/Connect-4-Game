#pragma once
#include <iostream>
using namespace std;

class Player {
  private:
    int totalPlayers;

  public:
    Player();

    int getTotalPlayers();
    int makeMove(char);
    char selectPlayerCharacter(int);
};