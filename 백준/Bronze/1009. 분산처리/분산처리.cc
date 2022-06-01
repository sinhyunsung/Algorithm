#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int n;
	cin >> n;

	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		int result = 1;
		while (b != 0) {
			if (b % 2 != 0)
			{
				result = (result * a) % 10;
				b -= 1;
			}
			a = (a * a) % 10;
			b /= 2;
		}
		if (result == 0) {
			cout << 10 << endl;
		}
		else {
			cout << result << endl;
		}
		}
}
