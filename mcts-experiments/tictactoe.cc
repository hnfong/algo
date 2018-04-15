#include <iostream>
#include <vector>

#include "basegame.h"
#include "tictactoe.h"

using std::cout;
using std::endl;
using std::vector;

TicTacToeGameState::TicTacToeGameState() : GameState(2) {
    memset(board, 0, sizeof(board));
}

TicTacToeGameState::TicTacToeGameState(const char *board_) : GameState(2) {
    memcpy(board, board_, sizeof(board));
}

GameState *TicTacToeGameState::clone() {
    return new TicTacToeGameState(*this);
}

void TicTacToeGameState::display() {
    for (int i = 0; i < board_h; i++) {
        for (int j = 0; j < board_w; j++) {
            cout << (int)board[j][i];
        }
        cout << endl;
    }
    cout << "(Player " << nextPlayer() << " to move)" << endl;
}

bool TicTacToeGameState::play(GameChoice choice) {
    int x = choice.underlying() % 3;
    int y = choice.underlying() / 3;

    if (board[y][x] != 0) {
        return false;
    }
    board[y][x] = nextPlayer();
    setNextPlayer();
    return true;
}

int TicTacToeGameState::checkFinished() {
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

vector<GameChoice > TicTacToeGameState::validNextMoves() {
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

int TicTacToeGameState::suggestedRounds() {
    return 1000;
}

bool TicTacToeGameState::sameFrom(int x, int y, int dx, int dy) {
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
