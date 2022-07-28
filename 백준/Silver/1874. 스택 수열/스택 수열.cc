#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> stack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	int now = 1;

	bool flag = true;

	int input;

	vector<int> result;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (flag) {
			while (now <= input) {
				stack.push_back(now);
				result.push_back(1);
				now++;
			}
			if (stack.back() == input) {
				stack.pop_back();
				result.push_back(0);
			}
			else {
				flag = false;
			}
		}
	}
	if (flag) {
		for (int i = 0; i < result.size(); i++) {
			if (result[i] == 1) {
				cout << '+' << "\n";
			}
			else {
				cout << '-' << "\n";
			}
		}
	}
	else {
		cout << "NO";
	}

}