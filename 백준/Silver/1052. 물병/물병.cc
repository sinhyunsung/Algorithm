#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;

	cin >> n >> k;

	int m[30] = { 0 };
	int mn[30];

	mn[0] = 1;
	for (int i = 1; i < 30; i++) {
		mn[i] = mn[i-1] * 2;
	}

	int i = 0;
	while (n != 0) {
		m[i] = n % 2;
		n = n / 2;
		i++;
	}

		
	int now = 0;
	for (int i = 0; i < 30; i++) {
		if (m[i]) {
			now++;
		}
	}

	if (k >= now) {
		cout << 0;
		return 0;
	}

	int sub = now - k;
	int result = 0;
	while (k<now) {
		int target;
		for (int j = 0; j < 30; j++) {
			if (m[j]) {
				target = j;
				m[j] = 0;
				break;
			}
		}
		for (int j = target; j < 28; j++) {
			result += mn[j];
			if (m[j+1]) {
				m[j + 1] = 0;
				m[j + 2] +=1;
				break;
			}
		}
		for (int j = target; j < 29; j++) {
			if (m[j] == 2) {
				m[j] = 0;
				m[j + 1]++;
			}
		}

		now = 0;
		for (int l = 0; l < 30; l++) {
			if (m[l]) {
				now++;
			}
		}

	}

	cout << result;


}