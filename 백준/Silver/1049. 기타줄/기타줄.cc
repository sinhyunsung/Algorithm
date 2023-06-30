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

int n, m;
vector<int> p;
vector<int> s;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	int a;
	for (int i = 0; i < m; i++) {
		cin >> a;
		p.push_back(a);
		cin >> a;
		s.push_back(a);
	}
	sort(p.begin(), p.end());
	sort(s.begin(), s.end());
	int result = 0;

	if (p[0] >= s[0] * 6) {
		result = s[0] * n;
	}
	else {
		result = p[0] * (n / 6);
		n = n % 6;
		if (p[0] >= s[0] * n) {
			result += s[0] * n;
		}
		else {
			result += p[0];
		}
	}
	cout << result;
}