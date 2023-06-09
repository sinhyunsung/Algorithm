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

int n;

int minn, maxn;
int result = 2000000001;
int v[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v +n);
	
	int left = 0, right = n - 1;
	while (left < right) {
		if (abs(v[left] + v[right])<result) {
			result = abs(v[left] + v[right]);
			minn = v[left];
			maxn = v[right];
		}
		if (v[left] + v[right] < 0) {
			left++;
		}
		else {
			right--;
		}

	}
	cout << minn << " " << maxn;
}