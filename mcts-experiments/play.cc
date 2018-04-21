#include <iostream>
#include <map>

#include "basegame.h"
#include "big2.h"
#include "connect4.h"
#include "mcts.h"
#include "tictactoe.h"
#include "util.h"
#include "testcase.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;

namespace cli {
void interactive() {
    map<int, GameState*> gameMap;
    gameMap[1] = new TicTacToeGameState();
    gameMap[2] = new ConnectFourGameState();
    gameMap[3] = new BigTwoGameState();

    int which = 0;
    while (gameMap.count(which) == 0) {
        cout << "Choose game: " << endl;
        cout << "0. Run tests" << endl;
        cout << "1. TicTacToe" << endl;
        cout << "2. Connect-Four" << endl;
        cout << "3. Big Two" << endl;
        if (!(cin >> which)) {
            return;
        }

        if (which == 0) {
            cout << "running tests" << endl;
            TestCase::runTests();
        }
    }

    MCTSNode g(gameMap[which]);
    g.state->display();
    while (true) {
        if (g.state->nextPlayer() == 1) {
            cout << "Your move, choose a move" << endl;
            cin >> which;
        } else {
            g.simulate(g.state->suggestedRounds());
            which = g.choose(false, true).second.underlying();
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
