#pragma once

#include "basegame.h"

class ConnectFourGameState : public GameState {
  public:
    ConnectFourGameState();
    GameState *clone();
    void display();
    bool play(GameChoice choice);
    int checkFinished();
    std::vector<GameChoice > validNextMoves();
    int suggestedRounds();

  private:
    const static int connect = 4;
    const static int board_w = 7;
    const static int board_h = 6;
    char board[board_h][board_w];
    int heights[board_w];

    bool sameFrom(int x, int y, int dx, int dy);
};

