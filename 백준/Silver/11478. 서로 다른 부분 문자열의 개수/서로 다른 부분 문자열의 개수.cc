#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

vector<string> map[1001];

int hash_f(string s) {
	int prime = 65599;
	for (int i = 0; i < s.size()&& i<4; i++) {
		prime = ((prime << 5) + prime + int(s[i])) % 1000;
	}
	prime = ((prime << 5) + prime + s.size()) % 1000;
	return prime;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int result = 0;
	string s;
	cin >> s;

	string temp;

	temp.clear();

	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			temp += s[j];
			int idx = hash_f(temp);
			bool find = false;
			for (int k = 0; k < map[idx].size(); k++) {
				if (map[idx][k] == temp) {
					find = true;
					break;
				}
			}
			if (!find) {
				result++;
				map[idx].push_back(temp);
			}
		}
		temp.clear();
	}

	cout<<result << "\n";

}