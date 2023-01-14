#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> edge[101];
int score[101];
int n,range,edge_n;
int maxn = 0;

void dijkstra(int stt) {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, stt));
	int dist[101];
	fill_n(dist, 101, 100000);
	dist[stt] = 0;

	int now, now_dist;

	while (!q.empty()) {
		now_dist = -q.top().first;
		now = q.top().second;
		q.pop();

		if (now_dist > dist[now]) {
			continue;
		}

		for (int i = 0; i < edge[now].size(); i++) {
			if (dist[edge[now][i].first] > edge[now][i].second + now_dist) {
				dist[edge[now][i].first] = edge[now][i].second + now_dist;
				q.push(make_pair(-dist[edge[now][i].first], edge[now][i].first));
			}
		}

	}

	int sumn = 0;

	for (int i = 1; i <= n; i++) {
		if (dist[i] <= range) {
			sumn += score[i];
		}
	}
	if (maxn < sumn) {
		maxn = sumn;
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> range >> edge_n;

	for (int i = 1; i <= n; i++) {
		cin >> score[i];
	}
	int a, b, c;
	for (int i = 0; i < edge_n; i++) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	cout << maxn;
}