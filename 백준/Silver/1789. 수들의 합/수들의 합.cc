#include <iostream>
#include <stack>
using namespace std;

#define ll long long



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;

	ll result = 0;
	ll i = 1;
	while (result <= n) {
		result += i;
		i++;
	}
	if (n == 1) {
		cout << 1;
	}
	else {
		cout << i - 2;
	}
}