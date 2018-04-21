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
    assert(BIG_TWO_PLAYERS * MAX_HAND == BigTwoCard::TOTAL_CARDS);

    int deck[BigTwoCard::TOTAL_CARDS];
    for (int i = 0; i < BigTwoCard::TOTAL_CARDS; i++) {
        deck[i] = BigTwoCard::SORTED_DECK[i].getValue();
    }

    // Somehow I have not been able to make shuffle work on PlayingCard objects.
    std::shuffle(deck, deck + BigTwoCard::TOTAL_CARDS, std::default_random_engine(seed));

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

    assert(BIG_TWO_PLAYERS * MAX_HAND == BigTwoCard::TOTAL_CARDS);
    int deck[BigTwoCard::TOTAL_CARDS];

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
            cout << BigTwoCard::fromValue(hand[i][j]).str() << " ";
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

const BigTwoCard BigTwoCard::SORTED_DECK[BigTwoCard::TOTAL_CARDS] = {
    BigTwoCard('D', 'A'), BigTwoCard('D', '2'), BigTwoCard('D', '3'), BigTwoCard('D', '4'), BigTwoCard('D', '5'), BigTwoCard('D', '6'), BigTwoCard('D', '7'), BigTwoCard('D', '8'), BigTwoCard('D', '9'), BigTwoCard('D', 'T'), BigTwoCard('D', 'J'), BigTwoCard('D', 'Q'), BigTwoCard('D', 'K'),
    BigTwoCard('C', 'A'), BigTwoCard('C', '2'), BigTwoCard('C', '3'), BigTwoCard('C', '4'), BigTwoCard('C', '5'), BigTwoCard('C', '6'), BigTwoCard('C', '7'), BigTwoCard('C', '8'), BigTwoCard('C', '9'), BigTwoCard('C', 'T'), BigTwoCard('C', 'J'), BigTwoCard('C', 'Q'), BigTwoCard('C', 'K'),
    BigTwoCard('H', 'A'), BigTwoCard('H', '2'), BigTwoCard('H', '3'), BigTwoCard('H', '4'), BigTwoCard('H', '5'), BigTwoCard('H', '6'), BigTwoCard('H', '7'), BigTwoCard('H', '8'), BigTwoCard('H', '9'), BigTwoCard('H', 'T'), BigTwoCard('H', 'J'), BigTwoCard('H', 'Q'), BigTwoCard('H', 'K'),
    BigTwoCard('S', 'A'), BigTwoCard('S', '2'), BigTwoCard('S', '3'), BigTwoCard('S', '4'), BigTwoCard('S', '5'), BigTwoCard('S', '6'), BigTwoCard('S', '7'), BigTwoCard('S', '8'), BigTwoCard('S', '9'), BigTwoCard('S', 'T'), BigTwoCard('S', 'J'), BigTwoCard('S', 'Q'), BigTwoCard('S', 'K'),
};

int BigTwoCard::getValue() const {
    int sVal;
    switch (suit) {
        case 'D': sVal = 0; break;
        case 'C': sVal = 1; break;
        case 'H': sVal = 2; break;
        case 'S': sVal = 3; break;
        default: return -1;
    }

    int rVal;
    switch (rank) {
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            rVal = rank - '0';
            break;
        case 'T': rVal = 10; break;
        case 'J': rVal = 11; break;
        case 'Q': rVal = 12; break;
        case 'K': rVal = 13; break;
        case 'A': rVal = 14; break;
        case '2': rVal = 15; break;
        default: return -1;
    }
    return rVal * NUM_SUITS + sVal;
}

BigTwoCard BigTwoCard::fromValue(int v) {
    static char suitLabel[NUM_SUITS] = {'D', 'C', 'H', 'S'};

    int vRank = v / NUM_SUITS;
    char r;
    switch (vRank) {
        case 10: r = 'T'; break;
        case 11: r = 'J'; break;
        case 12: r = 'Q'; break;
        case 13: r = 'K'; break;
        case 14: r = 'A'; break;
        case 15: r = '2'; break;
        default:
            r = vRank + '0';
            break;
    }

    return BigTwoCard(suitLabel[v % NUM_SUITS], r);
}


class BigTwoCardTestCase : public TestCase {
    const char *name() { return "Big2 test"; }

    int run() {
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '2').getValue()) == BigTwoCard('D', '2'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '3').getValue()) == BigTwoCard('D', '3'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '4').getValue()) == BigTwoCard('D', '4'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '5').getValue()) == BigTwoCard('D', '5'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '6').getValue()) == BigTwoCard('D', '6'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '7').getValue()) == BigTwoCard('D', '7'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '8').getValue()) == BigTwoCard('D', '8'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '9').getValue()) == BigTwoCard('D', '9'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'T').getValue()) == BigTwoCard('D', 'T'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'J').getValue()) == BigTwoCard('D', 'J'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'Q').getValue()) == BigTwoCard('D', 'Q'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'K').getValue()) == BigTwoCard('D', 'K'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'A').getValue()) == BigTwoCard('D', 'A'), "Cannot round trip");

        TEST(BigTwoCard::fromValue(BigTwoCard('C', '2').getValue()) == BigTwoCard('C', '2'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '3').getValue()) == BigTwoCard('C', '3'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '4').getValue()) == BigTwoCard('C', '4'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '5').getValue()) == BigTwoCard('C', '5'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '6').getValue()) == BigTwoCard('C', '6'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '7').getValue()) == BigTwoCard('C', '7'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '8').getValue()) == BigTwoCard('C', '8'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '9').getValue()) == BigTwoCard('C', '9'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'T').getValue()) == BigTwoCard('C', 'T'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'J').getValue()) == BigTwoCard('C', 'J'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'Q').getValue()) == BigTwoCard('C', 'Q'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'K').getValue()) == BigTwoCard('C', 'K'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'A').getValue()) == BigTwoCard('C', 'A'), "Cannot round trip");

        TEST(BigTwoCard::fromValue(BigTwoCard('H', '2').getValue()) == BigTwoCard('H', '2'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '3').getValue()) == BigTwoCard('H', '3'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '4').getValue()) == BigTwoCard('H', '4'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '5').getValue()) == BigTwoCard('H', '5'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '6').getValue()) == BigTwoCard('H', '6'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '7').getValue()) == BigTwoCard('H', '7'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '8').getValue()) == BigTwoCard('H', '8'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '9').getValue()) == BigTwoCard('H', '9'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'T').getValue()) == BigTwoCard('H', 'T'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'J').getValue()) == BigTwoCard('H', 'J'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'Q').getValue()) == BigTwoCard('H', 'Q'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'K').getValue()) == BigTwoCard('H', 'K'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'A').getValue()) == BigTwoCard('H', 'A'), "Cannot round trip");

        TEST(BigTwoCard::fromValue(BigTwoCard('S', '2').getValue()) == BigTwoCard('S', '2'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '3').getValue()) == BigTwoCard('S', '3'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '4').getValue()) == BigTwoCard('S', '4'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '5').getValue()) == BigTwoCard('S', '5'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '6').getValue()) == BigTwoCard('S', '6'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '7').getValue()) == BigTwoCard('S', '7'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '8').getValue()) == BigTwoCard('S', '8'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '9').getValue()) == BigTwoCard('S', '9'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'T').getValue()) == BigTwoCard('S', 'T'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'J').getValue()) == BigTwoCard('S', 'J'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'Q').getValue()) == BigTwoCard('S', 'Q'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'K').getValue()) == BigTwoCard('S', 'K'), "Cannot round trip");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'A').getValue()) == BigTwoCard('S', 'A'), "Cannot round trip");

        TEST(BigTwoCard::fromValue(BigTwoCard('D', '3').getValue()) < BigTwoCard('C', '3'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '4').getValue()) < BigTwoCard('C', '4'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '5').getValue()) < BigTwoCard('C', '5'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '6').getValue()) < BigTwoCard('C', '6'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '7').getValue()) < BigTwoCard('C', '7'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '8').getValue()) < BigTwoCard('C', '8'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '9').getValue()) < BigTwoCard('C', '9'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'T').getValue()) < BigTwoCard('C', 'T'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'J').getValue()) < BigTwoCard('C', 'J'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'Q').getValue()) < BigTwoCard('C', 'Q'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'K').getValue()) < BigTwoCard('C', 'K'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', 'A').getValue()) < BigTwoCard('C', 'A'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('D', '2').getValue()) < BigTwoCard('C', '2'), "Wrong ordering");

        TEST(BigTwoCard::fromValue(BigTwoCard('C', '3').getValue()) < BigTwoCard('H', '3'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '4').getValue()) < BigTwoCard('H', '4'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '5').getValue()) < BigTwoCard('H', '5'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '6').getValue()) < BigTwoCard('H', '6'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '7').getValue()) < BigTwoCard('H', '7'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '8').getValue()) < BigTwoCard('H', '8'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '9').getValue()) < BigTwoCard('H', '9'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'T').getValue()) < BigTwoCard('H', 'T'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'J').getValue()) < BigTwoCard('H', 'J'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'Q').getValue()) < BigTwoCard('H', 'Q'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'K').getValue()) < BigTwoCard('H', 'K'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', 'A').getValue()) < BigTwoCard('H', 'A'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('C', '2').getValue()) < BigTwoCard('H', '2'), "Wrong ordering");

        TEST(BigTwoCard::fromValue(BigTwoCard('H', '3').getValue()) < BigTwoCard('S', '3'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '4').getValue()) < BigTwoCard('S', '4'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '5').getValue()) < BigTwoCard('S', '5'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '6').getValue()) < BigTwoCard('S', '6'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '7').getValue()) < BigTwoCard('S', '7'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '8').getValue()) < BigTwoCard('S', '8'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '9').getValue()) < BigTwoCard('S', '9'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'T').getValue()) < BigTwoCard('S', 'T'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'J').getValue()) < BigTwoCard('S', 'J'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'Q').getValue()) < BigTwoCard('S', 'Q'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'K').getValue()) < BigTwoCard('S', 'K'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', 'A').getValue()) < BigTwoCard('S', 'A'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('H', '2').getValue()) < BigTwoCard('S', '2'), "Wrong ordering");

        TEST(BigTwoCard::fromValue(BigTwoCard('S', '3').getValue()) < BigTwoCard('D', '4'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '4').getValue()) < BigTwoCard('D', '5'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '5').getValue()) < BigTwoCard('D', '6'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '6').getValue()) < BigTwoCard('D', '7'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '7').getValue()) < BigTwoCard('D', '8'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '8').getValue()) < BigTwoCard('D', '9'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', '9').getValue()) < BigTwoCard('D', 'T'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'T').getValue()) < BigTwoCard('D', 'J'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'J').getValue()) < BigTwoCard('D', 'Q'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'Q').getValue()) < BigTwoCard('D', 'K'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'K').getValue()) < BigTwoCard('D', 'A'), "Wrong ordering");
        TEST(BigTwoCard::fromValue(BigTwoCard('S', 'A').getValue()) < BigTwoCard('D', '2'), "Wrong ordering");

        return numErrors == 0;
    }
};

namespace {
TestCase *tc2 = TestCase::registerTest(new BigTwoCardTestCase());
}  // anonymous namespace
