// 3-19-2021 author: Seyoun Vishakan
//sudoku.txt regular easy sudoku
//sudoku0.txt copy paste into new sudoku txts since its just a blank sudoku
//sudoku1.txt used for testing 
//sudoku2.txt used for testing
//sudokuw.txt this is where the finished sudoku will be sent
//board[x][y] x is vertical y is horizontal
#include <iostream>
#include <fstream> //file stuffs
#include <string>
#include <sstream>

using namespace std;

void printBoard(int** board) {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int isLegal(int** board) {
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
				test = board[v][h] - 1;
				listForTest[test]++;
				if (listForTest[test] > 1) {
					return 0;
				}
			}
		}

	}
	for (h = 0; h < 9; h++) {
		for (i = 0; i < 9; i++) {
			listForTest[i] = 0;
		}
		for (v = 0; v < 9; v++) {
			if (board[v][h] != 0) {
				test = board[v][h] - 1;
				listForTest[test]++;
				if (listForTest[test] > 1) {
					return 0;
				}
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
						test = board[3 * v + i][3 * h + j] - 1;
						listForTest[test]++;
						if (listForTest[test] > 1) {
							return 0;
						}
					}
				}
			}
		}

	}
	return 1;
}

void backtrack(int** board, int** board01) {
	int v, h;
	int i, j;
	int counter = 0;
	int emptyTiles[81];
	int solved = 0;
	int temp;
	int iterations = 0;

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
		if (current == counter) {
			solved = 1;
			break;
		}
		temp = emptyTiles[current];
		if (board[temp / 9][temp % 9] == 9) {
			board[temp / 9][temp % 9] = 0;
			current--;
			continue;
		}
		board[temp / 9][temp % 9]++;
		if (isLegal(board)) {
			current++;
		}
		iterations++;
	}
	cout << iterations << " iterations" << endl << endl;

}


int main() {
	//string is the info that will be read from the file and ifstream is for reading the file
	ifstream fin;
	string line;
	//defining 2d array here 
	int** board;
	board = new int* [10];
	for (int i = 0; i < 10; i++) {
		board[i] = new int[10];
	}
	int** board01;
	board01 = new int* [10];
	for (int i = 0; i < 10; i++) {
		board01[i] = new int[10];
	}
	int i, j = 0;
	int temp;
	int repList[9];
	int opNum;
	int timer = 0;
	int finished = 0;
	//reading file
	fin.open("sudoku.txt");
	while (getline(fin, line)) {
		stringstream linestream(line);
		string data;
		int val[9];
		int i;
		linestream >> val[0] >> val[1] >> val[2] >> val[3] >> val[4] >> val[5] >> val[6] >> val[7] >> val[8];
		for (i = 0; i < 9; i++) {
			board[j][i] = val[i];
		}
		j++;
	}
	/*
	//this is a way for me to see what the board looks like
	for (j = 0; j < 9; j++) {
		for (i = 0; i < 9; i++) {
			cout << board[j][i] << endl;
		}
	}
	*/
	fin.close();

	//print board
	printBoard(board);
	
	//solving
	backtrack(board, board01);

	printBoard(board);

	//writing to file

	ofstream fout;
	line = "";
	fout.open("sudokuw.txt");
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			line += to_string(board[i][j]);
			line += " ";
		}
		line += "\n";
	}
	fout << line << endl;
	fout.close();
	return 0;
}