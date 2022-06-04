#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long int

bool a[1000001];

int main() {
	ll min, max;
	cin >> min >> max;
	
	ll n = max - min +1;

	fill_n(a, 1000001, true);

	ll idx;

	for (ll i = 2; i*i <= max; i++) {
		if (min % (i * i) == 0) {
			idx = 0;
		}
		else {
			idx = (i * i) - min % (i * i);
		}
		if (idx <= n) {

			for (ll j = idx; j+min <= max; j += i * i) {
				a[j] = false;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (a[i]) {
			result++;
		}
	}
	cout << result;
}