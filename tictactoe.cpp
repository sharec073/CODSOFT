//TASK-3 TIC-TAC-TOE GAME
#include <iostream>
using namespace std;
//Functions
void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
void switchPlayer(char &currentPlayer);
bool playAgain();
//To initialize the game board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        board[i][j] = ' ';
    }
    }
}
//To display the current state of the game board
void displayBoard(const char board[3][3]) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
    for (int j = 0; j < 3; ++j) {
        cout << board[i][j] << " ";
    }
        cout << endl;
    }
}
//To make move on the game board
bool makeMove(char board[3][3], char player, int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
    return false; 
    }
    board[row][col] = player;
    return true;
}
//To check if the current player as won 
bool checkWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
    //Row win
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
    return true; 
    }
    //Column win
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
    return true; 
    }
    }
    //Diagonal win (top left to bottom right)
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true; 
    }
    //Diagonal win (top right to bottom left)
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true; 
    }
    //No win
    return false; 
}
//To check if the game is draw
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
    //Empty space found (No draw)
    if (board[i][j] == ' ') {
    return false; 
    }
    }
    }
    //The board is full (Game Draw)
    return true; 
}
//To switch players
void switchPlayer(char &currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
//To ask player if they want yo play again
bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
//Main function
int main() {
    char currentPlayer = 'X';
    char board[3][3];
    cout<<"Come on...Let's play Tic-Tac-Toe..."<<endl;
    do {
        initializeBoard(board);
    while (true) {
            displayBoard(board);
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (makeMove(board, currentPlayer, row, col)) {
            if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
            } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
            } else {
            switchPlayer(currentPlayer);
            }
            } else {
            cout << "Invalid move. Try again.\n";
            }
        }
    } while (playAgain());
    return 0;
}