#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string m;
	cin >> n >> m;
	long long result=0;
	for (int i = 0; i < n; i++) {
		long long s = m[i] - 96;
		for (int j = 0; j < i; j++) {
			s *= 31;
		}
		result += s;
	}

	cout << result % 1234567891;

}