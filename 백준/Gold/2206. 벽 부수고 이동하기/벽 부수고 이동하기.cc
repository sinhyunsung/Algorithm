#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

#define ll long long int

using namespace std;

struct state {
	int x;
	int y;
	int len;
	bool bore;
	state(int X, int Y,int Len, bool Bore) :x(X), y(Y),len(Len), bore(Bore) {}
};

deque <state> bfs;

int main() {
	int n, m;
	cin >> n >> m;

	string* road = new string[n];

	int** visit = new int* [n];
	int** visit2 = new int* [n];

	for (int i = 0; i < n; i++) {
		cin >> road[i];
		visit[i] = new int[m];
		fill_n(visit[i], m, 0);
		visit2[i] = new int[m];
		fill_n(visit2[i], m, 0);
	}
	


	bfs.push_back(state(0, 0,1, 0));
	visit[0][0] = 1;
	visit2[0][0] = 1;

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = {1, -1, 0, 0};

	int result = -1;


	while (!bfs.empty()) {
		state now_stat = bfs.front();
		bfs.pop_front();
		if (now_stat.x == m - 1 && now_stat.y == n - 1) {
			result = now_stat.len;
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int d_x = dx[i] + now_stat.x;
			int d_y = dy[i] + now_stat.y;
			if (d_x >= 0 && d_x < m && d_y >= 0 && d_y < n) {
				if ((now_stat.bore==0 && visit[d_y][d_x] == 0) || (now_stat.bore == 1 && visit2[d_y][d_x] == 0)) {
					if (road[d_y][d_x] == '0') {
						bfs.push_back(state(d_x, d_y, now_stat.len + 1, now_stat.bore));
						if (now_stat.bore == 0) {
							visit[d_y][d_x] = 1;
						}
						else {
							visit2[d_y][d_x] = 1;
						}
					}
					else if (now_stat.bore == 0) {
						bfs.push_back(state(d_x, d_y, now_stat.len + 1, 1));
						if (now_stat.bore == 0) {
							visit[d_y][d_x] = 1;
						}
						else {
							visit2[d_y][d_x] = 1;
						}
					}
				}

			}
		}

	}

	cout << result;


}