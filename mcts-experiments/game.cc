#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;

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

    virtual vector<GameChoice > validNextMoves() = 0;
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

class TicTacToeGameState : public GameState {
  public:
    TicTacToeGameState() : GameState(2) {
        memset(board, 0, sizeof(board));
    }

    TicTacToeGameState(const char *board_) : GameState(2) {
        memcpy(board, board_, sizeof(board));
    }

    GameState *clone() {
        return new TicTacToeGameState(*this);
    }

    void display() {
        for (int i = 0; i < board_h; i++) {
            for (int j = 0; j < board_w; j++) {
                cout << (int)board[j][i];
            }
            cout << endl;
        }
        cout << "(Player " << nextPlayer() << " to move)" << endl;
    }

    bool play(GameChoice choice) {
        int x = choice.underlying() % 3;
        int y = choice.underlying() / 3;

        if (board[y][x] != 0) {
            return false;
        }
        board[y][x] = nextPlayer();
        setNextPlayer();
        return true;
    }

    int checkFinished() {
        int played = 0;
        for (int i = 0; i < board_w; i++) {
            for (int j = 0; j < board_h; j++) {
                if (board[j][i] != 0) {
                    if (sameFrom(i, j, 1, 0) || sameFrom(i, j, 0, 1) || sameFrom(i, j, 1, 1) || sameFrom(i, j, 1, -1)) {
                        return board[j][i];
                    }
                    played++;
                }
            }
        }

        if (played == 3*3) {
            return 0;
        }

        return -1;
    }

    vector<GameChoice > validNextMoves() {
        // display();
        vector<GameChoice> result;
        for (int i = 0; i < board_w; i++) {
            for (int j = 0; j < board_h; j++) {
                if (board[j][i] == 0) {
                    result.push_back(j * board_w + i);
                    // cout << "[" << j << "," << i << "] ";
                }
            }
        }
        // cout << endl;
        return result;
    }

    int suggestedRounds() {
        return 300;
    }

  private:
    const static int board_w = 3;
    const static int board_h = 3;
    char board[board_h][board_w];

    bool sameFrom(int x, int y, int dx, int dy) {
        int orig = board[y][x];

        for (int i = 1; i < 3; i++) {
            if (!((y+dy*i < board_h) && (x+dx*i < board_w))) {
                return false;
            }
            if (!((y+dy*i >= 0) && (x+dx*i >= 0))) {
                return false;
            }
            if (board[y+dy*i][x+dx*i] != orig) {
                return false;
            }
        }

        return true;
    }
};

class ConnectFourGameState : public GameState {
  public:
    ConnectFourGameState() : GameState(2) {
        memset(board, 0, sizeof(board));
        memset(heights, 0, sizeof(heights));
    }

    // https://groups.google.com/forum/?hl=en#!topic/comp.lang.c++/wBGBNl0yey8
    // https://stackoverflow.com/questions/4755105/making-a-copy-of-an-object-of-abstract-base-class
    GameState *clone() {
        return new ConnectFourGameState(*this);
    }

    void display() {
        for (int i = 0; i < board_h; i++) {
            for (int j = 0; j < board_w; j++) {
                cout << (int)board[board_h - i - 1][j];
            }

            cout << endl;
        }
        cout << "(Player " << nextPlayer() << " to move)" << endl;
    }

    bool play(GameChoice choice) {
        int col = choice.underlying();
        if (heights[col] == board_h) {
            return false;
        }

        board[heights[col]++][col] = nextPlayer();

        setNextPlayer();
        return true;
    }

    // XXX: it may return true on "connect five" cases. Is this a valid win position or not?
    int checkFinished() {
        // For each col, check whether each spot is a starting point for a winning four.
        for (int i = 0; i < board_w; i++) {
            for (int j = 0; j < heights[i]; j++) {
                if (sameFrom(i, j, 1, 0) || sameFrom(i, j, 0, 1) || sameFrom(i, j, 1, 1) || sameFrom(i, j, 1, -1)) {
                    return board[j][i];
                }
            }
        }

        int played = 0;
        for (int i = 0; i < board_w; i++) {
            played += heights[i];
        }

        if (played == board_w * board_h) {
            return 0;
        }

        return -1;
    }

    vector<GameChoice > validNextMoves() {
        vector<GameChoice > result;
        for (int i = 0; i < board_w; i++) {
            if (heights[i] < board_h) {
                result.push_back(i);
            }
        }

        return result;
    }

    int suggestedRounds() {
        return 3000;
    }

  private:
    const static int connect = 4;
    const static int board_w = 7;
    const static int board_h = 6;
    char board[board_h][board_w];
    int heights[board_w];

    bool sameFrom(int x, int y, int dx, int dy) {
        int orig = board[y][x];

        for (int i = 1; i < connect; i++) {
            if (!((y+dy*i < board_h) && (x+dx*i < board_w))) {
                return false;
            }
            if (!((y+dy*i >= 0) && (x+dx*i >= 0))) {
                return false;
            }
            if (board[y+dy*i][x+dx*i] != orig) {
                return false;
            }
        }

        return true;
    }
};

namespace util {
int randInt() {
    static std::random_device randDevice;
    static std::default_random_engine randEngine(randDevice());
    static std::uniform_int_distribution<int> uniform_dist;
    return uniform_dist(randEngine);
}
}  // namespace util

class MCTSNode {
  public:
    MCTSNode(MCTSNode &parent_, GameChoice choiceAppliedToParent) {
        state.reset(parent_.state->clone());  // copy and apply state
        state->play(choiceAppliedToParent);
        trials = 0;
        wins = 0;
        losses = 0;
    }

    MCTSNode(GameState *state_) {
        trials = 0;
        wins = 0;
        losses = 0;
        state.reset(state_);
    }

    // First return parameter is whether the ucb choice is based on all legal
    // moves being considered. (XXX: is this necessary actually?) Second return
    // parameter is the choice with maximum potential value.
    std::pair<bool, GameChoice > choose(bool useUcb = true, bool printDebug = false) {
        auto validNextMoves = state->validNextMoves();
        assert(validNextMoves.size() > 0);
        auto bestChoice = validNextMoves[0];

        if (validNextMoves.size() == 1) {
            return std::make_pair(true, bestChoice);
        }

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
                cout << " - " << it->underlying() << ": mean=" << mean << ", " << 100.0 * candidate->wins / candidate->trials << " vs " << 100.0 * candidate->losses / candidate->trials << " (" << candidate->trials << ") ucb:" << std::sqrt(2.0 * std::log(trials) / (candidate->trials)) <<endl;
            }

            double upperBound = mean + (useUcb ? ucb : 0);
            if (upperBound > best) {
                best = upperBound;
                bestChoice = *it;
            }
        }

        return std::make_pair(valid, bestChoice);
    }

    // Returns the eventual winner for this playout, 0 if draw
    int playout() {
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

    void simulate(int numPlayouts) {
        while (numPlayouts-- > 0) {
            playout();
        }
    }

    // This is a weird implementation indeed... XXX: we will leak memory if we
    // forget to destroy stuff here, even if we add them to destructor. a
    // better way may be to return a shared_ptr of the newState and then really
    // just destroy everything in the map (which needs to use shared_ptr as
    // well).
    void enter(GameChoice choice) {
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

    ~MCTSNode() {
        for (auto it = choiceMap.begin(); it != choiceMap.end(); it++) {
            delete it->second;
        }
    }

    std::shared_ptr<GameState> state;
  private:
    int trials;
    int wins;
    int losses;
    map<GameChoice, MCTSNode*> choiceMap;
};

namespace cli {
void interactive() {
    map<int, GameState*> gameMap;
    gameMap[1] = new TicTacToeGameState();
    gameMap[2] = new ConnectFourGameState();

    int which;
    while (gameMap.count(which) == 0) {
        cout << "Choose game: " << endl;
        cout << "1. TicTacToe" << endl;
        cout << "2. Connect-Four" << endl;
        cin >> which;
    }

    MCTSNode g(gameMap[which]);
    g.state->display();
    while (true) {
        if (g.state->nextPlayer() == 1) {
            cout << "Your move, choose a move" << endl;
            cin >> which;
        } else {
            g.simulate(g.state->suggestedRounds());
            which = g.choose(false).second.underlying();
            cout << "Player 2 chose: " << which << endl;
        }
        g.enter(GameChoice(which));
        g.state->display();
        int fin = g.state->checkFinished();
        if (fin != -1) {
            cout << "Game finished, winner: " << fin << endl;
            break;
        }
    }
}
}  // namespace cli


int main() {
    cli::interactive();
    return 0;
}
