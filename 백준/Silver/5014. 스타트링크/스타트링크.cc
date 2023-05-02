#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

#define ll long long

int F, S, G, U, D;
int dp[1000001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> F >> S >> G >> U >> D;
	deque<pair<int, int>> q;

	q.push_back({ S,0 });

	while (!q.empty()) {
		int now = q.front().first;
		int move = q.front().second;
		q.pop_front();

		if (now - D >= 1) {
			if (!dp[now - D]) {
				dp[now - D] = move + 1;
				q.push_back(make_pair(now - D, move + 1));
			}
		}
		if (now + U <= F) {
			if (!dp[now + U]) {
				dp[now + U] = move + 1;
				q.push_back(make_pair(now + U, move + 1));
			}
		}
	}

	if (dp[G]||G==S) {
		cout << dp[G];
	}
	else {
		cout << "use the stairs";
	}

	
}