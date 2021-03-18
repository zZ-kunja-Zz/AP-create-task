#include <stdio.h>
#include <iostream>

using namespace std;

void wipeBoard(int** board, int** board2) {
	int v, h;
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			board2[v][h] = board2[v][h];
		}
	}
}

int isLegal(int** board, int** board01) {
	int h, v;
	int i, j;
	int test;
	int listForTest[9];
	for (v = 0; v < 9; v++) {
		for (i = 0; i < 9; i++) {
			listForTest[i] = 0;
		}
		for (h = 0; h < 9; h++) {
			if (board[v][h] != 0) {
				test = board[v][h];
				cout << test << endl;
				listForTest[--test]++;
			}
		}
		for (i = 0; i < 9; i++) {
			if (listForTest[i] > 1) {
				return 0;
			}
		}

	}
	for (h = 0; h < 9; h++) {
		for (i = 0; i < 9; i++) {
			listForTest[i] = 0;
		}
		for (v = 0; v < 9; v++) {
			if (board[v][h] != 0) {
				listForTest[--board[v][h]]++;
			}
		}
		for (i = 0; i < 9; i++) {
			if (listForTest[i] > 1) {
				return 0;
			}
		}
	}
	for (v = 0; v < 3; v++) {
		for (h = 0; h < 3; h++) {
			for (i = 0; i < 9; i++) {
				listForTest[i] = 0;
			}
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++) {
					if (board[3 * v + i][3 * h + j] != 0) {
						listForTest[--board[3 * v + i][3 * h + j]]++;
					}
				}
			}
			for (i = 0; i < 9; i++) {
				if (listForTest[i] > 1) {
					return 0;
				}
			}
		}

	}
	return 1;
}

void backtrack(int** board, int** board01, int** board2) {
	cout << "bruh" << endl;
	int v, h;
	int i, j;
	int counter = 0;
	int emptyTiles[81];
	int solved = 0;
	int temp;
	
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			if (board[v][h] == 0) {
				board01[v][h] = 0;
			}
			else {
				board01[v][h] = 1;
			}
		}
	}
	for (i = 0; i < 81; i++) {
		if (board01[i / 9][i % 9] == 0) {
			emptyTiles[counter] = i;
			counter++;
		}
	}
	int current = 0;
	while (solved != 1) {
		cout << "test" << endl;
		if (current == counter) {
			solved = 1;
			break;
		}
		temp = emptyTiles[current];
		if (board2[temp / 9][temp % 9] == 9) {
			board2[temp / 9][temp % 9] = 0;
			current--;
			continue;
		}
		board2[current / 9][current % 9]++;
		if (isLegal(board2, board01)) {
				current++;
		}
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << endl;
		}
	}
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			board[v][h] = board2[v][h];
		}
	}

}