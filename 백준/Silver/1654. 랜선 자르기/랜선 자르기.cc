#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	long long* l = new long long[n];

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	long long start, end;
	start = 1;
	end = *max_element(l, l + n);
	
	while (start <= end) {
		long long mid = (start + end) / 2;
		int ran = 0;
		for (int i = 0; i < n; i++) {
			ran = ran + (l[i] / mid);
		}
		if (ran < m) {
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << end;
}
