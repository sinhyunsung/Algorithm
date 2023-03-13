#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int n;
int m[49];
int visit[49] = { 0 };

void dfs(int now,int depth) {


	if (now == 6) {
		for (int i = 0; i < n; i++) {
			if (visit[i]) {
				cout << m[i]<<" ";
			}
		}
		cout << "\n";
		return;
	}
	if (depth == n) {
		return;
	}
	visit[depth] = true;
	dfs(now+1, depth+1);
	visit[depth] = false;
	dfs(now, depth+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}
		dfs(0,0);
		cin >> n;
		cout << "\n";
	}

}