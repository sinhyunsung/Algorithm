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

	string s;
	int temp=1, result=0;

	stack<char> st;
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push('(');
			temp *= 2;
			continue;
		}
		if (s[i] == '[') {
			st.push('[');
			temp *= 3;
			continue;
		}
		if (s[i] == ')') {
			if (!st.empty()&&st.top() == '(') {
				if (i != 0 && s[i - 1] == '(') {
					result += temp;
				}
				temp /= 2;
				st.pop();
				continue;
			}
			else {
				result = 0;
				break;
			}
		}

		if (s[i] == ']') {
			if (!st.empty() && st.top() == '[') {
				if (i != 0 && s[i - 1] == '[') {
					result += temp;
				}
				temp /= 3;
				st.pop();
				continue;
			}
			else {
				result = 0;
				break;
			}
		}
	}
	if (!st.empty()) {
		result = 0;
	}

	cout << result;

}