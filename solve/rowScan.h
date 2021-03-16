#include <iostream>

using namespace std;

void rowScan(int** board) {
	int h, v;
	int i, j, k;
	int num;
	int boardPos[9][9][9];
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			for (k = 0; k < 9; k++) {
				boardPos[i][j][k] = 1;
			}
		}
	}
	//does horizontal then vertical
	for (num = 0; num < 9; num++) {
		for (v = 0; v < 9; v++) {
			for (h = 0; h < 9; h++) {
				if (board[v][h] == 0) {
					for (i = 0; i < 9; i++) {
						if (board[i][h] == num) {
							boardPos[i][j][num] = 0;
						}
					}
				}
			}
		}
	}
}
