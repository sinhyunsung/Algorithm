#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

vector<int> human[101];

int n;
int a, b;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	int m;
	cin >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		human[x].push_back(y);
		human[y].push_back(x);
	}

	bool visit[101] = { 0 };

	deque<pair<int, int>> q;

	q.push_back({ a, 0 });
	visit[a] = 1;
	while (!q.empty()) {
		int now = q.front().first;
		int now_score= q.front().second;
		q.pop_front();
		if (now == b) {
			cout << now_score;
			return 0;
		}

		for (int i = 0; i < human[now].size(); i++) {
			if (!visit[human[now][i]]) {
				visit[human[now][i]] = 1;
				q.push_back({ human[now][i],now_score + 1 });
			}
		}
	}

	cout << -1;
}