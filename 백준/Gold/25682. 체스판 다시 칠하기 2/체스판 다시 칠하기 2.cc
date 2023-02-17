#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

int n, m, cs;
string s[2001];
pair<int, int> dp[2001][2001]; //B,W

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> cs;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = make_pair(0, 0);
			if ((i + j) % 2 == 0 && s[i][j] == 'W')dp[i][j].first++;
			if ((i + j) % 2 == 1 && s[i][j] == 'B')dp[i][j].first++;
			if ((i + j) % 2 == 0 && s[i][j] == 'B')dp[i][j].second++;
			if ((i + j) % 2 == 1 && s[i][j] == 'W')dp[i][j].second++;
			
			if (i > 0) { dp[i][j].first += dp[i - 1][j].first; dp[i][j].second += dp[i - 1][j].second;}
			if (j > 0) { dp[i][j].first += dp[i][j - 1].first; dp[i][j].second += dp[i][j - 1].second; }
			if (j > 0 && i > 0) { dp[i][j].first -= dp[i - 1][j - 1].first; dp[i][j].second -= dp[i - 1][j - 1].second; }
		}
	}

	int result = 100000000;
	int tmpb,tmpw;
	int tmpresult;
	for (int i = cs-1; i < n; i++) {
		for (int j = cs-1; j < m; j++) {
			tmpb = dp[i][j].first; tmpw = dp[i][j].second;
			
			if (i - cs >= 0) { tmpb -= dp[i - cs][j].first; tmpw -= dp[i - cs][j].second;}
			if (j-cs >= 0) { tmpb -= dp[i][j - cs].first; tmpw -= dp[i][j - cs].second; }
			if (j-cs >= 0 && i-cs >= 0) { tmpb += dp[i - cs][j - cs].first; tmpw += dp[i - cs][j - cs].second; }

			tmpresult = min(tmpb, tmpw);
			result = min(result, tmpresult);
		}
	}

	cout << result;

}