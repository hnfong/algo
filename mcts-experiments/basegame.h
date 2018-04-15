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
    GameState(int numPlayers_) {
        playerLastMoved = numPlayers_;
        numPlayers = numPlayers_;
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
        int result = (playerLastMoved + 1) % 2;
        if (result == 0) {  // one-based yuckiness
            result = 2;
        }
        return result;
    }

    virtual ~GameState() {
    }
  protected:
    void setNextPlayer() {
        playerLastMoved = nextPlayer();
    }

  private:
    int playerLastMoved;
    int numPlayers;
};

