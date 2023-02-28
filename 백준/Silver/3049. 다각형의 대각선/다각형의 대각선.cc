#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	cin >> n;

	cout << n * (n - 1) * (n - 2) * (n - 3) / 4 / 3 / 2 / 1;

}