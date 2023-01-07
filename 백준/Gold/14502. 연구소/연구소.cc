#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m;

int a[8][8];

vector <pair<int, int>> virus;
vector <pair<int, int>> air;

int maxn = 0;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(pair<int, int> b1, pair<int, int> b2, pair<int, int> b3) {
	int b[8][8];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b[i][j] = a[i][j];
		}
	}

	b[b1.first][b1.second] = 1;
	b[b2.first][b2.second] = 1;
	b[b3.first][b3.second] = 1;

	deque<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push_back(virus[i]);
	}
	
	int nowx, nowy;

	while (!q.empty()) {
		nowx = q.front().second;
		nowy = q.front().first;
		q.pop_front();

		int ddx, ddy;
		for (int i = 0; i < 4; i++) {
			ddx = nowx + dx[i];
			ddy = nowy + dy[i];
			if (ddx >= 0 && ddx < m && ddy >= 0 && ddy < n) {
				if (b[ddy][ddx] == 0) {
					b[ddy][ddx] = 2;
					q.push_back(make_pair(ddy, ddx));
				}
			}
		}

	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 0) {
				result++;
			}
		}
	}

	if (maxn < result) {
		maxn = result;
	}
	



}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}else if (a[i][j] == 0) {
				air.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < air.size()-2; i++) {
		for (int j = i+1; j < air.size()-1; j++) {
			for (int k = j+1; k < air.size(); k++) {
				bfs(air[i], air[j], air[k]);
			}
		}
	}

	cout << maxn;
}