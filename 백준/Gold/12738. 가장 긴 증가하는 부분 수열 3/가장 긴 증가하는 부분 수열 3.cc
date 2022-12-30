#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#define ll long long

using namespace std;

int n;

vector<ll> l;

void binary_search(ll x) {
	int start = 0;
	int end = l.size()-1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (l[mid] >= x) {
			end = mid-1;
		}
		else {
			start = mid+1;
		}
	}

	l[start] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;

	ll num;

	cin >> num;
	l.push_back(num);

	for (int i = 1; i < n; i++) {
		cin >> num;
		if (num > l.back()) {
			l.push_back(num);
		}
		else if(num < l.back()) {
			binary_search(num);
		}
	}

	cout << l.size();

}