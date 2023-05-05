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

stack<char> st;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	getline(cin, s);

	bool conf = 0;

	for (int i = 0; i < s.size(); i++) {
		if (conf == 1) {
			cout << s[i];
			if (s[i] == '>') {
				conf = 0;
			}
			continue;
		}
		if (s[i] == '<') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			conf = 1;
			cout << s[i];
			continue;
		}
		if (s[i] == ' ') {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			cout << ' ';
			continue;
		}
		else {
			st.push(s[i]);
		}
	}
	

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}