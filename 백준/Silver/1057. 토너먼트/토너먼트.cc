#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;
	
	if (a > b)swap(a, b);

	int result = 1;
	while (1) {
		if (a % 2 == 1 && b - a == 1) {
			break;
		}
		result++;
		if (a % 2 == 1)a++;
		if (b % 2 == 1)b++;

		a /= 2;
		b /= 2;
	}
	
	cout << result;
}