#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, c;
	cin >> n >> r >> c;
	
	int result = 0;

	while (n > 0) {
		n -= 1;
		int len = pow(2, n);
		if (r < len && c < len) {
			continue;
		}
		else if (r < len && c >= len) {
			c -= len;
			result += len * len;
		}
		else if (r >= len && c < len) {
			r -= len;
			result += 2*len * len;
		}
		else{
			r -= len;
			c -= len;
			result += 3 * len * len;
		}
	}
	cout << result;
}