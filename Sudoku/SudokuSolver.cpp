#include <iostream>
using namespace std;

void backtrack(int[9][9], int, int);

int main() 
{
	int table[9][9];
	for (int i = 0; i < 9; i++) 
		for (int j = 0; j < 9; j++) 
			cin >> table[i][j];

	backtrack(table, 0, 0);
	cout << "No solution exists";

	return 0;
}
void backtrack(int table[9][9], int i, int j) 
{
	if (i == 9) {
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) 
				cout << table[row][col] << " ";
			cout << endl;
		}
		exit(0);
	}
	if (table[i][j] == 0) {
		for (int k = 1; k <= 9; k++) {
			int row = 0;
			for (; row < 9; row++) {
				if (table[row][j] == k) 
					break;
			}
			if (row != 9) 
				continue;

			int col = 0;
			for (; col < 9; col++) {
				if (table[i][col] == k) 
					break;
			}
			if (col != 9) 
				continue;

			if (i % 3 == 0) {
				if (j % 3 == 0) {
					if (table[i][j + 1] == k) 
						continue;
					if (table[i][j + 2] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
					if (table[i + 1][j + 1] == k) 
						continue;
					if (table[i + 1][j + 2] == k) 
						continue;
					if (table[i + 2][j] == k) 
						continue;
					if (table[i + 2][j + 1] == k) 
						continue;
					if (table[i + 2][j + 2] == k) 
						continue;
				}
				else if (j % 3 == 1) {
					if (table[i][j - 1] == k) 
						continue;
					if (table[i][j + 1] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
					if (table[i + 1][j + 1] == k) 
						continue;
					if (table[i + 1][j - 1] == k) 
						continue;
					if (table[i + 2][j] == k) 
						continue;
					if (table[i + 2][j + 1] == k) 
						continue;
					if (table[i + 2][j - 1] == k) 
						continue;
				}
				else {
					if (table[i][j - 1] == k) 
						continue;
					if (table[i][j - 2] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
					if (table[i + 1][j - 1] == k) 
						continue;
					if (table[i + 1][j - 2] == k) 
						continue;
					if (table[i + 2][j] == k) 
						continue;
					if (table[i + 2][j - 1] == k) 
						continue;
					if (table[i + 2][j - 2] == k) 
						continue;
				}
			}
			else if (i % 3 == 1) {
				if (j % 3 == 0) {
					if (table[i - 1][j] == k) 
						continue;
					if (table[i - 1][j + 1] == k) 
						continue;
					if (table[i - 1][j + 2] == k) 
						continue;
					if (table[i][j + 1] == k) 
						continue;
					if (table[i][j + 2] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
					if (table[i + 1][j + 1] == k) 
						continue;
					if (table[i + 1][j + 2] == k) 
						continue;
				}
				else if (j % 3 == 1) {
					if (table[i - 1][j - 1] == k) 
						continue;
					if (table[i - 1][j] == k) 
						continue;
					if (table[i - 1][j + 1] == k) 
						continue;
					if (table[i][j - 1] == k) 
						continue;
					if (table[i][j + 1] == k) 
						continue;
					if (table[i + 1][j - 1] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
					if (table[i + 1][j + 1] == k) 
						continue;
				}
				else {
					if (table[i - 1][j - 2] == k) 
						continue;
					if (table[i - 1][j - 1] == k) 
						continue;
					if (table[i - 1][j] == k) 
						continue;
					if (table[i][j - 2] == k) 
						continue;
					if (table[i][j - 1] == k) 
						continue;
					if (table[i + 1][j - 2] == k) 
						continue;
					if (table[i + 1][j - 1] == k) 
						continue;
					if (table[i + 1][j] == k) 
						continue;
				}
			}
			else {
				if (j % 3 == 0) {
					if (table[i - 2][j] == k) 
						continue;
					if (table[i - 2][j + 1] == k) 
						continue;
					if (table[i - 2][j + 2] == k) 
						continue;
					if (table[i - 1][j] == k) 
						continue;
					if (table[i - 1][j + 1] == k) 
						continue;
					if (table[i - 1][j + 2] == k) 
						continue;
					if (table[i][j + 1] == k) 
						continue;
					if (table[i][j + 2] == k) 
						continue;
				}
				else if (j % 3 == 1) {
					if (table[i - 2][j - 1] == k) 
						continue;
					if (table[i - 2][j] == k) 
						continue;
					if (table[i - 2][j + 1] == k) 
						continue;
					if (table[i - 1][j - 1] == k) 
						continue;
					if (table[i - 1][j + 1] == k) 
						continue;
					if (table[i - 1][j] == k) 
						continue;
					if (table[i][j - 1] == k) 
						continue;
					if (table[i][j + 1] == k) 
						continue;
				}
				else {
					if (table[i - 2][j - 2] == k) 
						continue;
					if (table[i - 2][j - 1] == k) 
						continue;
					if (table[i - 2][j] == k) 
						continue;
					if (table[i - 1][j - 2] == k) 
						continue;
					if (table[i - 1][j - 1] == k) 
						continue;
					if (table[i - 1][j] == k) 
						continue;
					if (table[i][j - 2] == k) 
						continue;
					if (table[i][j - 1] == k) 
						continue;
				}
			}
			table[i][j] = k;

			if (j != 8) 
				backtrack(table, i, j + 1);
			else 
				backtrack(table, i + 1, 0);

			table[i][j] = 0;
		}
		table[i][j] = 0;
	}
	else if (j != 8) 
		backtrack(table, i, j + 1);
	else 
		backtrack(table, i + 1, 0);
}

