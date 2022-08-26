#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int n;

	cin >> n;

	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

}