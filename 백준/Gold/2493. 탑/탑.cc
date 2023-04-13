#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
int v[500000];
int result[500000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	stack<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		cin >> v[i];	
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!q.empty() && q.top().first < v[i]) {
			result[q.top().second] = i+1;
			q.pop();
		}
		q.push(make_pair(v[i], i));
	}
	while (!q.empty()) {
		result[q.top().second] = 0;
		q.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}



}