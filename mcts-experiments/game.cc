#include <iostream>
#include <map>

#include "basegame.h"
#include "connect4.h"
#include "mcts.h"
#include "tictactoe.h"
#include "util.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;

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
