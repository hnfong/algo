#pragma once

#include <map>
#include <memory>  // for shared_ptr

#include "basegame.h"

class MCTSNode {
  public:
    MCTSNode(MCTSNode &parent_, GameChoice choiceAppliedToParent);
    MCTSNode(GameState *state_);

    // First return parameter is whether the ucb choice is based on all legal
    // moves being considered. (XXX: is this necessary actually?) Second return
    // parameter is the choice with maximum potential value.
    std::pair<bool, GameChoice > choose(bool useUcb = true, bool printDebug = false);

    // Returns the eventual winner for this playout, 0 if draw
    int playout();

    void simulate(int numPlayouts);

    void enter(GameChoice choice);

    ~MCTSNode();

    std::shared_ptr<GameState> state;
  private:
    int trials;
    int wins;
    int losses;
    std::map<GameChoice, MCTSNode*> choiceMap;
};
