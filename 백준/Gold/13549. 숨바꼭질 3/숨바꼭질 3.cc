#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int n, k;

int dp[100001];
int visit[100001] = { 0 };



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	fill_n(dp, 100001, 100001);

	deque<pair<int, int>> q;

	q.push_back(make_pair(n, 0));
	while (!q.empty()) {
		
		int x = q.front().first;
		int t = q.front().second;
		q.pop_front();

		if (visit[x]) {
			continue;
		}

		dp[x] = t;
		visit[x] = 1;
		
		if (x * 2 < 100001 && !visit[x * 2]) {
			q.push_front(make_pair(2 * x, t));
		}
		if (x + 1 < 100001 && !visit[x + 1]) {
			q.push_back(make_pair(x + 1, t + 1));
		}
		if (x - 1 >= 0 && !visit[x - 1]) {
			q.push_back(make_pair(x - 1, t + 1));
		}
	}

	cout << dp[k];
}