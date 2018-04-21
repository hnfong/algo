#pragma once

/**
 * Abstract class. For most purposes, PokerCard can be used.
 */
struct PlayingCard {
    const static int NUM_SUITS = 4;
    const static int NUM_RANKS = 13;
    const static int TOTAL_CARDS = NUM_SUITS * NUM_RANKS;

    PlayingCard(char suit_, char rank_) : suit(suit_), rank(rank_) {};

    const char suit;
    const char rank;
    const char nul = '\0';  // for printing the suit and rank together.

    virtual int getValue() const = 0;

    // XXX: big warning here, subclasses should not add fields without overloading this.
    virtual bool operator==(const PlayingCard &x) const {
        return suit == x.suit && rank == x.rank;
    }

    const char *str() {
        return &suit;
    }
};

struct PokerCard : public PlayingCard {
    PokerCard(char suit, char rank) : PlayingCard(suit, rank) {}
    int getValue() const;
    static PokerCard fromValue(int v);

    bool operator<(const PokerCard &x) const {
        return getValue() < x.getValue();
    }
};

/*
template <class CardType>
struct MaxFiveCardSet<CardType> {
    CardType cards[5];
};
*/
