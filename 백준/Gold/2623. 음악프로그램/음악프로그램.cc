#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;

vector<int> edge[1001];
int in_degree[1001] = { 0 };

vector<int> result;
deque<int> que;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m;

	int a, b,c;
	for (int i = 0; i < m; i++) {
		cin >> a;
		c = -1;
		for (int j = 0; j < a; j++) {
			cin >> b;
			if (c != -1) {
				edge[c].push_back(b);
				in_degree[b]++;
			}
			c = b;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!in_degree[i]) {
			que.push_back(i);
			result.push_back(i);
		}
	}

	while (!que.empty()) {
		a = que.front();
		que.pop_front();
		for (int i = 0; i < edge[a].size(); i++) {
			in_degree[edge[a][i]]--;
			if (!in_degree[edge[a][i]]) {
				que.push_back(edge[a][i]);
				result.push_back(edge[a][i]);
			}
		}
	}

	bool flag = false;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i]) {
			flag = true;
		}
	}

	if (flag) {
		cout << 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << result[i] << "\n";
		}
	}




}