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

int m[300][300];
int l, px, py, ex, ey;

struct node {
	int y;
	int x;
	int depth;
	node(int X, int Y, int Depth) : x(X), y(Y), depth(Depth) {}
};

void solve() {
	cin >> l >> px >> py >> ex >> ey;	
	fill_n(&m[0][0], 90000, -1);

	deque<node> q;

	node first(px,py,0);

	q.push_back(first);

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int depth = q.front().depth;
		q.pop_front();

		if (x < 0 || y < 0 || x >= l || y >= l) {
			continue;
		}
		if (m[y][x] != -1) {
			continue;
		}
		m[y][x] = depth;

		q.push_back(node(x+2,y+1,depth+1));
		q.push_back(node(x + 2, y - 1, depth + 1));
		q.push_back(node(x - 2, y + 1, depth + 1));
		q.push_back(node(x - 2, y - 1, depth + 1));
		q.push_back(node(x + 1, y + 2, depth + 1));
		q.push_back(node(x - 1, y + 2, depth + 1));
		q.push_back(node(x + 1, y - 2, depth + 1));
		q.push_back(node(x - 1, y - 2, depth + 1));
	}

	cout << m[ey][ex] << "\n";
	
	
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
