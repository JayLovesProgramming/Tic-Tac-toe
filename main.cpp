#include <iostream>
using namespace std;

//9 is the number of numbers? 
//We cant use '' here, try to use ' in C++ for now
char board[9] = {
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
};


// Display the game board
void displayBoard() {
	cout << ' ' << board[0] << ' | ' << board[1] << ' | ' << board[2] << endl;
	cout << "--- | --- | --- " << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "--- | --- | --- " << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Get player 
void playerTurn(char player) {
	int choice;
	cout << "Player " << player << ", enter a number (1-9) to mark your position: ";
	cin >> choice;

	// Adjust for 0-based index
	choice--;

	// Ensure the spot is not already taken
	if (board[choice] != 'X' && board[choice] != '0') {
		board[choice] = player;
	}
	else {
		cout << "Invalid move, try again" << endl;
		playerTurn(player);
	}
}

// A bool - true or false



// A simple func to check if you win
bool checkWin() {
	// Winning combos
	int winCombinations[8][3] = {
		{0, 1, 3}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6} , {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};

	for (auto& combo : winCombinations) {
		if (board[combo[0]] == board[combo[1]] &&
			board[combo[1]] == board[combo[2]]) {
			return true;
		}
		return false;
	}
}

bool checkTie() {
	for (int i = 0; i < 9; i++) {
		if (board[i] != 'X' && board[i] != 'O') {
			return false;
		}
		return true;
	}
}


int main() {
	char currentPlayer = 'X';
	bool gameWon = false;

	while (!gameWon && !checkTie()) {
		displayBoard();
		playerTurn(currentPlayer);
		gameWon = checkWin();
		if (!gameWon) {
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