#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	ll m[100000];

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}

	sort(m, m + n);

	ll result = 0;

	for (int i = 0; i < n; i++) {
		result = max(result, m[i] * (n - i));
	}
	cout << result;

}