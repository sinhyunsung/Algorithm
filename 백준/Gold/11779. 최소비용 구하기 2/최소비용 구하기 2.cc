#include <iostream>
#include <vector>
#include <queue>
#define ll long long int 

using namespace std;


vector<pair<ll, ll>> edge[1001];
ll n, m;
ll a, b, c;
ll s, e;

void dijkstra() {
	priority_queue<pair<ll, ll>> q;
	q.push(make_pair(0, s));
	ll dist[1001];
	vector<ll> route[1001];
	fill_n(dist, 1001, 117440512);
	route[s].push_back(s);
	ll now, now_d;
	while (!q.empty()) {
		now_d = -q.top().first;
		now = q.top().second;
		q.pop();
		if (now_d > dist[now]) {
			continue;
		}
		for (int i = 0; i < edge[now].size(); i++) {
			if (edge[now][i].second + now_d < dist[edge[now][i].first]) {
				dist[edge[now][i].first] = edge[now][i].second + now_d;
				q.push(make_pair(-dist[edge[now][i].first], edge[now][i].first));
				if (!route[edge[now][i].first].empty()) {
					route[edge[now][i].first].clear();
				}

				route[edge[now][i].first] = route[now];

				route[edge[now][i].first].push_back(edge[now][i].first);
			}
		}

	}

	cout << dist[e] % 117440512 << "\n" << route[e].size() << "\n";
	for (int i = 0; i < route[e].size(); i++) {
		cout << route[e][i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge[a].push_back(make_pair(b, c));
	}

	cin >> s >> e;

	dijkstra();



}