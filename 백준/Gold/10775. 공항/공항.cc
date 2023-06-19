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

int n, k;
int v[100001];

int search(int x) {
	if (v[x] == x) {
		return v[x];
	}
	v[x] = search(v[x]);
	return v[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		v[i] = i;
			
	}
	int airplain;
	int result = 0;
	bool flag = true;
	for (int i = 0; i < k; i++) {
		cin >> airplain;
		if (flag) {
			int target = search(airplain);
			if (target != 0) {
				result++;
				v[target] = target-1;
			}
			else {
				flag = false;
			}
		}
	}
	cout << result;
	



}