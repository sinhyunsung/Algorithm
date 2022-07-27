#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[32001];
int in_degree[32001];


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
		in_degree[b] ++;
	}

	priority_queue<int> c;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0) {
			c.push(-i);
		}
	}

	int idx;

	while (!c.empty()) {
		idx = -c.top();
		cout << idx << " ";
		c.pop();
		for (int i = 0; i < edge[idx].size(); i++) {
			in_degree[edge[idx][i]]--;
			if (in_degree[edge[idx][i]] == 0) {
				c.push(-edge[idx][i]);
			}
		}
	}


}
