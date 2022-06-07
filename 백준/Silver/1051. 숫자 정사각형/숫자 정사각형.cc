#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int n, m;
	cin >> n >> m;

	string* l = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	int k = min(n, m)-1;
	int flag = false;
	int result = 1;
	for (int add = k; add >= 0; add--) {
		for (int y = 0; y < n - add; y++) {
			for (int x = 0; x < m - add; x++) {
				if (l[y][x] == l[y + add][x]) {
					if (l[y][x] == l[y + add][x+add]) {
						if (l[y][x] == l[y][x+add]) {
							result= (add + 1) * (add + 1);
							flag = true;
							break;
						}
					}
				}
			}
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	cout << result;
}