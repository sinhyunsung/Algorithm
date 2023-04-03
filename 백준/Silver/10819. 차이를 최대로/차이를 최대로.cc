#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

int n;
int m[8];
bool visit[8] = { 0 };
vector<int> q;


int result = 0;

void dfs(int depth) {
	if (depth == n) {
		int score = 0;
		for (int i = 0; i < n-1; i++) {
			score += abs(q[i] - q[i + 1]);
		}
		result = max(result, score);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			q.push_back(m[i]);
			dfs(depth+1);
			visit[i] = false;
			q.pop_back();
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	dfs(0);
	cout << result;


}