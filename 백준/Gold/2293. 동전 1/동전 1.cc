#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	cin >> n >> k;

	int coin[100];
	int value[10001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	value[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			value[j] += value[j - coin[i]];
		}
	}
	cout << value[k];


}