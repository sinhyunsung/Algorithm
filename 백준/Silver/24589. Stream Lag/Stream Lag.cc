#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.second)return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int a, b;
	int time = 1;
	int result = 0;
	cin >> n;
	
	vector<pair<int, int>> l;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		l.push_back(make_pair(a, b));
	}

	sort(l.begin(), l.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (time < l[i].first) {
			result += l[i].first - time;
			time = l[i].first + 1;
		}
		else {
			time++;
		}
	}


	cout << result;
}