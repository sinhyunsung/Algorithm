#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int num;
	cin >> num;

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (num == arr[i]) {
			result += 1;
		}
	}
	cout << result;
}
