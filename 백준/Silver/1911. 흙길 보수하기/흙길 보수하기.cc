#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, l;
	cin >> n >> l;
	vector<pair<int, int>> q;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		q.push_back(make_pair(a, b));
	}

	sort(q.begin(), q.end());


	int now = -1;
	int result = 0;
	for (int i = 0; i < n; i++) {
		a = q[i].first;
		b = q[i].second;
		if (now > a) {
			a = now;
		}
		if (a >= b) {
			continue;
		}
		result += (b - a) / l;
		if ((b - a) % l > 0) {
			result++;
			now = b + l - ((b - a) % l);
		}
		else {
			now = b;
		}
	}
	cout << result;
}