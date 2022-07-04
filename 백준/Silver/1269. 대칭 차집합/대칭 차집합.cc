#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

vector<int> map1[5001], map2[5001];

int hash_f(int k) {
	int prime = 65599;
	return ((prime << 5) + prime + k) % 5000;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		map1[hash_f(a[i])].push_back(a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		map2[hash_f(b[i])].push_back(b[i]);
	}

	int result = n+m;

	for (int i = 0; i < n; i++) {
		int idx = hash_f(a[i]);
		for (int j = 0; j < map2[idx].size(); j++) {
			if (map2[idx][j] == a[i]) { result--; break; }
		}
	}
	for (int i = 0; i < m; i++) {
		int idx = hash_f(b[i]);
		for (int j = 0; j < map1[idx].size(); j++) {
			if (map1[idx][j] == b[i]) { result--; break; }
		}
	}

	cout << result;
}