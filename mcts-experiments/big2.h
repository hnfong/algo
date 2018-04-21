#pragma once

#include "basegame.h"
#include "card.h"

struct BigTwoCard : public PlayingCard {
    BigTwoCard(char suit, char rank) : PlayingCard(suit, rank) {}
    int getValue() const;
    static BigTwoCard fromValue(int v);

    bool operator<(const BigTwoCard &x) const {
        return getValue() < x.getValue();
    }
};

class BigTwoGameState : public GameState {
  public:
    BigTwoGameState();
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
    int8_t hands[BIG_TWO_PLAYERS][MAX_HAND];  // suits: diamond=0, club=1, heart=2, spade=3   |||  ranks: 3=3, 4=4, 5=5, 6=6, 7=7, 8=8, 9=9, T=10, J=11, Q=12, K=13, A=14, 2=15
    int handSize[BIG_TWO_PLAYERS];
};
