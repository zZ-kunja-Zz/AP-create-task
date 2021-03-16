#include <iostream>

using namespace std;
//x is the number its going to search for and stuff x will be inputted by optimal number im going to have to change that though since at the moment it sucks and is literally useless but it should be easy since the loop is already there and i dont need to do much

void rowFindThing(int x, int** board) {
	int h, v;
	int i, j, k, n;
	int xInBox[9];
	int counter;
	int change1, change2;
	int a, b;
	for (i = 0; i < 9; i++) {
		xInBox[i] = 0;
	}
	for (h = 0; h < 9; h += 3) {

		for (v = 0; v < 9; v += 3) {
			for (i = h; i < h + 3; i++) {
				for (j = v; j < v + 3; j++) {
					if (board[j][i] == x) {
						xInBox[i / 3 + 3 * (j / 3)]++;
					}
				}
			}
		}
	}

	for (j = 0; j < 3; j++) {
		counter = 0;
		for (i = 0; i < 3; i++) {
			if (xInBox[3 * j + i] == 1) {
				counter++;
			}
			else {
				change1 = j;
				change2 = i;
			}
		}
		if (counter == 2) {
			a = 5;
				for (v = 0; v < 3; v++) {
					for (h = 0; h < 9; h++) {
						//cout << (change1 * 3 + v) % 9 << ' ' << h << endl;
						if (board[(change1 * 3 + v) % 9][h] == x) {
							
							a -= v + 1;
						}
					}
				}
			b = 5;
				for (v = 0; v < 9; v++) {
					for (h = 0; h < 3; h++) {
						//cout << v << ' ' << (change2 * 3 + h) % 9 << endl;
						if (board[v][(change2 * 3 + h) % 9] == x) {
							
							b -= h + 1;
						}
					}
				}
			//cout << a << ' ' << b << endl;
			a += 3 * change1;
			b += 3 * change2;
			board[a][b] = x;
		}
	}
}