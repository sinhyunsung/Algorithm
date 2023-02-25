#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int y,x,time;
	cin >> y >> x;

	string s[50];
	for (int i = 0; i < y; i++) {
		cin >> s[i];
	}

	cin >> time;

	int count[50] = { 0 };

	int result = 0;
	int same;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (s[i][j] == '0') {
				count[i]++;
			}
		}

		if (time>=count[i] && count[i] % 2 == time % 2) {
			same = 0;
			for (int k = 0; k < y; k++) {
				if (s[i] == s[k]) {
					same++;
				}
			}
			result = max(result, same);
		}
	}

	cout << result;


}