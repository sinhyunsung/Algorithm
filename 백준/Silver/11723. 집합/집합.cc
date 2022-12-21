#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n,v;
	string m;

	int l = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		
		if (m == "all") {
			l |= ~(0);
		}
		else if (m == "empty") {
			l &= 0;
		}
		else {
			cin >> v;
			if (m == "add") {
				l |= (1 << v);
			}else if (m == "remove") {
				l &= ~(1 << v);
			}
			else if (m == "check") {
				if (l & (1 << v)) {
					cout << 1 << "\n";
				}
				else {
					cout << 0 << "\n";
				}
			}
			else if (m == "toggle") {
				l ^= (1 << v);
			}
		}
	}

}