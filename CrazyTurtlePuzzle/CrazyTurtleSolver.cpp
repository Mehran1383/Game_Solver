#include <iostream>

using namespace std;

struct cards
{
	int states[4][4];
};

void backtracking(cards[], int[], int[][2], int);
void shift(int, int, int, int, int, cards[]);
bool check(int[][2], int, int, int, cards[]);

int main() 
{
	int used[9] = { 0,0,0,0,0,0,0,0,0 };
	int answer[9][2];
	cards card[9];

	card[0].states[0][0] = 4;
	card[0].states[0][1] = 3;
	card[0].states[0][2] = 6;
	card[0].states[0][3] = 3;
	shift(0, 4, 3, 6, 3, card);
	card[1].states[0][0] = 1;
	card[1].states[0][1] = 3;
	card[1].states[0][2] = 7;
	card[1].states[0][3] = 1;
	shift(1, 1, 3, 7, 1, card);
	card[2].states[0][0] = 1;
	card[2].states[0][1] = 4;
	card[2].states[0][2] = 0;
	card[2].states[0][3] = 7;
	shift(2, 1, 4, 0, 7, card);
	card[3].states[0][0] = 5;
	card[3].states[0][1] = 6;
	card[3].states[0][2] = 4;
	card[3].states[0][3] = 4;
	shift(3, 5, 6, 4, 4, card);
	card[4].states[0][0] = 0;
	card[4].states[0][1] = 2;
	card[4].states[0][2] = 3;
	card[4].states[0][3] = 6;
	shift(4, 0, 2, 3, 6, card);
	card[5].states[0][0] = 0;
	card[5].states[0][1] = 4;
	card[5].states[0][2] = 6;
	card[5].states[0][3] = 7;
	shift(5, 0, 4, 6, 7, card);
	card[6].states[0][0] = 2;
	card[6].states[0][1] = 6;
	card[6].states[0][2] = 4;
	card[6].states[0][3] = 5;
	shift(6, 2, 6, 4, 5, card);
	card[7].states[0][0] = 5;
	card[7].states[0][1] = 5;
	card[7].states[0][2] = 2;
	card[7].states[0][3] = 2;
	shift(7, 5, 5, 2, 2, card);
	card[8].states[0][0] = 7;
	card[8].states[0][1] = 5;
	card[8].states[0][2] = 2;
	card[8].states[0][3] = 0;
	shift(8, 7, 5, 2, 0, card);

	backtracking(card, used, answer, 0);

	return 0;
}
void shift(int p, int a, int b, int c, int d, cards card[9]) 
{
	for (int n = 0; n < 3; n++) {
		for (int i = 1; i < 4; i++) {
			card[p].states[i][0] = card[p].states[i - 1][3];
			for (int j = 1; j < 4; j++) 
				card[p].states[i][j] = card[p].states[i - 1][j - 1];
		}
	}
}
void backtracking(cards card[9], int used[], int answer[9][2], int dim) 
{
	if (dim == 9) {
		cout << endl << "----+----+-----" << endl;
		for (int i = 0;i <= 6; i += 3) {
			for (int j = i; j < i + 3; j++) 
				cout << answer[j][0] + 1 << "->" << answer[j][1] << "|";
			cout << endl << "----+----+-----" << endl;
		}
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (!used[i]) {
			for (int j = 0; j < 4; j++) {
				if (check(answer, i, j, dim, card)) {
					used[i] = 1;
					answer[dim][0] = i;
					answer[dim][1] = j;
					backtracking(card, used, answer, dim + 1);
					used[i] = 0;
				}
			}
		}
	}
}
bool check(int answer[9][2], int num, int st, int dim, cards card[9]) 
{
	int temp1, temp2;

	if (dim == 0) 
		return 1;
	if (dim == 1) {
		temp1 = abs(card[num].states[st][0] - card[answer[0][0]].states[answer[0][1]][2]);
		if (temp1 == 4) 
			return 1;
		return 0;
	}
	if (dim == 2) {
		temp1 = abs(card[num].states[st][0] - card[answer[1][0]].states[answer[1][1]][2]);
		if (temp1 == 4) 
			return 1;
		return 0;
	}
	if (dim == 3) {
		temp1 = abs(card[num].states[st][1] - card[answer[0][0]].states[answer[0][1]][3]);
		if (temp1 == 4) 
			return 1;
		return 0;
	}
	if (dim == 4) {
		temp1 = abs(card[num].states[st][0] - card[answer[3][0]].states[answer[3][1]][2]);
		temp2 = abs(card[num].states[st][1] - card[answer[1][0]].states[answer[1][1]][3]);
		if (temp1 == 4 && temp2 == 4) 
			return 1;
		return 0;
	}
	if (dim == 5) {
		temp1 = abs(card[num].states[st][0] - card[answer[4][0]].states[answer[4][1]][2]);
		temp2 = abs(card[num].states[st][1] - card[answer[2][0]].states[answer[2][1]][3]);
		if (temp1 == 4 && temp2 == 4) 
			return 1;
		return 0;
	}
	if (dim == 6) {
		temp1 = abs(card[num].states[st][1] - card[answer[3][0]].states[answer[3][1]][3]);
		if (temp1 == 4) 
			return 1;
		return 0;
	}
	if (dim == 7) {
		temp1 = abs(card[num].states[st][0] - card[answer[6][0]].states[answer[6][1]][2]);
		temp2 = abs(card[num].states[st][1] - card[answer[4][0]].states[answer[4][1]][3]);
		if (temp1 == 4 && temp2 == 4) 
			return 1;
		return 0;
	}
	if (dim == 8) {
		temp1 = abs(card[num].states[st][0] - card[answer[7][0]].states[answer[7][1]][2]);
		temp2 = abs(card[num].states[st][1] - card[answer[5][0]].states[answer[5][1]][3]);
		if (temp1 == 4 && temp2 == 4) 
			return 1;
		return 0;
	}
}