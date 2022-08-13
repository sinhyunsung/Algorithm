#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define ll long long

ll T, n, m;

vector<ll> a, b;

map<int, int> value;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> T >> n;

	int num;

	cin >> num;
	a.push_back(num);
	for (int i = 1; i < n; i++) {
		cin >> num;
		a.push_back(a.back() + num);
	}
	cin >> m;

	cin >> num;
	b.push_back(num);
	for (int i = 1; i < m; i++) {
		cin >> num;
		b.push_back(b.back() + num);
	}

	ll result = 0;

	
	for (int i = 0; i < n; i++) {
		value[a[i]]++;
		for (int j = i+1; j < n; j++) {
			value[a[j] - a[i]]++;
		}
	}

	for (int i = 0; i < m; i++) {
		result += value[T - (b[i])];
		for (int j = i + 1; j < m; j++) {
			result += value[T - (b[j] - b[i])];
		}
	}

	cout << result;

}