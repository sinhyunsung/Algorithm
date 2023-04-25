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
	
	string s;
	cin >> s;

	int o = 0, z = 0;
	
	int idx = 0;
	while (idx < s.size()) {
		char target;
		target = s[idx];
		target == '1' ? o++ : z++;
		idx++;
		while (idx < s.size() && s[idx] == target) {
			idx++;
		}
	}
	cout << min(o, z);
	
}