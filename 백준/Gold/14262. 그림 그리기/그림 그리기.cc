#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int y, x, n;

	cin >> y >> x >> n;

	string s[50];

	for (int i = 0; i < y; i++) {
		cin >> s[i];
	}

	ll r=0, g=0, b=0;

	for (int i = 0; i < x; i++) {
		for (int j = 0; (j < y)&&(i+j<x); j++) {
			if (s[j][i + j] == '.') {
				continue;
			}
			if (s[j][i + j] == 'R') r++;
			if (s[j][i + j] == 'G') g++;
			if (s[j][i + j] == 'B') b++;
			break;
		}
	}

	for (int j = 1; j < y; j++) {
		for (int i = 0; (i < x) && (i + j < y); i++) {
			if (s[i + j][i] == '.') {
				continue;
			}
			if (s[i+j][i] == 'R') r++;
			if (s[i+j][i] == 'G') g++;
			if (s[i+j][i] == 'B') b++;
			break;
		}
	}
	int minn = max(x, y);

	char sim[100][100] = { 0 };


	ll tr = 0, tg = 0, tb = 0;
	if (minn > n) {
		for (int i = 0; i < n; i++) {
			for (int b = 0; b < y; b++) {
				for (int a = 0; a < x; a++) {
					if (s[b][a] != '.') {
						sim[b + i][a + i] = s[b][a];
					}
				}
			}
		}
		for (int i = 0; i < n + y; i++) {
			for (int j = 0; j < n + x; j++) {
				if (sim[i][j] == 'R')tr++;
				if (sim[i][j] == 'G')tg++;
				if (sim[i][j] == 'B')tb++;
			}
		}
	}
	else {
		for (int i = 0; i < minn; i++) {
			for (int b = 0; b < y; b++) {
				for (int a = 0; a < x; a++) {
					if (s[b][a] != '.') {
						sim[b + i][a + i] = s[b][a];
					}
				}
			}
		}
		for (int i = 0; i < minn + y; i++) {
			for (int j = 0; j < minn + x; j++) {
				if (sim[i][j] == 'R')tr++;
				if (sim[i][j] == 'G')tg++;
				if (sim[i][j] == 'B')tb++;
			}
		}
		tr += r * (n - minn);
		tg += g * (n - minn);
		tb += b * (n - minn);
	}

	cout << tr << "\n" << tg << "\n" << tb;
}