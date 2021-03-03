//finished 3/17 author: Seyoun Vishakan
//sudoku.txt regular easy sudoku
//sudoku1.txt used for testing the oneMissing function
#include <iostream>
#include <fstream> //file stuffs
#include <string>
#include <sstream>
#include "optimalNumber.h"
#include "oneMissing.h"

using namespace std;


int main() {
	ifstream fin;
	string line;
	int** board;
	board = new int* [10];
	for (int i = 0; i < 10; ++i) {
		board[i] = new int[10];
	}
	int i, j = 0;
	int temp;
	int z;
	int opNum;
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
	//this is a way for me to test what the sudoku values are
	for (j = 0; j < 9; j++) {
		for (i = 0; i < 9; i++) {
			cout << board[j][i] << endl;
		}
	}
	*/
	fin.close();

	//cout << optimalNumber(board, &z) << endl;
	opNum = optimalNumber(board, &z);
	switch (z) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		oneMissing(board);
		break;
	}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}