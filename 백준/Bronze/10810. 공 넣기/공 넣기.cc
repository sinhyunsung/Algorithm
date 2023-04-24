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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	int v[100] = { 0 };
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		for (int j = a - 1; j < b; j++) {
			v[j] = c;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	
}