#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;


ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	double result = 0;
	
	int n;
	cin >> n;
	
	ll** dot;
	dot = new ll*[n];
	for (int i = 0; i < n; i++) {
		dot[i] = new ll[2];
		cin >> dot[i][0] >> dot[i][1];
	}

	for (int i = 2; i < n; i++) {
		result += ccw(dot[0][0], dot[0][1], dot[i - 1][0], dot[i - 1][1], dot[i][0], dot[i][1]);
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(result / 2.0);
	
}