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

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> a;

	for (int i = 0; i <= n; i++) {
		a.push_back(i);
	}

	int result = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * i <= n; j++) {
			if (a[j * i]!=0) {
				a[j * i] = 0;
				result++;
				if (result == k) {
					cout << j * i;
					break;
				}
			}
		}
		if (result == k) {
			break;
		}
	}
	

}