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

	string a, b;
	cin >> a >> b;

	int len = b.size();
	int result = 0;

	if (a == b) {
		result = 1;
	}

	for (int i = 0; i < len; i++) {
		if (b.back() == 'A') {
			b.pop_back();
		}
		else {
			b.pop_back();
			for (int j = 0; j < b.size()/2; j++) {
				swap(b[j], b[b.size() - j - 1]);
			}
		}
		if (a==b) {
			result =1;
		}
	}
	cout << result;
}