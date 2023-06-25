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

int n;
deque<pair<int, int>> q;
int day[10001];


int find(int x) {
	if (day[x] == x) {
		return x;
	}
	day[x] = find(day[x]);
	return day[x];
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		q.push_back(make_pair(a, b));
	}

	for (int i = 0; i < 10001; i++) {
		day[i] = i;
	}

	sort(q.begin(), q.end(),cmp);

	int p, d;
	int result = 0;

	while (!q.empty()) {
		p = q.front().first;
		d = q.front().second;
		q.pop_front();
		int f = find(d);
		if (f != 0) {
			day[f] = f - 1;
			result += p;
		}
	}
	cout << result;

}