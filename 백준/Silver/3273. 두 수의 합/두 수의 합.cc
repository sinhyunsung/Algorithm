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

int n;
int v[100000];
int x;

unordered_map<int, bool> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		a[v[i]] = true;
	}
	cin >> x;
	sort(v, v + n);
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (x - v[i] > 0 && x - v[i]!=v[i] && a[x - v[i]] == 1) {
			result++;
			a[v[i]] = 0;
		}
	}
	cout << result;

}