#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

int pic[50][50];
int n, m;
int r, c, d;
int result = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

bool simul() {
	if (pic[c][r] == 0) {
		pic[c][r] = 2;
		result++;
		return true;
	}

	bool back = true;

	for (int i = 0; i < 4; i++) {
		int ddx = r + dx[i];
		int ddy = c + dy[i];
		if (ddx >= 0 && ddy >= 0 && ddx < m && ddy < n) {
			if (pic[ddy][ddx] == 0) {
				back = false;
			}
		}
	}

	if (back) {
		int dddx = r + dx[d];
		int dddy = c + dy[d];
		if (dddx >= 0 && dddy >= 0 && dddx < m && dddy < n) {
			if (pic[dddy][dddx] == 0) {
				r = dddx;
				c = dddy;
				return true;
			}
			if (pic[dddy][dddx] == 2) {
				r = dddx;
				c = dddy;
				return true;
			}
			else {
				return false;
			}
		}
	}
	
	d++;
	d %= 4;
	int dddx = r + dx[(d+2)%4];
	int dddy = c + dy[(d+2)%4];
	if (dddx >= 0 && dddy >= 0 && dddx < m && dddy < n) {
		if (pic[dddy][dddx] == 0) {
			r = dddx;
			c = dddy;
		}
	}

	return true;

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >>c>>r>>d;
	if (d == 1 || d == 3) {
		d = (d + 2) % 4;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> pic[i][j];
		}
	}

	while (simul());

	cout << result;


}