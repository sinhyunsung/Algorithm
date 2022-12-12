
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<int>l;
	cin >> n;

	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		l.push_back(num);
	}
	
	int* l2 = new int[n];
	int* l3 = new int[n];

	fill(l2, l2 + n, 1);
	fill(l3, l3 + n, 1);
	int max2, max3;
	max2 = l[0];
	max3 = l[n-1];


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (l[i] > l[j] && l2[i]<=l2[j]) {
				l2[i] = l2[j] + 1;
			}

			if (l[n - 1 - i] > l[n -1- j] && l3[n - 1 - i] <= l3[n - 1 - j]) {
				l3[n - 1 - i] = l3[n -1- j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (l2[i] + l3[i] > max) {
			max = l2[i] + l3[i];
		}
	}

	cout << max-1;

}