#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct state {
	int right;
	int diagonal;
	int down;

	state() {
		right = 0;
		diagonal = 0;
		down = 0;
	}
};

int n;

vector<int>* a;
vector<state>* dp;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;

	a = new vector<int>[n];
	dp = new vector<state>[n];

	int dig;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dig;
			a[i].push_back(dig);
			state b;
			dp[i].push_back(b);
		}
	}

	dp[0][1].right = 1;

	priority_queue <pair<int,pair<int, int>>> q;

	q.push(make_pair(0,make_pair(0, 1)));

	int pri,nowy, nowx;

	while (!q.empty()) {
		nowy = q.top().second.first;
		nowx = q.top().second.second;
		pri = q.top().first;
		q.pop();

		if (a[nowy][nowx] != 2) {
			a[nowy][nowx]=2;
		}
		else {
			continue;
		}


		if ( a[nowy][nowx - 1] != 1) {
			dp[nowy][nowx].right += dp[nowy][nowx - 1].right;
			dp[nowy][nowx].right += dp[nowy][nowx - 1].diagonal;
		}

		if (nowy - 1 >= 0) {

			if (a[nowy - 1][nowx] != 1) {
				dp[nowy][nowx].down += dp[nowy - 1][nowx].down;
				dp[nowy][nowx].down += dp[nowy - 1][nowx].diagonal;
			}

			if (a[nowy - 1][nowx] != 1 && a[nowy][nowx - 1] != 1 && a[nowy-1][nowx - 1] != 1) {
				dp[nowy][nowx].diagonal += dp[nowy - 1][nowx - 1].down;
				dp[nowy][nowx].diagonal += dp[nowy - 1][nowx - 1].right;
				dp[nowy][nowx].diagonal += dp[nowy - 1][nowx - 1].diagonal;
			}
		}


		if (nowx + 1 < n && a[nowy][nowx + 1] != 1 ) {
				q.push(make_pair(pri-1,make_pair(nowy, nowx + 1)));
;		}
		if (nowy + 1 < n && a[nowy+1][nowx] != 1 ) {
				q.push(make_pair(pri - 1, make_pair(nowy + 1, nowx)));
		}
		if (nowx + 1 < n && nowy + 1 < n && a[nowy + 1][nowx+1] != 1 && a[nowy + 1][nowx] != 1 && a[nowy][nowx + 1] != 1) {
				q.push(make_pair(pri - 2, make_pair(nowy + 1, nowx + 1)));
		}
	}

	cout << dp[n - 1][n - 1].diagonal + dp[n - 1][n - 1].down + dp[n - 1][n - 1].right;

}