#include <iostream>
#include <deque>
using namespace std;

#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;
	deque<pair<ll, ll>> q;
	q.push_back(make_pair(n, 1));

	bool visit[100000002] = { false };

	ll now,time;
	bool flag = true;
	while (!q.empty()) {
		now = q.front().first;
		time = q.front().second;
		if (now < 100000001)
		{
			visit[now] = true;
		}
		q.pop_front();
		if (now == m) {
			cout << time;
			flag = false;
		}
		else if (now < m) {
			if (now*2>100000000 || !visit[now * 2]) {
				q.push_back(make_pair(now * 2, time + 1));
			}
			if (now * 10 + 1 > 100000000 || !visit[now * 10+1]) {
				q.push_back(make_pair(now * 10 + 1, time + 1));
			}
		}

	}

	if (flag) {
		cout << -1;
	}

}