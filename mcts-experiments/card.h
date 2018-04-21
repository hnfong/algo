#pragma once

struct PlayingCard {
    const static int NUM_SUITS = 4;
    const static int NUM_RANKS = 13;
    const static int TOTAL_CARDS = NUM_SUITS * NUM_RANKS;

    PlayingCard(char suit_, char rank_, unsigned char mode_) : suit(suit_), rank(rank_), mode(mode_) {};

    const char suit;
    const char rank;
    const char nul = '\0';  // for printing the suit and rank together.
    const unsigned char mode = 0;  // 0 for poker, 1 for big2

    bool operator==(const PlayingCard &x) const {
        return suit == x.suit && rank == x.rank;
    }

    bool operator<(const PlayingCard &x) const {
        return getValue() < x.getValue();
    }

    const char *str() {
        return &suit;
    }

    int getValue() const;
    static PlayingCard fromValue(int v, unsigned char mode);

    const static int POKER_MODE = 0;
    const static int BIGTWO_MODE = 1;

    static const PlayingCard SORTED_BIGTWO_DECK[TOTAL_CARDS];
};

static inline PlayingCard PokerCard(char suit, char rank) {
    return PlayingCard(suit, rank, 0);
}

static inline PlayingCard BigTwoCard(char suit, char rank) {
    return PlayingCard(suit, rank, 1);
}

static inline PlayingCard PokerCard(int pokerValue) {
    return PlayingCard::fromValue(pokerValue, 0);
}

static inline PlayingCard BigTwoCard(int bigTwoValue) {
    return PlayingCard::fromValue(bigTwoValue, 1);
}
