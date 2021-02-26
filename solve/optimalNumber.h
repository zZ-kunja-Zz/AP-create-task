#include <iostream>
 
using namespace std;

int optimalNumber(int board[9][9], int *z) {
	int h, v, x;
	int i, j;
	int big, num, binary = 0;
	int numCon[9]; //number concentration
	for (i = 0; i < 9; i++) {
		numCon[i] = 0;
	}
	for (v = 0; v < 9; v++) {
		for (h = 0; h < 9; h++) {
			x = board[v][h];
			if (x > 0) {
				numCon[--x]++;
			}
		}
	}
	num = 0;
	for (j = 1; j < 9; j++) {
		if (numCon[j] < 9 && binary == 0) {
			big = numCon[j];
			num = j + 1;
			binary = 1;
		}
		if (numCon[j] > big) {
			big = numCon[j];
			num = j + 1;

		}
	}
	*z = big;
	return num;
}
