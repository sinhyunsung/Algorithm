#include <iostream>
#include <map>
#include <vector>

using namespace std;

int** n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	string a, b;
	cin >> a >> b;

	n = new int* [a.size()+1];
	for (int i = 0; i < a.size() + 1; i++) {
		n[i] = new int[b.size() + 1];
		fill_n(n[i], b.size() + 1, 0);
	}

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1]) {
				n[i][j] = n[i-1][j - 1] + 1;
			}
			else {
				n[i][j] = max(n[i - 1][j], n[i][j - 1]);
			}
		}
	}

	string result = "";

	int x = b.size();
	int y = a.size();

	while (x != 0 && y != 0) {
		if (a[y-1] == b[x-1]) {
			result.push_back(a[y-1]);
			y -= 1;
			x -= 1;
		}
		else {
			if (n[y][x] == n[y - 1][x]) {
				y -= 1;
			}
			else {
				x -= 1;
			}
		}
	}
	cout << n[a.size()][b.size()] << "\n";


	for (int i = 0; i < result.size(); i++) {
		cout << result[result.size() - 1 - i];
	}
	
}