#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int n, k;
char m[15];

bool visit[15] = { 0 };

void dfs(int now,int depth) {
	if (depth > n) {
		return;
	}
	if (depth == n) {
		string s = "";
		int gather = 0;
		int consonant = 0;
		for (int i = 0; i < k; i++) {
			if (visit[i]) {
				s += m[i];
				if (m[i] == 'a' || m[i] == 'i' || m[i] == 'e' || m[i] == 'o' || m[i] == 'u') {
					gather ++;
				}
				else {
					consonant++;
				}
			}
		}
		if (gather>=1 && consonant>=2) {
			cout << s << "\n";
		}
		return;
	}


	if (now >= k) {
		return;
	}


	visit[now] = true;
	dfs(now + 1, depth + 1);
	visit[now] = false;
	dfs(now + 1, depth);
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> m[i];
	}
	sort(m, m + k);

	dfs(0, 0);
}