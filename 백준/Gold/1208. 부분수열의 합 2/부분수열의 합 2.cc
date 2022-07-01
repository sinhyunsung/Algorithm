#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int n, s;
int* l;

unordered_map<int, int> mapv;

long long int result = 0;

void left(int start, int end, int sumv) {
	if (start > end) {
		mapv[sumv] += 1;
		return;
	}

	left(start + 1, end, sumv);
	left(start + 1, end, sumv + l[start]);
}

void right(int start, int end, int sumv) {

	if (start > end) {
		result += mapv[s - sumv];
		return;
	}

	right(start + 1, end, sumv);
	right(start + 1, end, sumv + l[start]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> s;
	l = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	left(0, n / 2, 0);
	right(n / 2 + 1, n - 1, 0);
	if (s == 0) {

		cout << result - 1;
	}
	else {
		cout << result;
	}
}