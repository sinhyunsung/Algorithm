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

int n, k;
int v[101];
bool in[101] = { 0 };
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	int result = 0;
	for (int i = 1; i <= k; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= k; i++) {
		if (in[v[i]] == 1) {
			continue;
		}
		if (cnt < n) {
			in[v[i]] = 1;
			cnt++;
		}
		else
		{
			int max_idx = 0;
			int target = -1;
			for (int num = 1; num < 101; num++) {
				if (in[num]) {
					bool check = true;
					for (int j = i; j <= k; j++) {
						if (v[j] == num) {
							check = false;
							if (j > max_idx) {
								max_idx = j;
								target = num;
							}
							break;
						}
					}
					if (check) {
						target = num;
						break;
					}
				}
			}
			in[target] = 0;
			in[v[i]] = 1;
			result++;
			
		}
	}
	cout << result;
}