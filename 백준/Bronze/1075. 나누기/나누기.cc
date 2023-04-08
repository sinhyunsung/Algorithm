#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int mod = n % k;
	int nk = n % 100;
	int result;
	if (nk >= mod) {
		 result= (nk - mod)%k;
	}
	else {
		result = nk + (k - mod);
	}
	if (result < 10) {
		cout << 0 << result;
	}
	else {
		cout << result;
	}
}