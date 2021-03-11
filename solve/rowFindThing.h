#include <iostream>

using namespace std;
//x is the number its going to search for and stuff x will be inputted by optimal number im going to have to change that though since at the moment it sucks and is literally useless but it should be easy since the loop is already there and i dont need to do much

void rowFindThing(int x, int** board) {
	int h, v;
	int i, j, k;
	int xInBox[9];
	int counter;
	int change1, change2;
	int a, b;
	for (h = 0; h < 9; h += 3) {
		for (v = 0; v < 9; v += 3) {
			for (i = h; i < h + 3; i++) {
				for (j = v; j < v + 3; j++) {
					if (board[v][h] == x) {
						xInBox[h % 3 + 3 * (v % 3)]++;
						cout << h % 3 + 3 * (v % 3) << endl;
					}
				}
			}
		}
	}
	for (j = 1; j < 4; j++) {
		counter = 0;
		for (i = 1; i < 4; i++) {
			if (xInBox[i * j - 1] == 1) {
				counter++;
			}
			else {
				change1 = j;
				change2 = i;
			}
		}
		if (counter == 2) {
			a = 6 + 9 * (j - 1);
			for (k = 0; k < 3; k++) {
				if (xInBox[k] == 1) {
					for (v = 0; v < 3; v++) {
						for (h = 0; h < 3; h++) {
							if (board[v][h] == x) {
								a -= v + 1;
							}
						}
					}
				}
			}
			b = 6 + 9 * (j - 1);
			for (k = 0; k < 2; k++) {
				for (v = 0; v < 3; v++) {
					for (h = 0; h < 3; h++) {
						if (board[(v + 3 * k + 3 * (change1 - 1)) % 9][h + 3 * (change2 - 1)] == x) {
							b -= h + 1;
						}
					}
				}
			}
			board[a][b] = x;
		}
	}
}