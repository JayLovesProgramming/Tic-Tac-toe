#include <iostream>
#include <cstdlib> // For system()
using namespace std;

//void clearConsole() {
//    system("cls"); // For Windows
//    // For Linux/Mac, you can use: system("clear"), but considering we are on Winodws this works fine above;
//}

char board[9] = {
    '1', '2', '3', '4', '5', '6', '7', '8', '9',
};

// Display the game board
void displayBoard() {
    cout << "Displaying board..." << endl;
    cout << ' ' << board[0] << ' | ' << board[1] << ' | ' << board[2] << endl;
    cout << "Test";
    cout << "--- | --- | --- " << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "--- | --- | --- " << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Get player input and validate the move
void playerTurn(char player) {
    int choice;
    cout << "Player " << player << ", enter a number (1-9) to mark your position: ";
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cin >> choice;

    // Ensure input is within the valid range (1-9)
    if (choice < 1 || choice > 9) {
        cout << "Invalid choice, please enter a number between 1 and 9." << endl;
        playerTurn(player);
        return;
    }

    // Adjust for 0-based index
    choice--;

    // Ensure the spot is not already taken
    if (board[choice] != 'X' && board[choice] != 'O') {
        board[choice] = player;
    }
    else {
        cout << "Invalid move, the spot is already taken. Try again." << endl;
        playerTurn(player);
    }
}

// A simple function to check if a player has won
bool checkWin() {
    // Winning combos
    int winCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}  // Diagonals
    };

    for (auto& combo : winCombinations) {
        if (board[combo[0]] == board[combo[1]] &&
            board[combo[1]] == board[combo[2]]) {
            return true; // Return true if it's a win combo
        }
    }

    return false; // Return false if it's not a win combo
}

// A simple function to check if the game is a tie
bool checkTie() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false; // If any space is not taken, it's not a tie
        }
    }
    return true; // It's a tie if all spaces are taken
}

// Main loop
int main() {
    char currentPlayer = 'X';
    bool gameWon = false;

    while (!gameWon && !checkTie()) {
        displayBoard();
        playerTurn(currentPlayer);
        gameWon = checkWin();
        if (!gameWon && !checkTie()) {
            // Switch the player only if the game is still ongoing
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    displayBoard();

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
