#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>

using namespace std;

int n, m;
int p[100][100];

vector<pair<int, int>> edge[100100];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dist[100100];



void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0,0 });

	while (!q.empty()) {
		int now = q.top().second;
		int now_dist = -q.top().first;
		q.pop();
		if (now_dist > dist[now]) {
			continue;
		}
		for (int i = 0; i < edge[now].size(); i++) {
			if (dist[edge[now][i].first] > now_dist + edge[now][i].second) {
				dist[edge[now][i].first] = now_dist + edge[now][i].second;
				q.push(make_pair(-dist[edge[now][i].first], edge[now][i].first));
			}
		}
	}

	if (n == 1 && m == 1) {
		cout << 0;
	}
	else {
		cout << dist[(n - 1) * 1000 + m - 1];
	}
	}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = 0; j < m; j++) {
			p[i][j] = temp[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ddx = dx[k] + j;
				int ddy = dy[k] + i;
				if (ddx >= 0 && ddy >= 0 && ddx < m && ddy < n) {
					edge[i * 1000 + j].push_back(make_pair(ddy*1000+ddx,p[ddy][ddx]));
				}
			}
		}
	}

	fill_n(dist, 100100, 100000);
	
	dijkstra();

}