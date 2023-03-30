#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;

	sort(s.begin(), s.end(),cmp);

	if (s[s.size() - 1] == '0') {
		int sumv = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			sumv += s[i] - '0';
		}
		if (sumv % 3 == 0) {
			cout << s;
		}
		else {
			cout << -1;
		}
	}
	else {
		cout << -1;
	}

}