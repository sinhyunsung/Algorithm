#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

#define ll long long

using namespace std;

stack<char> stk;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string target;
	cin >> target;

	for (int i = 0; i < target.size(); i++) {
		if (target[i] >= 'A' && target[i] <= 'Z') {
			cout << target[i];
		}
		else if (target[i] == ')') {
			while (1) {
				char now = stk.top();
				if (now == '(') {
					stk.pop();
					break;
				}
				else {
					cout << now;
					stk.pop();
				}
			}
		}
		else {
			if (target[i] == '+' || target[i] == '-') {
				while (1) {
					if (!stk.empty() && stk.top() != '(' && stk.top() != ')') {
						cout << stk.top();
						stk.pop();
					}
					else {
						break;
					}
				}
			}
			if (target[i] == '*' || target[i] == '/') {
				while (1) {
					if (!stk.empty() && stk.top() != '(' && stk.top() != ')' && (stk.top() == '*'|| stk.top() == '/')) {
						cout << stk.top();
						stk.pop();
					}
					else {
						break;
					}
				}
			}
			stk.push(target[i]);
		}
	}
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}

}
