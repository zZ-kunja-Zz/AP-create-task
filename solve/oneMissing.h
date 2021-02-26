#include <iostream>

using namespace std;

int horizontal(int x, int board[9][9]) {
	int num = 45;
	int place;
	int i;
	for (i = 0; i < 9; i++) {
		num -= board[x][i];
		if (board[x][i] == 0) {
			place = i;
		}
	}
	board[x][place] = num;
	return board[9][9];
}
int vertical(int x, int board[9][9]) {
	int num = 45;
	int place;
	int i;
	for (i = 0; i < 9; i++) {
		num -= board[i][x];
		if (board[i][x] == 0) {
			place = i;
		}
	}
	board[place][x] = num;
	return board[9][9];
}
int box(int x, int board[9][9]) {
	int num = 45;
	int place1;
	int place2;
	int i, j;
	for (i = 3 * x; i < 3 * x + 3; i++) {
		for (j = 3 * x; j < 3 * x + 3; j++) {
			num -= board[i][j];
			if (board[i][j] == 0) {
				place1 = i;
				place2 = j;
			}
		}
	}
	board[place1][place2] = num;
	return board[9][9];
}

int oneMissing(int board[9][9]) {
	int h, v;
	int i, j;
	int zeroCountHor[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int zeroCountVer[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int zeroCountBox[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
			board[9][9] = horizontal(i, board);
		}
	}
	for (i = 0; i < 9; i++) {
		if (zeroCountVer[i] == 1) {
			board[9][9] = vertical(i, board);
		}
	}
	for (i = 0; i < 9; i++) {
		if (zeroCountBox[i] == 1) {
			board[9][9] = box(i, board);
		}
	}
	return board[9][9];
}
