#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

#define ll long long

void solve(int x,int y) {
	int m[50][50] = { 0 };
	bool visit[50][50] = { 0 };
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> m[i][j];
		}
	}

	deque<pair<int, int>> q;

	int result = 0;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (!visit[i][j]&&m[i][j]) {
				result++;
				q.push_back(make_pair(i, j));
				visit[i][j] = true;
				while (!q.empty()) {
					int ny = q.front().first;
					int nx = q.front().second;
					q.pop_front();

					for (int dy = ny - 1; dy <= ny + 1; dy++) {
						for (int dx = nx - 1; dx <= nx + 1; dx++) {
							if (dx < 0 || dy < 0 || dx >= x || dy >= y) {
								continue;
							}
							if (dx == nx && dy == ny) {
								continue;
							}
							if (m[dy][dx]&&!visit[dy][dx]) {
								visit[dy][dx] = true;
								q.push_back(make_pair(dy, dx));
							}
						}
					}
				}
			}
		}
	}
	cout << result << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		solve(a, b);
		cin >> a >> b;
	}

}