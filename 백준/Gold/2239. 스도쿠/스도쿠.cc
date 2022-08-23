#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int m[10][10];
bool xline[10][10] = { 0 };
bool yline[10][10]= { 0 };
bool box[10][10]= { 0 };

bool flag = false;

void solve(int x,int y) {
	int dx, dy;

	if (!m[y][x]) {
		for (int i = 1; i <= 9; i++) {
			if (xline[y][i]) {
				continue;
			}
			if (yline[x][i]) {
				continue;
			}
			if (box[((x-1) / 3) + ((y-1) / 3) * 3][i]) {
				continue;
			}
			if (x == 9) {

				dx = 1;
				dy = y+1;
			}
			else {

				dx = x + 1;
				dy = y;
			}
			xline[y][i] = true;
			yline[x][i] = true;
			box[((x-1) / 3) + ((y-1) / 3) * 3][i] = true;
			if (x != 9 || y != 9) {
				m[y][x] = i;
				solve(dx, dy);
				if (flag) {
					return;
				}
				m[y][x] = 0;
			}
			else {
				m[y][x] = i;
				flag = true;
			}
			xline[y][i] = false;
			yline[x][i] = false;
			box[((x-1) / 3) + ((y-1) / 3) * 3][i] = false;
		}
	}
	else {
		if (x == 9) {

			dx = 1;
			dy = y + 1;
		}
		else {

			dx = x + 1;
			dy = y;
		}
		if (x != 9 || y != 9) {
			solve(dx, dy);
		}
		else {
			flag = true;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a;
	int n;
	for (int i = 1; i <= 9; i++) {
		cin >> a;
		for (int j = 9; j >= 1; j--) {
			n = a % 10;
			m[i][j] = n;
			a /= 10;
		}

	}


	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (m[i][j]) {
				xline[i][m[i][j]] = true;
				yline[j][m[i][j]] = true;
				box[((j-1)/3)+((i-1)/3)*3][m[i][j]] = true;
			}
		}
	}

	solve(1, 1);


	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << m[i][j];
			
		}
		cout << "\n";
	}

}