#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

#define ll long long

using namespace std;

stack<pair<int,int>> dfs;

vector <pair<int, int>> tree[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	int max_idx = 1;
	int max_len = 0;

	int visit[10001] = {0};
	visit[1] = 1;

	dfs.push(make_pair(1, 0));
	while (!dfs.empty()) {
		int now_idx, now_len;
		now_idx = dfs.top().first;
		now_len = dfs.top().second;
		dfs.pop();
		if (now_len > max_len) {
			max_len = now_len;
			max_idx = now_idx;
		}
		visit[now_idx] = 1;
		for (int i = 0; i < tree[now_idx].size(); i++) {
			if (visit[tree[now_idx][i].first] == 0) {
				dfs.push(make_pair(tree[now_idx][i].first, tree[now_idx][i].second + now_len));
			}
		}
	}

	max_len = 0;

	fill_n(visit, 10001, 0);
	visit[max_idx] = 1;


	dfs.push(make_pair(max_idx, 0));
	while (!dfs.empty()) {
		int now_idx, now_len;
		now_idx = dfs.top().first;
		now_len = dfs.top().second;
		dfs.pop();
		if (now_len > max_len) {
			max_len = now_len;
			max_idx = now_idx;
		}
		visit[now_idx] = 1;
		for (int i = 0; i < tree[now_idx].size(); i++) {
			if (visit[tree[now_idx][i].first] == 0) {
				dfs.push(make_pair(tree[now_idx][i].first, tree[now_idx][i].second + now_len));
			}
		}
	}

	cout << max_len;

}
