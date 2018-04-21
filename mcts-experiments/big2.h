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

    const static BigTwoCard SORTED_DECK[BigTwoCard::TOTAL_CARDS];
};

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
