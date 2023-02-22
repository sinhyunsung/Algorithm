#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

#define ll long long

void solve() {
	int n;
	cin >> n;
	ll* num = new ll[n];
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	priority_queue<ll> q;


	for (int i = 0; i < n; i++) {
		q.push(-num[i]);
	}

	ll a, b;
	ll result = 0;
	while (q.size() != 1) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		result += a + b;
		q.push(a + b);
	}
	cout << -result << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cs;
	cin >> cs;
	while (cs--) {
		solve();
	}

}