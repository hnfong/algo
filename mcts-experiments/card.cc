#include "card.h"

#include "testcase.h"

#include <cassert>
#include <iostream>

int PlayingCard::getValue() const {
    int sVal;
    if (mode == POKER_MODE) {
        switch (suit) {
            case 'C': sVal = 0; break;
            case 'D': sVal = 1; break;
            case 'H': sVal = 2; break;
            case 'S': sVal = 3; break;
            default: return -1;
        }
    } else if (mode == BIGTWO_MODE) {
        switch (suit) {
            case 'D': sVal = 0; break;
            case 'C': sVal = 1; break;
            case 'H': sVal = 2; break;
            case 'S': sVal = 3; break;
            default: return -1;
        }
    }

    int rVal;
    if (rank == '2' && mode == BIGTWO_MODE) {
        rVal = 15;
    } else {
        switch (rank) {
            case '2':
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
            default: return -1;
        }
    }
    return rVal * NUM_SUITS + sVal;
}

PlayingCard PlayingCard::fromValue(int v, unsigned char mode) {
    static char suitLabelPoker[NUM_SUITS] = {'C', 'D', 'H', 'S'};
    static char suitLabelBigTwo[NUM_SUITS] = {'D', 'C', 'H', 'S'};

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

    if (mode == POKER_MODE) {
        return PokerCard(suitLabelPoker[v % NUM_SUITS], r);
    } else if (mode == BIGTWO_MODE) {
        return BigTwoCard(suitLabelBigTwo[v % NUM_SUITS], r);
    } else {
        assert(false);
    }
}

class CardTestCase : public TestCase {
    const char *name() { return "Poker test"; }

    int run() {
        TEST(PokerCard(PokerCard('C', '2').getValue()) == PokerCard('C', '2'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '3').getValue()) == PokerCard('C', '3'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '4').getValue()) == PokerCard('C', '4'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '5').getValue()) == PokerCard('C', '5'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '6').getValue()) == PokerCard('C', '6'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '7').getValue()) == PokerCard('C', '7'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '8').getValue()) == PokerCard('C', '8'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', '9').getValue()) == PokerCard('C', '9'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', 'T').getValue()) == PokerCard('C', 'T'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', 'J').getValue()) == PokerCard('C', 'J'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', 'Q').getValue()) == PokerCard('C', 'Q'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', 'K').getValue()) == PokerCard('C', 'K'), "Cannot round trip");
        TEST(PokerCard(PokerCard('C', 'A').getValue()) == PokerCard('C', 'A'), "Cannot round trip");

        TEST(PokerCard(PokerCard('D', '2').getValue()) == PokerCard('D', '2'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '3').getValue()) == PokerCard('D', '3'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '4').getValue()) == PokerCard('D', '4'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '5').getValue()) == PokerCard('D', '5'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '6').getValue()) == PokerCard('D', '6'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '7').getValue()) == PokerCard('D', '7'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '8').getValue()) == PokerCard('D', '8'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', '9').getValue()) == PokerCard('D', '9'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', 'T').getValue()) == PokerCard('D', 'T'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', 'J').getValue()) == PokerCard('D', 'J'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', 'Q').getValue()) == PokerCard('D', 'Q'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', 'K').getValue()) == PokerCard('D', 'K'), "Cannot round trip");
        TEST(PokerCard(PokerCard('D', 'A').getValue()) == PokerCard('D', 'A'), "Cannot round trip");

        TEST(PokerCard(PokerCard('H', '2').getValue()) == PokerCard('H', '2'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '3').getValue()) == PokerCard('H', '3'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '4').getValue()) == PokerCard('H', '4'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '5').getValue()) == PokerCard('H', '5'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '6').getValue()) == PokerCard('H', '6'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '7').getValue()) == PokerCard('H', '7'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '8').getValue()) == PokerCard('H', '8'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', '9').getValue()) == PokerCard('H', '9'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', 'T').getValue()) == PokerCard('H', 'T'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', 'J').getValue()) == PokerCard('H', 'J'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', 'Q').getValue()) == PokerCard('H', 'Q'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', 'K').getValue()) == PokerCard('H', 'K'), "Cannot round trip");
        TEST(PokerCard(PokerCard('H', 'A').getValue()) == PokerCard('H', 'A'), "Cannot round trip");

        TEST(PokerCard(PokerCard('S', '2').getValue()) == PokerCard('S', '2'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '3').getValue()) == PokerCard('S', '3'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '4').getValue()) == PokerCard('S', '4'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '5').getValue()) == PokerCard('S', '5'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '6').getValue()) == PokerCard('S', '6'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '7').getValue()) == PokerCard('S', '7'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '8').getValue()) == PokerCard('S', '8'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', '9').getValue()) == PokerCard('S', '9'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', 'T').getValue()) == PokerCard('S', 'T'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', 'J').getValue()) == PokerCard('S', 'J'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', 'Q').getValue()) == PokerCard('S', 'Q'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', 'K').getValue()) == PokerCard('S', 'K'), "Cannot round trip");
        TEST(PokerCard(PokerCard('S', 'A').getValue()) == PokerCard('S', 'A'), "Cannot round trip");

        TEST(PokerCard(PokerCard('C', '2').getValue()) < PokerCard('D', '2'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '3').getValue()) < PokerCard('D', '3'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '4').getValue()) < PokerCard('D', '4'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '5').getValue()) < PokerCard('D', '5'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '6').getValue()) < PokerCard('D', '6'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '7').getValue()) < PokerCard('D', '7'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '8').getValue()) < PokerCard('D', '8'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', '9').getValue()) < PokerCard('D', '9'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', 'T').getValue()) < PokerCard('D', 'T'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', 'J').getValue()) < PokerCard('D', 'J'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', 'Q').getValue()) < PokerCard('D', 'Q'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', 'K').getValue()) < PokerCard('D', 'K'), "Wrong ordering");
        TEST(PokerCard(PokerCard('C', 'A').getValue()) < PokerCard('D', 'A'), "Wrong ordering");

        TEST(PokerCard(PokerCard('D', '2').getValue()) < PokerCard('H', '2'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '3').getValue()) < PokerCard('H', '3'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '4').getValue()) < PokerCard('H', '4'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '5').getValue()) < PokerCard('H', '5'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '6').getValue()) < PokerCard('H', '6'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '7').getValue()) < PokerCard('H', '7'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '8').getValue()) < PokerCard('H', '8'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', '9').getValue()) < PokerCard('H', '9'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', 'T').getValue()) < PokerCard('H', 'T'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', 'J').getValue()) < PokerCard('H', 'J'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', 'Q').getValue()) < PokerCard('H', 'Q'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', 'K').getValue()) < PokerCard('H', 'K'), "Wrong ordering");
        TEST(PokerCard(PokerCard('D', 'A').getValue()) < PokerCard('H', 'A'), "Wrong ordering");

        TEST(PokerCard(PokerCard('H', '2').getValue()) < PokerCard('S', '2'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '3').getValue()) < PokerCard('S', '3'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '4').getValue()) < PokerCard('S', '4'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '5').getValue()) < PokerCard('S', '5'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '6').getValue()) < PokerCard('S', '6'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '7').getValue()) < PokerCard('S', '7'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '8').getValue()) < PokerCard('S', '8'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', '9').getValue()) < PokerCard('S', '9'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', 'T').getValue()) < PokerCard('S', 'T'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', 'J').getValue()) < PokerCard('S', 'J'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', 'Q').getValue()) < PokerCard('S', 'Q'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', 'K').getValue()) < PokerCard('S', 'K'), "Wrong ordering");
        TEST(PokerCard(PokerCard('H', 'A').getValue()) < PokerCard('S', 'A'), "Wrong ordering");

        TEST(PokerCard(PokerCard('S', '2').getValue()) < PokerCard('C', '3'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '3').getValue()) < PokerCard('C', '4'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '4').getValue()) < PokerCard('C', '5'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '5').getValue()) < PokerCard('C', '6'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '6').getValue()) < PokerCard('C', '7'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '7').getValue()) < PokerCard('C', '8'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '8').getValue()) < PokerCard('C', '9'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', '9').getValue()) < PokerCard('C', 'T'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', 'T').getValue()) < PokerCard('C', 'J'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', 'J').getValue()) < PokerCard('C', 'Q'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', 'Q').getValue()) < PokerCard('C', 'K'), "Wrong ordering");
        TEST(PokerCard(PokerCard('S', 'K').getValue()) < PokerCard('C', 'A'), "Wrong ordering");

        return numErrors == 0;
    }
};

namespace {
TestCase *tc1 = TestCase::registerTest(new CardTestCase());
}  // anonymous namespace

const PlayingCard PlayingCard::SORTED_BIGTWO_DECK[PlayingCard::TOTAL_CARDS] = {
    BigTwoCard('D', 'A'), BigTwoCard('D', '2'), BigTwoCard('D', '3'), BigTwoCard('D', '4'), BigTwoCard('D', '5'), BigTwoCard('D', '6'), BigTwoCard('D', '7'), BigTwoCard('D', '8'), BigTwoCard('D', '9'), BigTwoCard('D', 'T'), BigTwoCard('D', 'J'), BigTwoCard('D', 'Q'), BigTwoCard('D', 'K'),
    BigTwoCard('C', 'A'), BigTwoCard('C', '2'), BigTwoCard('C', '3'), BigTwoCard('C', '4'), BigTwoCard('C', '5'), BigTwoCard('C', '6'), BigTwoCard('C', '7'), BigTwoCard('C', '8'), BigTwoCard('C', '9'), BigTwoCard('C', 'T'), BigTwoCard('C', 'J'), BigTwoCard('C', 'Q'), BigTwoCard('C', 'K'),
    BigTwoCard('H', 'A'), BigTwoCard('H', '2'), BigTwoCard('H', '3'), BigTwoCard('H', '4'), BigTwoCard('H', '5'), BigTwoCard('H', '6'), BigTwoCard('H', '7'), BigTwoCard('H', '8'), BigTwoCard('H', '9'), BigTwoCard('H', 'T'), BigTwoCard('H', 'J'), BigTwoCard('H', 'Q'), BigTwoCard('H', 'K'),
    BigTwoCard('S', 'A'), BigTwoCard('S', '2'), BigTwoCard('S', '3'), BigTwoCard('S', '4'), BigTwoCard('S', '5'), BigTwoCard('S', '6'), BigTwoCard('S', '7'), BigTwoCard('S', '8'), BigTwoCard('S', '9'), BigTwoCard('S', 'T'), BigTwoCard('S', 'J'), BigTwoCard('S', 'Q'), BigTwoCard('S', 'K'),
};

class BigTwoCardTestCase : public TestCase {
    const char *name() { return "Big2 test"; }

    int run() {
        TEST(BigTwoCard(BigTwoCard('D', '2').getValue()) == BigTwoCard('D', '2'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '3').getValue()) == BigTwoCard('D', '3'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '4').getValue()) == BigTwoCard('D', '4'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '5').getValue()) == BigTwoCard('D', '5'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '6').getValue()) == BigTwoCard('D', '6'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '7').getValue()) == BigTwoCard('D', '7'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '8').getValue()) == BigTwoCard('D', '8'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', '9').getValue()) == BigTwoCard('D', '9'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', 'T').getValue()) == BigTwoCard('D', 'T'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', 'J').getValue()) == BigTwoCard('D', 'J'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', 'Q').getValue()) == BigTwoCard('D', 'Q'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', 'K').getValue()) == BigTwoCard('D', 'K'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('D', 'A').getValue()) == BigTwoCard('D', 'A'), "Cannot round trip");

        TEST(BigTwoCard(BigTwoCard('C', '2').getValue()) == BigTwoCard('C', '2'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '3').getValue()) == BigTwoCard('C', '3'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '4').getValue()) == BigTwoCard('C', '4'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '5').getValue()) == BigTwoCard('C', '5'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '6').getValue()) == BigTwoCard('C', '6'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '7').getValue()) == BigTwoCard('C', '7'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '8').getValue()) == BigTwoCard('C', '8'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', '9').getValue()) == BigTwoCard('C', '9'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', 'T').getValue()) == BigTwoCard('C', 'T'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', 'J').getValue()) == BigTwoCard('C', 'J'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', 'Q').getValue()) == BigTwoCard('C', 'Q'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', 'K').getValue()) == BigTwoCard('C', 'K'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('C', 'A').getValue()) == BigTwoCard('C', 'A'), "Cannot round trip");

        TEST(BigTwoCard(BigTwoCard('H', '2').getValue()) == BigTwoCard('H', '2'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '3').getValue()) == BigTwoCard('H', '3'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '4').getValue()) == BigTwoCard('H', '4'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '5').getValue()) == BigTwoCard('H', '5'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '6').getValue()) == BigTwoCard('H', '6'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '7').getValue()) == BigTwoCard('H', '7'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '8').getValue()) == BigTwoCard('H', '8'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', '9').getValue()) == BigTwoCard('H', '9'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', 'T').getValue()) == BigTwoCard('H', 'T'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', 'J').getValue()) == BigTwoCard('H', 'J'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', 'Q').getValue()) == BigTwoCard('H', 'Q'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', 'K').getValue()) == BigTwoCard('H', 'K'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('H', 'A').getValue()) == BigTwoCard('H', 'A'), "Cannot round trip");

        TEST(BigTwoCard(BigTwoCard('S', '2').getValue()) == BigTwoCard('S', '2'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '3').getValue()) == BigTwoCard('S', '3'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '4').getValue()) == BigTwoCard('S', '4'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '5').getValue()) == BigTwoCard('S', '5'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '6').getValue()) == BigTwoCard('S', '6'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '7').getValue()) == BigTwoCard('S', '7'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '8').getValue()) == BigTwoCard('S', '8'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', '9').getValue()) == BigTwoCard('S', '9'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', 'T').getValue()) == BigTwoCard('S', 'T'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', 'J').getValue()) == BigTwoCard('S', 'J'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', 'Q').getValue()) == BigTwoCard('S', 'Q'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', 'K').getValue()) == BigTwoCard('S', 'K'), "Cannot round trip");
        TEST(BigTwoCard(BigTwoCard('S', 'A').getValue()) == BigTwoCard('S', 'A'), "Cannot round trip");

        TEST(BigTwoCard(BigTwoCard('D', '3').getValue()) < BigTwoCard('C', '3'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '4').getValue()) < BigTwoCard('C', '4'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '5').getValue()) < BigTwoCard('C', '5'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '6').getValue()) < BigTwoCard('C', '6'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '7').getValue()) < BigTwoCard('C', '7'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '8').getValue()) < BigTwoCard('C', '8'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '9').getValue()) < BigTwoCard('C', '9'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', 'T').getValue()) < BigTwoCard('C', 'T'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', 'J').getValue()) < BigTwoCard('C', 'J'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', 'Q').getValue()) < BigTwoCard('C', 'Q'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', 'K').getValue()) < BigTwoCard('C', 'K'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', 'A').getValue()) < BigTwoCard('C', 'A'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('D', '2').getValue()) < BigTwoCard('C', '2'), "Wrong ordering");

        TEST(BigTwoCard(BigTwoCard('C', '3').getValue()) < BigTwoCard('H', '3'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '4').getValue()) < BigTwoCard('H', '4'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '5').getValue()) < BigTwoCard('H', '5'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '6').getValue()) < BigTwoCard('H', '6'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '7').getValue()) < BigTwoCard('H', '7'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '8').getValue()) < BigTwoCard('H', '8'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '9').getValue()) < BigTwoCard('H', '9'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', 'T').getValue()) < BigTwoCard('H', 'T'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', 'J').getValue()) < BigTwoCard('H', 'J'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', 'Q').getValue()) < BigTwoCard('H', 'Q'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', 'K').getValue()) < BigTwoCard('H', 'K'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', 'A').getValue()) < BigTwoCard('H', 'A'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('C', '2').getValue()) < BigTwoCard('H', '2'), "Wrong ordering");

        TEST(BigTwoCard(BigTwoCard('H', '3').getValue()) < BigTwoCard('S', '3'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '4').getValue()) < BigTwoCard('S', '4'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '5').getValue()) < BigTwoCard('S', '5'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '6').getValue()) < BigTwoCard('S', '6'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '7').getValue()) < BigTwoCard('S', '7'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '8').getValue()) < BigTwoCard('S', '8'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '9').getValue()) < BigTwoCard('S', '9'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', 'T').getValue()) < BigTwoCard('S', 'T'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', 'J').getValue()) < BigTwoCard('S', 'J'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', 'Q').getValue()) < BigTwoCard('S', 'Q'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', 'K').getValue()) < BigTwoCard('S', 'K'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', 'A').getValue()) < BigTwoCard('S', 'A'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('H', '2').getValue()) < BigTwoCard('S', '2'), "Wrong ordering");

        TEST(BigTwoCard(BigTwoCard('S', '3').getValue()) < BigTwoCard('D', '4'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '4').getValue()) < BigTwoCard('D', '5'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '5').getValue()) < BigTwoCard('D', '6'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '6').getValue()) < BigTwoCard('D', '7'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '7').getValue()) < BigTwoCard('D', '8'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '8').getValue()) < BigTwoCard('D', '9'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', '9').getValue()) < BigTwoCard('D', 'T'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', 'T').getValue()) < BigTwoCard('D', 'J'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', 'J').getValue()) < BigTwoCard('D', 'Q'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', 'Q').getValue()) < BigTwoCard('D', 'K'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', 'K').getValue()) < BigTwoCard('D', 'A'), "Wrong ordering");
        TEST(BigTwoCard(BigTwoCard('S', 'A').getValue()) < BigTwoCard('D', '2'), "Wrong ordering");

        return numErrors == 0;
    }
};

namespace {
TestCase *tc2 = TestCase::registerTest(new BigTwoCardTestCase());
}  // anonymous namespace
