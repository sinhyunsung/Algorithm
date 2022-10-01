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
	int* l = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}
	int start = *max_element(l, l + n)-m;
	int end = *max_element(l, l + n);
	start < 0 ? start = 0 : start = start;

	while (start <= end) {
		long long r = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			l[i] - mid < 0 ? r = r : r=r + l[i] - mid;
		}
		if (r < m) {
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << end;
}
