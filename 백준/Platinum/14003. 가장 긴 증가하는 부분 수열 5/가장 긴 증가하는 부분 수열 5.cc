#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define ll long long

int n;

ll l[1000001];
ll result[1000001];
vector<ll> leng;

ll binary_search(ll x) {
	ll start = 0;
	ll end = leng.size() - 1;
	while (start <= end) {
		ll mid = (start + end) / 2;
		if (leng[mid] < x) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return start;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n;

	cin >> l[0];
	leng.push_back(l[0]);
	result[0] = 0;

	for (int i = 1; i < n; i++) {
		cin >> l[i];
		if (leng.back() < l[i]) {
			leng.push_back(l[i]);
			result[i] = leng.size() - 1;
		}
		else {
			ll idx = binary_search(l[i]);
			leng[idx] = l[i];
			result[i] = idx;
		}
	}

	vector<ll> result2;

	int idx = n - 1;

	for (int i = leng.size() - 1; i >= 0; i--) {
		for (int j = idx; j >= 0; j--) {
			if (result[j] == i) {
				idx = j;
				result2.push_back(l[j]);
				break;
			}
		}
	}
	cout << leng.size() << "\n";

	for (int i = leng.size() - 1; i >= 0; i--) {
		cout << result2[i] << " ";
	}

}