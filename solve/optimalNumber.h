#include <iostream>
 
using namespace std;

void optimalNumber(int** board, int* repList) {
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
	for (i = 0; i < 9; i++) {
		repList[i] = numCon[i];
	}
}
