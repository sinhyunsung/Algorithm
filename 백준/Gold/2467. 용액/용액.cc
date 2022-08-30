#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;

	cin >> n;

	int m[100000];

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}

	int l = 0;
	int r = n - 1;

	int low = m[0];
	int high = m[n - 1];
	while (l < r) {
		if (abs((high + low)) > abs((m[r] + m[l]))) {
			 low = m[l];
			 high = m[r];
		}

		if (m[r] + m[l] == 0) {
			break;
		}
		
		if (abs(m[l] + m[r - 1]) > abs(m[l + 1] + m[r])) {
			l++;
		}
		else {
			r--;
		}
	}
	
	cout << low << " " << high;
}
