#include <stdio.h>

using namespace std;

int isLegal(int** board) {
	int h, v;
	int i, j;
	int listForTest[9];
	for (v = 0; v < 9; v++) {
		for (i = 0; i < 9; i++) {
			listForTest[i] = 0;
		}
		for (h = 0; h < 9; h++) {
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

void backtrack(int** board) {
	int h, v;
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			if (board[v][h] == 0)

		}
	}
}