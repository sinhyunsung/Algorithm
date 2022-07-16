#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>

#define ll long long

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	ll result = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			result = (result * a) % c;
			b -= 1;
		}
		a = ((a % c) * (a % c)) % c;
		b /= 2;
	}
	cout << result%c;
}
