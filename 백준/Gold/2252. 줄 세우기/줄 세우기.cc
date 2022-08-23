#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> edge[32001];
int edge_count[32001] = { 0 };

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge_count[b] ++;
	}

	deque<int> topological;

	for (int i = 1; i <= n; i++) {
		if (edge_count[i] == 0) {
			topological.push_back(i);
		}
	}

	while (!topological.empty()) {
		a = topological.front();
		topological.pop_front();

		cout << a << " ";
		for (int i = 0; i < edge[a].size(); i++) {
			edge_count[edge[a][i]]--;
			if (edge_count[edge[a][i]] == 0) {
				topological.push_back(edge[a][i]);
			}
		}
	}

}