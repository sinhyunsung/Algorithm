#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long 



int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;

	int d, e, f;
	d = 1; e = 1; f = 1;
	int result = 1;
	while (!(a == d && b == e && c == f)) {
		result++;
		d++; e++; f++;
		if (d == 16) {
			d = 1;
		}if (e == 29) {
			e = 1;
		}if (f == 20) {
			f = 1;
		}
	}
	cout << result;
}

