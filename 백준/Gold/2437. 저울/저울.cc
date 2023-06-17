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
int v[1000];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v + n);

	int sum = 1;
	for (int i = 0; i < n; i++) {
		if (sum < v[i]) {
			break;
		}
		sum += v[i];
	}

	cout << sum;

}