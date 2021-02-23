#include <iostream>
#include <fstream> //file stuffs
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream fin;
	string line;
	vector <string> tokens;
	int board[9][9]; //9 rows by 9 columns
	int i;
	fin.open("sudoku.txt");
	while (fin) {
		getline(fin, line);
		cout << line << endl;


	}
	fin.close();

	return 0;
}
