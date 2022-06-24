#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>

#define ll long long

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<pair<int, int>> v[100001];
	int v2[100001] = { 0 };
	
	int a,d, d2;

	for (int i = 0; i < n; i++) {
		cin >> a >> d;
		while (d != -1) {
			cin >> d2;
			v[a].push_back({d, d2});
			cin >> d;
		}
	}

	deque<pair<int, int>> dfs;

	dfs.push_back({ 1,0 });

	int idx, len;

	len = 0;
	idx = 1;
	v2[idx] = 1;

	while (!dfs.empty())
	{
		int nowidx= dfs.back().first;

		if (dfs.back().second > len) {
			idx = dfs.back().first;
			len = dfs.back().second;
		}

		int nowlen = dfs.back().second;
		dfs.pop_back();

		for (auto var : v[nowidx])
		{
			if (v2[var.first] == 0)
			{
				dfs.push_back({ var.first,var.second + nowlen });
				v2[var.first] = 1;
			}
		}

	}

	len = 0;
	fill(v2, v2 + 100001, 0);
	v2[idx] = 1;

	dfs.push_back({ idx,0 });

	while (!dfs.empty())
	{
		int nowidx = dfs.back().first;

		if (dfs.back().second > len) {
			idx = dfs.back().first;
			len = dfs.back().second;
		}

		int nowlen = dfs.back().second;
		dfs.pop_back();

		for (auto var : v[nowidx])
		{
			if (v2[var.first] == 0)
			{
				dfs.push_back({ var.first,var.second + nowlen });
				v2[var.first] = 1;
			}
		}

	}


	cout << len ;

}
