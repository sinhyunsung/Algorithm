#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n, m;
	cin >> n >> m;

	int* bag = new int[m];
	pair<int, int>* jewel = new pair<int, int>[n];

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		jewel[i] = make_pair(a, b);
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		bag[i] = a;
	}

	sort(jewel, jewel + n);
	sort(bag, bag + m);

	priority_queue<int> q;

	long long int result = 0;
	int j = 0;

	for (int i = 0; i < m; i++) {
		while (j < n && bag[i] >= jewel[j].first) {
			q.push(jewel[j].second);
			j++;
		}
		if (!q.empty()) {
			result += q.top();
			q.pop();
		}
	}

	cout << result;

}