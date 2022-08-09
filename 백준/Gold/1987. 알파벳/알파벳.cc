#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int r, c;

string* m;

int maxn = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void dfs(int len, int y, int x, bool* visit) {
	if (len > maxn) {
		maxn = len;
	}

	for (int i = 0; i < 4; i++) {
		int ddx = dx[i] + x;
		int ddy = dy[i] + y;
		if (ddx >= 0 && ddy >= 0 && ddx < c && ddy < r) {
			if (!visit[m[ddy][ddx] - 'A']) {
				visit[m[ddy][ddx] - 'A'] = true;
				dfs(len + 1, ddy, ddx, visit);
				visit[m[ddy][ddx] - 'A'] = false;
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> r >> c;

	m = new string[r];
	
	for (int i = 0; i < r; i++) {
		cin >> m[i];
	}

	bool alpha_visit['Z' - 'A'+1] = { false };
	alpha_visit[m[0][0] - 'A'] = true;
	dfs(1, 0, 0, alpha_visit);
	cout << maxn;




}