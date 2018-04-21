#include "card.h"

#include "testcase.h"

#include <iostream>

int PokerCard::getValue() const {
    int sVal;
    switch (suit) {
        case 'C': sVal = 0; break;
        case 'D': sVal = 1; break;
        case 'H': sVal = 2; break;
        case 'S': sVal = 3; break;
        default: return -1;
    }

    int rVal;
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
    return rVal * NUM_SUITS + sVal;
}

PokerCard PokerCard::fromValue(int v) {
    static char suitLabel[NUM_SUITS] = {'C', 'D', 'H', 'S'};

    int vRank = v / NUM_SUITS;
    char r;
    switch (vRank) {
        case 10: r = 'T'; break;
        case 11: r = 'J'; break;
        case 12: r = 'Q'; break;
        case 13: r = 'K'; break;
        case 14: r = 'A'; break;
        default:
            r = vRank + '0';
            break;
    }

    return PokerCard(suitLabel[v % NUM_SUITS], r);
}

class CardTestCase : public TestCase {
    const char *name() { return "Poker test"; }

    int run() {
        TEST(PokerCard::fromValue(PokerCard('C', '2').getValue()) == PokerCard('C', '2'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '3').getValue()) == PokerCard('C', '3'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '4').getValue()) == PokerCard('C', '4'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '5').getValue()) == PokerCard('C', '5'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '6').getValue()) == PokerCard('C', '6'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '7').getValue()) == PokerCard('C', '7'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '8').getValue()) == PokerCard('C', '8'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', '9').getValue()) == PokerCard('C', '9'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', 'T').getValue()) == PokerCard('C', 'T'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', 'J').getValue()) == PokerCard('C', 'J'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', 'Q').getValue()) == PokerCard('C', 'Q'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', 'K').getValue()) == PokerCard('C', 'K'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('C', 'A').getValue()) == PokerCard('C', 'A'), "Cannot round trip");

        TEST(PokerCard::fromValue(PokerCard('D', '2').getValue()) == PokerCard('D', '2'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '3').getValue()) == PokerCard('D', '3'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '4').getValue()) == PokerCard('D', '4'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '5').getValue()) == PokerCard('D', '5'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '6').getValue()) == PokerCard('D', '6'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '7').getValue()) == PokerCard('D', '7'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '8').getValue()) == PokerCard('D', '8'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', '9').getValue()) == PokerCard('D', '9'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', 'T').getValue()) == PokerCard('D', 'T'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', 'J').getValue()) == PokerCard('D', 'J'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', 'Q').getValue()) == PokerCard('D', 'Q'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', 'K').getValue()) == PokerCard('D', 'K'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('D', 'A').getValue()) == PokerCard('D', 'A'), "Cannot round trip");

        TEST(PokerCard::fromValue(PokerCard('H', '2').getValue()) == PokerCard('H', '2'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '3').getValue()) == PokerCard('H', '3'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '4').getValue()) == PokerCard('H', '4'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '5').getValue()) == PokerCard('H', '5'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '6').getValue()) == PokerCard('H', '6'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '7').getValue()) == PokerCard('H', '7'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '8').getValue()) == PokerCard('H', '8'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', '9').getValue()) == PokerCard('H', '9'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', 'T').getValue()) == PokerCard('H', 'T'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', 'J').getValue()) == PokerCard('H', 'J'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', 'Q').getValue()) == PokerCard('H', 'Q'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', 'K').getValue()) == PokerCard('H', 'K'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('H', 'A').getValue()) == PokerCard('H', 'A'), "Cannot round trip");

        TEST(PokerCard::fromValue(PokerCard('S', '2').getValue()) == PokerCard('S', '2'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '3').getValue()) == PokerCard('S', '3'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '4').getValue()) == PokerCard('S', '4'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '5').getValue()) == PokerCard('S', '5'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '6').getValue()) == PokerCard('S', '6'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '7').getValue()) == PokerCard('S', '7'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '8').getValue()) == PokerCard('S', '8'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', '9').getValue()) == PokerCard('S', '9'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', 'T').getValue()) == PokerCard('S', 'T'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', 'J').getValue()) == PokerCard('S', 'J'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', 'Q').getValue()) == PokerCard('S', 'Q'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', 'K').getValue()) == PokerCard('S', 'K'), "Cannot round trip");
        TEST(PokerCard::fromValue(PokerCard('S', 'A').getValue()) == PokerCard('S', 'A'), "Cannot round trip");

        TEST(PokerCard::fromValue(PokerCard('C', '2').getValue()) < PokerCard('D', '2'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '3').getValue()) < PokerCard('D', '3'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '4').getValue()) < PokerCard('D', '4'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '5').getValue()) < PokerCard('D', '5'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '6').getValue()) < PokerCard('D', '6'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '7').getValue()) < PokerCard('D', '7'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '8').getValue()) < PokerCard('D', '8'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', '9').getValue()) < PokerCard('D', '9'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', 'T').getValue()) < PokerCard('D', 'T'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', 'J').getValue()) < PokerCard('D', 'J'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', 'Q').getValue()) < PokerCard('D', 'Q'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', 'K').getValue()) < PokerCard('D', 'K'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('C', 'A').getValue()) < PokerCard('D', 'A'), "Wrong ordering");

        TEST(PokerCard::fromValue(PokerCard('D', '2').getValue()) < PokerCard('H', '2'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '3').getValue()) < PokerCard('H', '3'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '4').getValue()) < PokerCard('H', '4'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '5').getValue()) < PokerCard('H', '5'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '6').getValue()) < PokerCard('H', '6'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '7').getValue()) < PokerCard('H', '7'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '8').getValue()) < PokerCard('H', '8'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', '9').getValue()) < PokerCard('H', '9'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', 'T').getValue()) < PokerCard('H', 'T'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', 'J').getValue()) < PokerCard('H', 'J'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', 'Q').getValue()) < PokerCard('H', 'Q'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', 'K').getValue()) < PokerCard('H', 'K'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('D', 'A').getValue()) < PokerCard('H', 'A'), "Wrong ordering");

        TEST(PokerCard::fromValue(PokerCard('H', '2').getValue()) < PokerCard('S', '2'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '3').getValue()) < PokerCard('S', '3'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '4').getValue()) < PokerCard('S', '4'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '5').getValue()) < PokerCard('S', '5'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '6').getValue()) < PokerCard('S', '6'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '7').getValue()) < PokerCard('S', '7'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '8').getValue()) < PokerCard('S', '8'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', '9').getValue()) < PokerCard('S', '9'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', 'T').getValue()) < PokerCard('S', 'T'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', 'J').getValue()) < PokerCard('S', 'J'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', 'Q').getValue()) < PokerCard('S', 'Q'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', 'K').getValue()) < PokerCard('S', 'K'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('H', 'A').getValue()) < PokerCard('S', 'A'), "Wrong ordering");

        TEST(PokerCard::fromValue(PokerCard('S', '2').getValue()) < PokerCard('C', '3'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '3').getValue()) < PokerCard('C', '4'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '4').getValue()) < PokerCard('C', '5'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '5').getValue()) < PokerCard('C', '6'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '6').getValue()) < PokerCard('C', '7'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '7').getValue()) < PokerCard('C', '8'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '8').getValue()) < PokerCard('C', '9'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', '9').getValue()) < PokerCard('C', 'T'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', 'T').getValue()) < PokerCard('C', 'J'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', 'J').getValue()) < PokerCard('C', 'Q'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', 'Q').getValue()) < PokerCard('C', 'K'), "Wrong ordering");
        TEST(PokerCard::fromValue(PokerCard('S', 'K').getValue()) < PokerCard('C', 'A'), "Wrong ordering");

        return numErrors == 0;
    }
};

namespace {
TestCase *tc1 = TestCase::registerTest(new CardTestCase());
}  // anonymous namespace
