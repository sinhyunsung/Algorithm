#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long 

int n, m;
vector < pair<int, pair<int, int>>> edge;
int u[1001];

int find(int x) {
	if (u[x] != x) {
		u[x] = find(u[x]);

	}
	return u[x];
}



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	int a, b, c;

	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(edge.begin(), edge.end());

	for (int i = 1; i <= n; i++) {
		u[i] = i;
	}

	ll result = 0;

	for (int i = 0; i < m; i++) {

		if (find(edge[i].second.first) == find(edge[i].second.second)) {
			continue;
		}
		if (find(edge[i].second.first) > find(edge[i].second.second)) {
			u[find(edge[i].second.first)] = u[find(edge[i].second.second)];
		}
		else {
			u[find(edge[i].second.second)] = u[find(edge[i].second.first)];
		}
		result += edge[i].first;
	}
	cout << result;
}

