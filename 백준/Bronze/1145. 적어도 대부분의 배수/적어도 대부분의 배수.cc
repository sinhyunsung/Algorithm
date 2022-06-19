#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define ll long long

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n[5];

	int result = 1;

	for (int i = 0; i < 5; i++) {
		cin >> n[i];
	}
	
	while (1) {
		int conf = 0;
		for (int i = 0; i < 5; i++) {
			if (result % n[i] == 0) {
				conf++;
			}
		}
		if (conf >= 3) {
			cout << result;
			break;
		}
		result++;
	}
	

}