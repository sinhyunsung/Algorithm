#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int* road = new int[n - 1];
	int* city = new int[n];

	for (int i = 0; i < n - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> city[i];
	}

	int now_price=200000000;
	int result = 0;

	for (int i = 0; i < n - 1; i++) {
		now_price = min(now_price, city[i]);
		result += road[i] * now_price;
	}

	cout << result;
}