#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int n,k;
int result = 0;
int s[20];
void dfs(int now, int depth) {
	if (depth == n) {
		if (k == now) {
			result++;
		}
		return;
	}
	dfs(now, depth+1);
	dfs(now+s[depth], depth+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n>>k;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	dfs(0,0);
	if (k == 0) {
		result--;
	}
	cout << result;
}