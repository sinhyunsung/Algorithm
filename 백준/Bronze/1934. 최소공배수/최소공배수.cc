#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

int gcd(int x, int y) {
	int tmp;
	while (y != 0) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cs;

	cin >> cs;

	int a, b;
	for (int i = 0; i < cs; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << "\n";
	}

}