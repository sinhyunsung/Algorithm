#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long

ll gcd(ll x, ll y) {
	while (y != 0) {
		x %= y;
		swap(x, y);
	}
	return x;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	ll b;
	
	cin >> n >> b;

	ll x, y;

	ll result = 0;
	ll acount = 0;
	

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		acount += x;
		result += y - b;
	}

	if (acount == 0) {
		cout << "EZPZ";
	}
	else {
		if (result%acount==0) {
			cout << result / acount;
		}
		else {
			ll gcd_n = gcd(result, acount);
			if (acount / gcd_n < 0) {
				result *= -1;
				acount *= -1;
			}
			cout << result / gcd_n << "/" << acount / gcd_n;
		}
	}
	


}