#include <iostream>
#include <deque>
#include <vector>

using namespace std;



void solve() {
	int n, m;
	cin >> n >> m;
	int* build = new int[n+1];
	int* count = new int[n + 1];
	fill_n(count, n + 1, 0);
	vector<int>* edge = new vector<int>[n+1];

	for (int i = 1; i <= n; i++) {
		cin >> build[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		count[b]++;
	}

	deque<int> building;

	int* dp = new int[n + 1];
	fill_n(dp, n + 1, 0);

	for (int i = 1; i <= n; i++) {
		if (count[i] == 0) {
			building.push_back(i);
			dp[i] = build[i];
		}
	}

	int now;

	


	while (!building.empty()) {
		now = building.front();
		building.pop_front();
		for (int i = 0; i < edge[now].size(); i++)
		{
			count[edge[now][i]]--;
			if (build[edge[now][i]] + dp[now] > dp[edge[now][i]]) {
				dp[edge[now][i]] = build[edge[now][i]] + dp[now];
			}
			if (count[edge[now][i]] == 0) {
				building.push_back(edge[now][i]);
			}
		}
	}

	int target;
	cin >> target;
	cout << dp[target] << "\n";

}





int main() {
	int cs;
	cin >> cs;
	for (int i = 0; i < cs; i++) {
		solve();
	}
}
