#include "big2.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

#include "basegame.h"
#include "card.h"
#include "testcase.h"

using std::cout;
using std::endl;
using std::vector;

BigTwoGameState::BigTwoGameState(unsigned int seed) : GameState(BIG_TWO_PLAYERS) {
    assert(BIG_TWO_PLAYERS * MAX_HAND == PlayingCard::TOTAL_CARDS);

    int deck[PlayingCard::TOTAL_CARDS];
    for (int i = 0; i < PlayingCard::TOTAL_CARDS; i++) {
        deck[i] = PlayingCard::SORTED_BIGTWO_DECK[i].getValue();
    }

    // Somehow I have not been able to make shuffle work on PlayingCard objects.
    std::shuffle(deck, deck + PlayingCard::TOTAL_CARDS, std::default_random_engine(seed));

    initialize(deck);
}

void BigTwoGameState::initialize(int deck[]) {
    for (int i = 0; i < BIG_TWO_PLAYERS; i++) {
        for (int j = 0; j < MAX_HAND; j++) {
            hand[i][j] = deck[i * MAX_HAND + j];
        }
        handSize[i] = MAX_HAND;
    }

    // lastPlayPlayer = 1;  // TODO: diamond 3 first move
}

BigTwoGameState::BigTwoGameState() : BigTwoGameState((unsigned int)0) {}

// 52 * "{suit}{rank} "
BigTwoGameState::BigTwoGameState(const char *dumpFmt) : GameState(BIG_TWO_PLAYERS) {
    int N = strlen(dumpFmt);
    assert(N == NUM_PLAYERS * MAX_HAND * 3);

    assert(BIG_TWO_PLAYERS * MAX_HAND == PlayingCard::TOTAL_CARDS);
    int deck[PlayingCard::TOTAL_CARDS];

    for (int i = 0; i < N / 3; i ++) {
        assert(dumpFmt[i * 3 + 2] == ' ' || dumpFmt[i * 3 + 2] == '\n');
        deck[i] = BigTwoCard(dumpFmt[i * 3], dumpFmt[i * 3 + 1]).getValue();
    }

    initialize(deck);
}

GameState *BigTwoGameState::clone() {
    return new BigTwoGameState(*this);
}

void BigTwoGameState::display() {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < MAX_HAND; j++) {
            cout << BigTwoCard(hand[i][j]).str() << " ";
        }
        cout << endl;
    }
}

bool BigTwoGameState::play(GameChoice choice) {
    return true;
}

int BigTwoGameState::checkFinished() {
    return -1;
}

vector<GameChoice > BigTwoGameState::validNextMoves() {
    vector<GameChoice> result;

    // bool canPlayAnything = lastPlayPlayer == nextPlayer();

    // if (canPlayAnything ||


    return result;
}

int BigTwoGameState::suggestedRounds() {
    return 1000;
}

