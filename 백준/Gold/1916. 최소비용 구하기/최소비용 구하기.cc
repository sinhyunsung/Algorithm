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

vector<pair<int, int>> edge[1001];
priority_queue<pair<int, int>> que;


void dijkstra(int start, int end) {
	int distance[1001];
	fill_n(distance, 1001, 100000000);
	que.push(make_pair(0, start));
	distance[start] = 0;

	while (!que.empty()) {
		int now_idx = que.top().second;
		int now_dist = -que.top().first;
		que.pop();

		if (now_dist > distance[now_idx]) {
			continue;
		}

		for (int i = 0; i < edge[now_idx].size(); i++) {
			int next_idx = edge[now_idx][i].first;
			int next_dist = edge[now_idx][i].second;

			if (distance[next_idx] > now_dist + next_dist) {
				distance[next_idx] = now_dist + next_dist;
				que.push(make_pair(-distance[next_idx], next_idx));
			}

		}

	}

	cout << distance[end];
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
	}


	cin >> n >> m;

	dijkstra(n, m);


}
