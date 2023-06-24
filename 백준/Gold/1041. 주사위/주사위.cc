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

ll n;
ll v[6];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];

	ll result = 0;

	ll plus = 0;
	plus += min(v[0], v[5]);
	plus += min({ v[1]+v[2],v[3]+v[4] ,v[3]+v[1],v[2] + v[4] });

	result += 4 * plus;


	plus = 10000000000000;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 6; j++) {
			if (i == 0 && j == 5) {
				continue;
			}
			if (i == 1 && j == 4) {
				continue;
			}
			if (i == 2 && j == 3) {
				continue;
			}
			plus = min(plus, v[i]+v[j]);
		}
	}
	result += 8 * (n - 2) * plus;
	result += 4  * plus;


	plus = min({ v[0],v[1],v[2],v[3],v[4],v[5] });
	result += 5 * (n - 2) * (n - 2) * plus;
	result += 4 * (n - 2) * plus;

	if (n == 1) {
		result=v[0]+v[1]+v[2]+v[3]+v[4]+v[5]- max({ v[0],v[1],v[2],v[3],v[4],v[5] });
	}
	cout << result;
}