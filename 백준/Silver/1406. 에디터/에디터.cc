#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

stack<char> l;
stack<char> r;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		l.push(s[i]);
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'L') {
			if (l.empty()) {
				continue;
			}
			char c = l.top();
			l.pop();
			r.push(c);
			continue;
		}
		if (s[0] == 'D') {
			if (r.empty()) {
				continue;
			}
			char c = r.top();
			r.pop();
			l.push(c);
			continue;
		}

		if (s[0] == 'B') {
			if (l.empty()) {
				continue;
			}
			l.pop();
			continue;
		}
		char c;
		cin >> c;
		l.push(c);
	}

	while (!l.empty()) {
		char c = l.top();
		l.pop();
		r.push(c);
	}

	while (!r.empty()) {
		char c = r.top();
		r.pop();
		cout << c;
	}

}