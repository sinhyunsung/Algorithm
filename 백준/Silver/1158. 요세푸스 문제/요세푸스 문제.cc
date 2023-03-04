#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

#define ll long long



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,k;
	cin >> n>>k;

	deque<int> q;

	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}

	cout << "<";

	int now = 1;
	while (!q.empty()) {
		if (now == k) {
			cout << q.front();
			q.pop_front();
			now = 0;
			if (!q.empty()) {
				cout << ", ";
			}
		}
		else {
			q.push_back(q.front());
			q.pop_front();
		}
		now++;
	}
	cout << ">";

}