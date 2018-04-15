#pragma once

#include "basegame.h"

class TicTacToeGameState : public GameState {
  public:
    TicTacToeGameState();
    TicTacToeGameState(const char *board_);
    GameState *clone();
    void display();
    bool play(GameChoice choice);
    int checkFinished();
    std::vector<GameChoice > validNextMoves();
    int suggestedRounds();

  private:
    const static int board_w = 3;
    const static int board_h = 3;
    char board[board_h][board_w];
    bool sameFrom(int x, int y, int dx, int dy);
};
