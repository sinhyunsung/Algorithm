#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

int n, m, sx, sy, k;

int dice[4][3] = { 0 };

int pic[20][20];

void move(int direction) {
	int dx=sx, dy=sy;
	if (direction == 1)dx++;
	else if (direction == 2)dx--;
	else if (direction == 3)dy--;
	else if (direction == 4)dy++;
	if (dx < 0 || dy < 0 || dx >= m || dy >= n) {
		return;
	}

	switch(direction) {
		case 1:
			swap(dice[1][0], dice[1][1]);
			swap(dice[1][2], dice[3][1]);
			swap(dice[1][2], dice[1][0]);
			break;
		case 2:
			swap(dice[1][0], dice[1][1]);
			swap(dice[1][2], dice[3][1]);
			swap(dice[1][1], dice[3][1]);
			break;
		case 3:
			swap(dice[0][1], dice[1][1]);
			swap(dice[2][1], dice[3][1]);
			swap(dice[1][1], dice[3][1]);
			break;
		case 4:
			swap(dice[0][1], dice[1][1]);
			swap(dice[2][1], dice[3][1]);
			swap(dice[0][1], dice[2][1]);
			break;
	}

	sx = dx;
	sy = dy;

	if (pic[sy][sx] != 0) {
		dice[3][1] = pic[sy][sx];
		pic[sy][sx] = 0;
	}
	else {
		pic[sy][sx] = dice[3][1];
	}

	cout << dice[1][1] << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> sy >> sx >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pic[i][j];
		}
	}

	int command;
	for (int i = 0; i < k; i++) {
		cin >> command;
		move(command);
	}
}