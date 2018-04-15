#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

#include "mcts.h"
#include "util.h"

using std::cout;
using std::endl;

MCTSNode::MCTSNode(MCTSNode &parent_, GameChoice choiceAppliedToParent) {
    state.reset(parent_.state->clone());  // copy and apply state
    state->play(choiceAppliedToParent);
    trials = 0;
    wins = 0;
    losses = 0;
}

MCTSNode::MCTSNode(GameState *state_) {
    trials = 0;
    wins = 0;
    losses = 0;
    state.reset(state_);
}

std::pair<bool, GameChoice > MCTSNode::choose(bool useUcb, bool printDebug) {
    auto validNextMoves = state->validNextMoves();
    assert(validNextMoves.size() > 0);
    auto bestChoice = validNextMoves[0];

    if (validNextMoves.size() == 1) {
        return std::make_pair(true, bestChoice);
    }

    std::random_shuffle(validNextMoves.begin(), validNextMoves.end());

    double best = std::numeric_limits<double>::lowest();

    bool valid = true;

    for (auto it = validNextMoves.begin(); it != validNextMoves.end(); it++) {
        if (choiceMap.count(*it) == 0) {
            valid = false;
            continue;
        }

        auto candidate = choiceMap[*it];

        double ucb = std::sqrt(2.0 * std::log(trials) / (candidate->trials));
        double mean = (1.0 * candidate->wins - candidate->losses) / candidate->trials;

        if (printDebug) {
            cout << " - " << it->underlying() << ": mean=" << mean <<
                " win%=" << util::percent(1.0 * candidate->wins / candidate->trials) <<
                " loss%=" << util::percent(1.0 * candidate->losses / candidate->trials) <<
                " draw%=" << util::percent(1.0 * (candidate->trials - candidate->losses - candidate->wins) / candidate->trials) <<
                " trials=" << candidate->trials <<
                " ucb=" << ucb << endl;
        }

        double upperBound = mean + (useUcb ? ucb : 0);
        if (upperBound > best) {
            best = upperBound;
            bestChoice = *it;
        }
    }

    return std::make_pair(valid, bestChoice);
}

int MCTSNode::playout() {
    int fin = state->checkFinished();
    if (fin != -1) {
        trials++;
        if (fin == state->lastMovedPlayer()) {
            wins++;
        } else if (fin != 0) {
            losses++;
        }
        return fin;
    }

    auto ucb = choose();
    auto choice = ucb.second;
    MCTSNode *nextGameState = nullptr;

    if (!ucb.first) {  // ucb choice is not valid, we randomly choose
        auto valid = state->validNextMoves();
        choice = valid[util::randInt() % valid.size()];
    }

    if (choiceMap.count(choice) == 0) {
        auto x = new MCTSNode(*this, choice);
        assert(x != nullptr);
        choiceMap[choice] = x;
    }


    nextGameState = choiceMap[choice];
    fin = nextGameState->playout();
    trials++;
    if (fin == state->lastMovedPlayer()) {
        wins++;
    } else if (fin != 0) {
        losses++;
    }
    return fin;
}

void MCTSNode::simulate(int numPlayouts) {
    while (numPlayouts-- > 0) {
        playout();
    }
}

// This is a weird implementation indeed... XXX: we will leak memory if we
// forget to destroy stuff here, even if we add them to destructor. a
// better way may be to return a shared_ptr of the newState and then really
// just destroy everything in the map (which needs to use shared_ptr as
// well).
void MCTSNode::enter(GameChoice choice) {
    // Determine the new state, create if necessary
    MCTSNode *newState;
    if (choiceMap.count(choice) == 0) {
        newState = new MCTSNode(*this, choice);
    } else {
        newState = choiceMap[choice];
    }

    // Delete the choiceMap of the current state
    for (auto it = choiceMap.begin(); it != choiceMap.end(); it++) {
        if (it->second != newState) {
            delete it->second;
        }
    }

    // Replace contents of this with that.
    *this = *newState;

    // newState is now useless. "this" is now the new newState.
    newState->choiceMap.clear();
    delete newState;
}

MCTSNode::~MCTSNode() {
    for (auto it = choiceMap.begin(); it != choiceMap.end(); it++) {
        delete it->second;
    }
}
