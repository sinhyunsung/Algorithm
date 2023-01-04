#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> map[5001];


int hashf(string s) {
	int result = 5851;
	for (int i = 0; i < s.size(); i++) {
		result = ((result << 5) + result + int(s[i])) % 5000;
	}
	return result;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		map[hashf(s)].push_back(s);
	}

	int result = 0;

	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < map[hashf(s)].size(); j++) {
			if (s == map[hashf(s)][j]) {
				result++;
				break;
			}
		}
	}

	cout << result;


}