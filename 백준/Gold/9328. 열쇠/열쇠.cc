#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

void solve() {
	int n, m;
	cin >> n >> m;

	string key;

	string* l = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	cin >> key;
	if (key == "0") {
		key = "";
	}

	int result = 0;

	deque<pair<int, int>> now;
	deque<pair<int, int>> alpha;


	for (int i = 0; i < m; i++) {
		if (l[0][i] == '.') {
			now.push_back(make_pair(0, i));
		}
		if (l[n - 1][i] == '.') {
			now.push_back(make_pair(n - 1, i));
		}
		if (l[0][i] == '$') {
			l[0][i] = '.';
			result++;
			now.push_back(make_pair(0, i));
		}
		if (l[n - 1][i] == '$') {
			l[n-1][i] = '.';
			result++;
			now.push_back(make_pair(n - 1, i));
		}
		if (l[0][i] >= 'A' && l[0][i] <= 'Z') {
			alpha.push_back(make_pair(0, i));
		}
		if (l[n - 1][i] >= 'A' && l[n - 1][i] <= 'Z') {
			alpha.push_back(make_pair(n - 1, i));
		}

		if (l[0][i] >= 'a' && l[0][i] <= 'z') {
			key.push_back(l[0][i]);
			now.push_back(make_pair(0, i));
		}
		if (l[n - 1][i] >= 'a' && l[n - 1][i] <= 'z') {
			key.push_back(l[n-1][i]);
			now.push_back(make_pair(n - 1, i));
		}
	}
	for (int i = 1; i < n - 1; i++) {
		if (l[i][0] == '.') {
			now.push_back(make_pair(i, 0));
		}
		if (l[i][m - 1] == '.') {
			now.push_back(make_pair(i, m - 1));
		}
		if (l[i][0] == '$') {
			l[i][0] = '.';
			result++;
			now.push_back(make_pair(i, 0));
		}
		if (l[i][m - 1] == '$') {
			l[i][m-1] = '.';
			result++;
			now.push_back(make_pair(i, m - 1));
		}


		if (l[i][0] >= 'A' && l[i][0] <= 'Z') {
			alpha.push_back(make_pair(i, 0));
		}
		if (l[i][m - 1] >= 'A' && l[i][m - 1] <= 'Z') {
			alpha.push_back(make_pair(i, m-1));
		}
		if (l[i][0] >= 'a' && l[i][0] <= 'z') {
			key.push_back(l[i][0]);
			now.push_back(make_pair(i, 0));
		}
		if (l[i][m - 1] >= 'a' && l[i][m - 1] <= 'z') {
			key.push_back(l[i][m-1]);
			now.push_back(make_pair(i, m - 1));
		}
	}

	int y, x;

	int dx[4] = {0, 0, 1, -1};
	int dy[4] = { 1, -1, 0, -0 };

	now.push_front({ -1,-1 });
	while (!now.empty()) {
		if (now.front().second == -1) {
			now.pop_front();
		}
		
		while (!now.empty()) {
			int y = now.front().first;
			int x = now.front().second;
			now.pop_front();
			l[y][x] = '*';

			for (int i = 0; i < 4; i++) {
				int cx = dx[i] + x;
				int cy = dy[i] + y;
				if (cx >= 0 && cx < m && cy >= 0 && cy < n) {
					if (l[cy][cx] == '.') {
						now.push_back(make_pair(cy, cx));
					}
					if (l[cy][cx] == '$') {
						result++;
						l[cy][cx] = '.';
						now.push_back(make_pair(cy, cx));
					}
					if (l[cy][cx] >= 'A' && l[cy][cx] <= 'Z') {
						alpha.push_back(make_pair(cy, cx));
					}
					if (l[cy][cx] >= 'a' && l[cy][cx] <= 'z') {
						key.push_back(l[cy][cx]);
						l[cy][cx] = '.';
						now.push_back(make_pair(cy, cx));
					}

				}
			}

		}
		
		for (int a = 0; a < alpha.size(); a++) {
			int y = alpha[a].first;
			int x = alpha[a].second;
			
			if (key.find(l[y][x] + 32)!=string::npos) {
				l[y][x] = '.';
				now.push_back(make_pair(y, x));
			}
		}


	}

	cout << result << "\n";



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int cs;

	cin >> cs;

	while (cs--) {
		solve();
	}

	
}