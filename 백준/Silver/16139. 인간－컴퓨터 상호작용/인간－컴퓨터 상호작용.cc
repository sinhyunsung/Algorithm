#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

int alpha[200001][26]={0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n;

	cin >> s >> n;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0) { alpha[i][s[i] - 'a'] += 1; }
		else {
			for (int j = 0; j < 26; j++) {
				alpha[i][j]= alpha[i-1][j];
			}
			alpha[i][s[i] - 'a'] += 1;
		}
	}

	char target;
	int r, l;

	for (int i = 0; i < n; i++) {
		cin >> target >> l >> r;
		cout << alpha[r][target - 'a'] - alpha[l][target - 'a'] + (target == s[l]) << "\n";
	}

}