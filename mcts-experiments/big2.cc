#include "big2.h"

#include <cassert>
#include <iostream>
#include <vector>

#include "basegame.h"
#include "card.h"
#include "testcase.h"

using std::cout;
using std::endl;
using std::vector;

BigTwoGameState::BigTwoGameState() : GameState(BIG_TWO_PLAYERS) {
    memset(hands, 0, sizeof(hands));
    memset(handSize, 0, sizeof(handSize));
}

// 52 * "{suit}{rank} "
BigTwoGameState::BigTwoGameState(const char *dumpFmt) : GameState(2) {
    int N = strlen(dumpFmt);
    assert(N == NUM_PLAYERS * MAX_HAND * 3);
    for (int i = 0; i < N / 3; i ++) {
        assert(dumpFmt[i * 3 + 2] == ' ');
        hands[i / MAX_HAND][i % MAX_HAND] = BigTwoCard(dumpFmt[i * 3], dumpFmt[i * 3 + 1]).getValue();
    }
}

GameState *BigTwoGameState::clone() {
    return new BigTwoGameState(*this);
}

void BigTwoGameState::display() {
}

bool BigTwoGameState::play(GameChoice choice) {
    return true;
}

int BigTwoGameState::checkFinished() {
    return -1;
}

vector<GameChoice > BigTwoGameState::validNextMoves() {
    vector<GameChoice> result;
    return result;
}

int BigTwoGameState::suggestedRounds() {
    return 1000;
}

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

