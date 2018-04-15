#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::vector;

template <class T>
class GameChoice {
  public:
    GameChoice(T choice_) {  // This can probably be private, but who cares for now...
        choice = choice_;
    }

    T underlying() {
        return choice;
    }

    std::string toString() {
        std::stringstream ss;
        ss << choice;  // This will not work if T becomes complicated.
        return ss.str();
    }

    bool operator<(const GameChoice<T>& b) const {
        return choice < b.choice;
    }
  private:
    T choice;
};

class GameState {
  public:
    GameState() {
        memset(board, 0, sizeof(board));
        memset(heights, 0, sizeof(heights));
        playerLastMoved = 2;
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

    bool play(GameChoice<int> choice) {
        int col = choice.underlying();
        if (heights[col] == board_h) {
            return false;
        }

        playerLastMoved = nextPlayer();

        board[heights[col]++][col] = playerLastMoved;
        return true;
    }

    /**
     * Returns:
     * winning player (1+) if somebody won
     * 0 if draw
     * -1 if not yet finished
     */
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

    vector<GameChoice<int> > validNextMoves() {
        vector<GameChoice<int> > result;
        for (int i = 0; i < board_w; i++) {
            if (heights[i] < board_h) {
                result.push_back(i);
            }
        }

        return result;
    }

  private:
    const static int connect = 4;
    const static int board_w = 7;
    const static int board_h = 6;
    char board[board_h][board_w];
    int heights[board_w];
    int playerLastMoved;

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

class MCTSGameState {
  public:
    MCTSGameState(MCTSGameState &parent_, GameChoice<int> choiceAppliedToParent) {
        state = parent_.state;  // copy and apply state
        state.play(choiceAppliedToParent);
        trials = 0;
        wins = 0;
        losses = 0;

        // cout << "Created game state: " << this << endl;
    }

    MCTSGameState() {
        trials = 0;
        wins = 0;
        losses = 0;
        state = GameState();
    }

    // First return parameter is whether the ucb choice is based on all legal
    // moves being considered. (XXX: is this necessary actually?) Second return
    // parameter is the choice with maximum potential value.
    std::pair<bool, GameChoice<int> > ucbChoice() {
        auto validNextMoves = state.validNextMoves();
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

            double ucb = std::sqrt(2.0 * std::log(trials) / candidate->wins);
            double mean = (1.0 * candidate->wins - candidate->losses) / candidate->trials;

            double upperBound = mean + ucb;
            if (upperBound > best) {
                best = upperBound;
                bestChoice = *it;
            }
        }

        return std::make_pair(valid, bestChoice);
    }

    // Returns the eventual winner for this playout, 0 if draw
    int playout() {
        int fin = state.checkFinished();
        if (fin != -1) {
            trials++;
            if (fin == state.lastMovedPlayer()) {
                wins++;
            } else if (fin != 0) {
                losses++;
            }
            return fin;
        }

        auto ucb = ucbChoice();
        auto choice = ucb.second;
        MCTSGameState *nextGameState = nullptr;

        if (!ucb.first) {  // ucb choice is not valid, we randomly choose
            auto valid = state.validNextMoves();
            choice = valid[rand() % valid.size()];
        }

        if (choiceMap.count(choice) == 0) {
            auto x = new MCTSGameState(*this, choice);
            assert(x != nullptr);
            choiceMap[choice] = x;
        }


        nextGameState = choiceMap[choice];
        fin = nextGameState->playout();
        trials++;
        if (fin == state.lastMovedPlayer()) {
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

    // This is a weird implementation indeed...
    void enter(GameChoice<int> choice) {
        MCTSGameState *newState;
        if (choiceMap.count(choice) == 0) {
            newState = new MCTSGameState(*this, choice);
        } else {
            newState = choiceMap[choice];
        }

        for (auto it = choiceMap.begin(); it != choiceMap.end(); it++) {
            if (it->second != newState) {
                delete it->second;
            }
        }

        *this = *newState;
        newState->choiceMap.clear();
        delete newState;
    }

    ~MCTSGameState() {
        // cout << "Deleting game state: " << this << endl;
        for (auto it = choiceMap.begin(); it != choiceMap.end(); it++) {
            delete it->second;
        }
    }

    GameState state;
  private:
    int trials;
    int wins;
    int losses;
    map<GameChoice<int>, MCTSGameState*> choiceMap;
};

namespace util {

template <class T>
std::string stringify(GameChoice<T> x) {
    return x.toString();
}

template <class T>
std::string join(vector<T> &v, std::string delim) {
    std::stringstream result;
    for (auto it = v.begin(); it != v.end(); it++) {
        result << stringify(*it);
        result << delim;
    }
    return result.str();
}

}  // util

namespace interface {
void interactive() {
    MCTSGameState g;
    g.state.display();
    while (true) {
        int which;
        if (g.state.nextPlayer() == 1) {
            cin >> which;
        } else {
            g.simulate(10000);
            which = g.ucbChoice().second.underlying();
            cout << "Player 2 chose: " << which << endl;
        }
        g.enter(GameChoice<int>(which));
        g.state.display();
        int fin = g.state.checkFinished();
        if (fin != -1) {
            cout << "Game finished, winner: " << fin << endl;
            break;
        }
    }
}
}  // namespace interface

int main() {
    interface::interactive();
    return 0;
}
