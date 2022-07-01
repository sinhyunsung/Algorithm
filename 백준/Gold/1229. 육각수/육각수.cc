#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define ll long long

using namespace std;

vector<int> six;
int dp[1000001];
int k;

void fill_dp() {
	for (int i = 0; i < 151; i++) {
		for (int j = 0; j < six.size(); j++) {
			if (i + six[j] > 150) {
				break;
			}
			dp[i + six[j]] = min(dp[i + six[j]], dp[i]+1);
		}
	}
}


int search(int target, int depth) {
	if (depth > 3) {
		return 100000;
	}
	if (target < 150) {
		return dp[target];
	}
	for (int i = 0; i < six.size(); i++) {
		if (target < six[i]) {
			break;
		}
		if (target > (4- depth) * six[i]) {
			continue;
		}
		dp[target] = min(dp[target], 1 + search(target - six[i],depth+1));
	}
	return dp[target];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	six.push_back(1);
	for (int i = 5; six.back() < 1000001; i += 4) {
		six.push_back(six.back() + i);
	}

	fill_n(dp, 1000001, 100000);
	dp[0] = 0;
	
	cin >> k;
	
	fill_dp();


	cout << search(k,0);




}