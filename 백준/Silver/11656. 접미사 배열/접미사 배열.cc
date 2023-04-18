#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	string ss[1000];
	for (int i = 0; i < s.size(); i++) {
		ss[i] = s.substr(i, s.size() - i);
	}
	sort(ss, ss + s.size());

	for (int i = 0; i < s.size(); i++) {
		cout << ss[i] << "\n";
	}
}