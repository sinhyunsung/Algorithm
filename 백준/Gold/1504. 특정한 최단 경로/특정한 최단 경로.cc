#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

int len[801][801];
vector<pair<int, int>> road[801];
priority_queue<pair<int, int>> que;

void dijkstra(int target) {
	fill_n(len[target], 801, 100000000);
	que.push({ target,0 });
	int idx = target;
	len[target][idx] = 0;
	int visit[801] = { 0 };
	visit[idx] = 1;
	int nowlen = 0;
	while (!que.empty()) {
		idx = que.top().first;
		nowlen= -que.top().second;
		que.pop();
		for (int i = 0; i < road[idx].size(); i++) {
			int next_idx = road[idx][i].first;
			int next_len = road[idx][i].second;
			if (nowlen + next_len < len[target][next_idx]) {
				que.push({ next_idx,-(nowlen + next_len) });
				len[target][next_idx] = nowlen + next_len;
				visit[next_idx] = 1;
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, E;
	cin >> N >> E;

	int a, b, c;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		road[a].push_back({ b, c });
		road[b].push_back({ a, c });
	}

	int target1, target2;
	cin >> target1 >> target2;

	dijkstra(target1);

	dijkstra(target2);

	dijkstra(N);


	int min = 100000000;

	if (len[target1][1] + len[target2][target1] + len[target2][N] < len[target2][1] + len[target1][target2] + len[target1][N])
	{
		min= len[target1][1] + len[target2][target1] + len[target2][N];
	}
	else {
		min= len[target2][1] + len[target1][target2] + len[target1][N];
	}

	if (min > 99999999) {
		cout << -1;
	}
	else {
		cout << min;
	}


	


}
