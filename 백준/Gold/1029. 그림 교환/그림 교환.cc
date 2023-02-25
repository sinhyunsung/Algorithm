#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

int n;
int m[16][16];
int k[16][1 << 15];
int result = 0;

void dp(int now_human, int state, int now_value, int depth) {
	result = (max(result, depth));

	for (int i = 1; i <= n; i++) {
		if (state & ( 1<< (i - 1))) {
			continue;
		}

		if (m[now_human][i] >= now_value && k[i][state | (1 << (i - 1))] > now_value) {
			k[i][state | (1 << (i - 1))] = m[now_human][i];
			dp(i, state | (1 << (i - 1)), m[now_human][i] ,depth+1);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			m[i+1][j+1] = s[j] - '0';
		}
	}
	fill_n(&k[0][0], 16*(1 << 15), 10000);

	dp(1, 1, 0,1);

	cout << result;
}