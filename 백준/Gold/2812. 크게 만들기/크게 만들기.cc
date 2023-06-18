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

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	string s;
	cin >> s;
	
	deque<char> q;

	for (int i = 0; i < n; i++) {
		while (!q.empty() && k && q.back() < s[i]) {
			q.pop_back();
			k--;
		}
		q.push_back(s[i]);
	}
	
	for (int i = 0; i < q.size()-k; i++) {
		cout << q[i];
	}
	




}