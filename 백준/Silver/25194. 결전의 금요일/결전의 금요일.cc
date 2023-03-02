#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int seven[7] = { 0 };
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		seven[a % 7] += 1;
	}
	bool check[6001] = { 0 };
	check[0] = true;
	int max = 0;
	int temp=0;
	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < seven[i]; j++) {
			for (int k = 0; k <= max; k++) {
				if (check[k]) {
					check[k + i] = true;
					temp = k + i;
				}
			}
			max = temp;
		}
	}
	bool psb = false;
	for (int i = 0; i < 6001; i++) {
		if (check[i] && i % 7 - 4 == 0) {
			psb = true;
		}
	}

	if (psb) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}