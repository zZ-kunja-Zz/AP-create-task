#include <iostream>
#include <fstream> //file stuffs
#include <string>
#include <sstream>
#include "optimalNumber.h"
#include "oneMissing.h"

using namespace std;

int optimalNumber(int board[9][9]);

int main() {
	ifstream fin;
	string line;
	int board[9][9]; //9 rows by 9 columns
	int i, j = 0;
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

	cout << optimalNumber(board) << endl;
	return 0;
}