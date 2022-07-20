#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int max_d;
priority_queue<pair<int, pair<int, int>>> q;
int* conn;

int find(int x) {
	if (conn[x] == x) {
		return x;
	}
	conn[x] = find(conn[x]);
	return conn[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		q.push(make_pair(-c, make_pair(a, b)));
	}

	conn = new int[n+1];
	for (int i = 0; i < n + 1; i++) {
		conn[i] = i;
	}

	int result=0;

	while (!q.empty()) {
		c = -q.top().first;
		a = q.top().second.first;
		b = q.top().second.second;

		q.pop();

		a = find(a);
		b = find(b);
		if (a == b) {
			continue;
		}
		if (a < b) {
			conn[b] = a;
		}
		else {
			conn[a] = b;
		}
		result += c;
		max_d = c;
	}

	cout << result - max_d;



}
