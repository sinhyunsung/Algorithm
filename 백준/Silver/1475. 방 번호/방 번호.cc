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
	
	int num[10] = { 0 };

	int n;
	cin >> n;

	while (n != 0) {
		num[n % 10]++;
		n /= 10;
	}

	int maxn = 0;
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			continue;
		}
		maxn = max(maxn, num[i]);
	}

	cout << max(maxn,(num[6]+num[9])/2+ (num[6] + num[9]) % 2);
}