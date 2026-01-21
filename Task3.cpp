#include <iostream>
using namespace std;

char board[3][3];

void initializeBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = start++;
        }
    }
}

void displayBoard() {
    cout << "\n------ TIC TAC TOE ------\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

bool checkWinner(char player) {

    for (int i = 0; i < 3; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;


    for (int i = 0; i < 3; i++)
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;


    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    initializeBoard();
    char player = 'X';
    int choice;

    while (true) {
        displayBoard();

        cout << "\nPlayer " << player << ", enter a position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Position already taken! Choose another.\n";
            continue;
        }

        board[row][col] = player;

        if (checkWinner(player)) {
            displayBoard();
            cout << "\n🎉 Player " << player << " wins the game!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << "\nIt's a draw!\n";
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
