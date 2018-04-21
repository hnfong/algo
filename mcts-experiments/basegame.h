#pragma once

#include <vector>

template <class T>
class GameChoiceT {
  public:
    GameChoiceT(T choice_) {  // This can probably be private, but who cares for now...
        choice = choice_;
    }

    T underlying() {
        return choice;
    }

    bool operator<(const GameChoiceT<T>& b) const {
        return choice < b.choice;
    }
  private:
    T choice;
};

typedef GameChoiceT<int> GameChoice;

class GameState {  // Abstract class.
  public:
    GameState(int numPlayers_) : NUM_PLAYERS(numPlayers_) {
        playerLastMoved = numPlayers_;
    }

    virtual void display() = 0;
    virtual bool play(GameChoice choice) = 0;

    /**
     * Returns:
     * winning player (1+) if somebody won
     * 0 if draw
     * -1 if not yet finished
     */
    virtual int checkFinished() = 0;

    virtual std::vector<GameChoice > validNextMoves() = 0;
    virtual GameState *clone() = 0;
    virtual int suggestedRounds() = 0;

    int lastMovedPlayer() {
        return playerLastMoved;
    }

    int nextPlayer() {
        int result = (playerLastMoved + 1) % NUM_PLAYERS;
        if (result == 0) {  // one-based yuckiness
            result = NUM_PLAYERS;
        }
        return result;
    }

    virtual ~GameState() {
    }
  protected:
    void setNextPlayer() {
        playerLastMoved = nextPlayer();
    }
    const int NUM_PLAYERS;
  private:
    int playerLastMoved;
};

