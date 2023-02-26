#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	double x, y, d, t;
	double dist;
	cin >> x >> y >> d >> t;
	dist = sqrt(x *x + y *y);

	double ans = dist;

	double jump = int(dist /d);

	if (dist >= d) {
		ans = min(ans, jump * t + (dist - jump * d));
		ans = min(ans, (jump + 1) * t);
	}
	else {
		ans = min(ans, t+d-dist);
		ans = min(ans, 2 * t);
	}
	cout << fixed;
	cout.precision(10);
	cout << ans;


}