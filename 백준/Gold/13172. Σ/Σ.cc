#include <iostream>


using namespace std;

#define ll long long int

ll mod = 1000000007;

ll gcd(ll a, ll b) {
	ll temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

ll multi(ll a, ll b) {
	ll result = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			result *= a;
			result %= mod;
			b -= 1;
		}
		a *= a;
		a %= mod;
		b /= 2;
	}
	return result;
}

int main() {
	int cs;
	ll n, m;
	cin >> cs;

	ll result = 0;

	for (int i = 0; i < cs; i++) {
		cin >> n >> m;
		result += m * multi(n, mod - 2) % mod;
		result %= mod;
	}
	cout << result;
}