#pragma once

struct PlayingCard {
    const static int NUM_SUITS = 4;
    const static int NUM_RANKS = 13;
    const static int TOTAL_CARDS = NUM_SUITS * NUM_RANKS;
    const static int RANK_A_VALUE = 14;

    PlayingCard() : suit('X'), rank('X'), mode(0) {}

    PlayingCard(char suit_, char rank_, unsigned char mode_) : suit(suit_), rank(rank_), mode(mode_) {};

    char suit;
    char rank;
    char nul = '\0';  // for printing the suit and rank together.
    unsigned char mode = 0;  // 0 for poker, 1 for big2

    bool operator==(const PlayingCard &x) const {
        return suit == x.suit && rank == x.rank;
    }

    bool operator<(const PlayingCard &x) const {
        return getValue() < x.getValue();
    }

    PlayingCard& operator= ( const PlayingCard& ) = default;

    const char *str() {
        return &suit;
    }

    int getValue() const;
    int rv() const;
    int sv() const;

    static PlayingCard fromValue(int v, unsigned char mode);

    const static int POKER_MODE = 0;
    const static int BIGTWO_MODE = 1;

    static const PlayingCard SORTED_BIGTWO_DECK[TOTAL_CARDS];
};

static_assert(sizeof(PlayingCard) == 4, "PlayingCard struct may be too large.");

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

namespace HR {
enum HandRank {
    Unknown = -1,
    Single = 0,  // Poker = High Card, No Pair, Nothing, etc.
    Pair = 1,
    TwoPair = 2,  // Not used in Big2.
    ThreeOfKind = 3,
    Straight = 4,
    Flush = 5,
    FullHouse = 6,
    FourOfKind = 7,
    StraightFlush = 8,
};
}  // namespace HR

struct MaxFiveCardSet {
    PlayingCard cards[5];
    PlayingCard rankCard;  // Significant card to compare cardsets if HandRank is the same. Usually the highest card, except in FullHouse
    unsigned char n;
    HR::HandRank hRank;

    MaxFiveCardSet() : n(0), hRank(HR::Unknown) {}

    MaxFiveCardSet(const char *dumpFmt, unsigned char mode);

    void insert(const PlayingCard &x);


    bool isStraightFlush() const;
    bool isStraight() const;
    bool isFlush() const;

    // Returns null if false, returns proper rankCard if true
    const PlayingCard* isFourKind() const;

    // Returns null if false, returns proper rankCard if true
    const PlayingCard* isFullHouse() const;

    // Returns null if false, returns proper rankCard if true
    const PlayingCard* isThreeKind() const;

    // TODO: Not implementing twopair

    // TODO: Partial implementation of pair
    const PlayingCard* isPair() const;

    // Returns a reference to *this for convenience.
    const MaxFiveCardSet& finalize();
};
