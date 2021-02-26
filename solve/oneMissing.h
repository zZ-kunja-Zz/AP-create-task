#include <iostream>

using namespace std;

int horizontal(int i, int *board[9][9]) {
}

void oneMissing(int *board[9][9]) {
	int h, v;
	int i, j;
	int zeroCountHor[9];
	int zeroCountVer[9];
	int zeroCountBox[9];
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			if (board[v][h] == 0) {
				zeroCountHor[v]++;
			}
		}
	}
	for (h = 0; h < 9; h++) {
		for (v = 0; v < 9; v++) {
			if (board[v][h] == 0) {
					zeroCountVer[h]++;
			}
		}
	}
	for (h = 0; h < 9; h += 3) {
		for (v = 0; v < 9; v += 3) {
			for (i = h; i < h + 3; i++) {
				for (j = v; j < v + 3; j++) {
					if (board[v][h] == 0) {
							zeroCountBox[h % 3 + 3 * (v % 3)]++;
					}
				}
			}
		}
	}
	for (i = 0; i < 9; i++) {
		if (zeroCountHor[i] == 1) {
			horizontal(i, ptr);
		}
	}
}
// the way to do this is to get the 8 numbers and subtract them fron the sum of 1-9 im literally a genius 