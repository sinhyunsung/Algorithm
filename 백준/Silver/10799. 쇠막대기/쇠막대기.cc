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

	string s;
	cin >> s;
	int open = 0, result = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			open++;
		}
		else {
				open--;
				if (s[i - 1] == '(') {
					result += open;
				}
				else {
					result++;
				}
		}
	}
	cout << result;
}