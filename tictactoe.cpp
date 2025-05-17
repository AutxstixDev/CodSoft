#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool makeMove(char player) {
    char move;
    cout << "Player " << player << ", enter your move (1-9): ";
    cin >> move;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == move) {
                board[i][j] = player;
                return true;
            }

    cout << "? Invalid move! Try again.\n";
    return false;
}

bool checkWin(char p) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == p && board[i][1] == p && board[i][2] == p) ||
            (board[0][i] == p && board[1][i] == p && board[2][i] == p))
            return true;
    if ((board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
        (board[0][2] == p && board[1][1] == p && board[2][0] == p))
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char current = 'X';
    initBoard();

    while (true) {
        displayBoard();
        if (!makeMove(current)) continue;

        if (checkWin(current)) {
            displayBoard();
            cout << "?? Player " << current << " wins!\n";
            break;
        }

        if (checkDraw()) {
            displayBoard();
            cout << "?? It's a draw!\n";
            break;
        }

        current = (current == 'X') ? 'O' : 'X';
    }

    return 0;
}

