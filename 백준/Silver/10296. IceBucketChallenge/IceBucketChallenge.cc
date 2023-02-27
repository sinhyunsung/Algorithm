#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

#define ll long long

void solve() {
	int a, b;
	cin >> a >> b;
	
	int result = 0;
	int now = 1;
	int val = 0;
	while (now * 100+val < a) {
		result++;
		val += 10;
		now = now - 1 + b;
	}
	cout << result << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cs;
	cin >> cs;
	while (cs--) {
		solve();
	}


}