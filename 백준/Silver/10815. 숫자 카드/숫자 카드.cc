#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m,k;
	
	int map[20000001] = { 0 };

	cin >> n;

	int idx;

	for (int i = 0; i < n; i++) {
		cin >> k;
		map[k + 10000000] = 1;
	}
	
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> k;
		cout << map[k + 10000000]<<" ";
	}


}