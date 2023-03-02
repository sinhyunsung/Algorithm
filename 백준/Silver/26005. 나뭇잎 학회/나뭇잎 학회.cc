#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << n * n / 2;
	}
	else if (n == 1) {
		cout << 0;
	}
	else {
		cout << n * n / 2 + 1;
	}
}