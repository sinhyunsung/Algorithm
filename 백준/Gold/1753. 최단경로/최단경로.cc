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

vector<pair<int, int>> edge[20001];
priority_queue<pair<int, int>> que;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int V, E, target_node;
	cin >> V >> E >> target_node;
	
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair( b,c ));
	}
	int distance[20001];

	for (int i = 1; i <= V; i++)
		distance[i] = 100000000;

	distance[target_node] = 0;
	que.push({ 0,target_node });

	while (!que.empty()) {
		int idx = que.top().second;
		int idx_distance = -que.top().first;
		que.pop();

		if (idx_distance > distance[idx]) {
			continue;
		}

		for (int i = 0; i < edge[idx].size(); i++) {
			int next_idx = edge[idx][i].first;
			int next_distance = edge[idx][i].second;

			if (idx_distance + next_distance < distance[next_idx]) {
				distance[next_idx] = idx_distance + next_distance;
				que.push(make_pair(-distance[next_idx],next_idx));
			}

		}

	}

	for (int i = 1; i <= V; i++) {
		if (distance[i] == 100000000) {
			cout << "INF\n";
		}
		else
		{
			cout << distance[i] << "\n";
		}
	}

}
