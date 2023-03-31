#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int n,l,r;
int m[50][50];
int result = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool move() {
	bool move_flag = false;

	bool visit[50][50] = { 0 };
	deque<pair<int, int>> q;
	deque<pair<int, int>> q2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				int area_n = 0;
				int area_human = 0;
				q.push_back(make_pair(i, j));
				while (!q.empty()) {
					int nowx = q.front().second;
					int nowy = q.front().first;
					q.pop_front();
					for (int a = 0; a < 4; a++) {
						int ddx = dx[a] + nowx;
						int ddy = dy[a] + nowy;
						if (ddx >= 0 && ddy >= 0 && ddx < n && ddy < n && !visit[ddy][ddx]) {
							int human_diff = abs(m[nowy][nowx] - m[ddy][ddx]);
							if (human_diff <= r && human_diff >= l) {
								move_flag = true;
								visit[ddy][ddx] = true;
								area_n++;
								area_human += m[ddy][ddx];

								q.push_back(make_pair(ddy, ddx));
								q2.push_back(make_pair(ddy, ddx));
							}
						}
					}
				}


				while (!q2.empty()) {
					int move_human = area_human / area_n;
					int nowx = q2.front().second;
					int nowy = q2.front().first;
					q2.pop_front();
					m[nowy][nowx] = move_human;
				}
			}
		}
	}

	if (move_flag) {
		result++;
	}
	return move_flag;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	while (move());
	cout << result;
}