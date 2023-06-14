#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int n;
string v;
unordered_map<char, int> m;

bool comp(pair<char, int> a, pair<char, int> b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		for (int j = 0; j < v.size(); j++) {
			m[v[v.size() - 1 - j]] += pow(10, j);
		}
	}

	int result = 0;
	
	vector<pair<char, int>> q;

	for (pair<char, int> elem : m) {
		q.push_back(elem);
	}



	sort(q.begin(),q.end(),comp);
	
	int now = 9;
	int num[100] = { 0 };
	for (int i = 0; i < q.size(); i++) {
		if (num[q[i].first] == 0) {
			num[q[i].first] = now;
			now--;
		}
		result += num[q[i].first] * q[i].second;
	}

	cout << result;

	
}