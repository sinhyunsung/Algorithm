#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

#define ll long long

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unordered_map<string, int> m;

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		m[s] += 1;
	}
	
	vector<pair<string, int>> m2(m.begin(), m.end());
	sort(m2.begin(), m2.end(), cmp);

	int result = m2.front().second;
	int i = 0;
	while (m2[i].second == result) {
		cout << m2[i].first << "\n";
		i++;
	}
	

	


}