#include <iostream>
#include <vector>

#include "connect4.h"

using std::cout;
using std::endl;
using std::vector;

ConnectFourGameState::ConnectFourGameState() : GameState(2) {
    memset(board, 0, sizeof(board));
    memset(heights, 0, sizeof(heights));
}

// https://groups.google.com/forum/?hl=en#!topic/comp.lang.c++/wBGBNl0yey8
// https://stackoverflow.com/questions/4755105/making-a-copy-of-an-object-of-abstract-base-class
GameState *ConnectFourGameState::clone() {
    return new ConnectFourGameState(*this);
}

void ConnectFourGameState::display() {
    for (int i = 0; i < board_h; i++) {
        for (int j = 0; j < board_w; j++) {
            cout << (int)board[board_h - i - 1][j];
        }

        cout << endl;
    }
    cout << "(Player " << nextPlayer() << " to move)" << endl;
}

bool ConnectFourGameState::play(GameChoice choice) {
    int col = choice.underlying();
    if (heights[col] == board_h) {
        return false;
    }

    board[heights[col]++][col] = nextPlayer();

    setNextPlayer();
    return true;
}

// XXX: it may return true on "connect five" cases. Is this a valid win position or not?
int ConnectFourGameState::checkFinished() {
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

vector<GameChoice > ConnectFourGameState::validNextMoves() {
    vector<GameChoice > result;
    for (int i = 0; i < board_w; i++) {
        if (heights[i] < board_h) {
            result.push_back(i);
        }
    }

    return result;
}

int ConnectFourGameState::suggestedRounds() {
    return 3000;
}

bool ConnectFourGameState::sameFrom(int x, int y, int dx, int dy) {
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

