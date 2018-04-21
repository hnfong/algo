#pragma once

#include "basegame.h"
#include "card.h"

class BigTwoGameState : public GameState {
  public:
    BigTwoGameState();
    BigTwoGameState(unsigned int seed);
    BigTwoGameState(const char *board_);
    GameState *clone();
    void display();
    bool play(GameChoice choice);
    int checkFinished();
    std::vector<GameChoice > validNextMoves();
    int suggestedRounds();

  private:
    const static int BIG_TWO_PLAYERS = 4;
    const static int MAX_HAND = 13;
    int8_t hand[BIG_TWO_PLAYERS][MAX_HAND];
    int handSize[BIG_TWO_PLAYERS];

    void initialize(int deck[]);

    /*
    int lastPlayPlayer;
    MaxFiveCardSet lastPlay;
    */
};
