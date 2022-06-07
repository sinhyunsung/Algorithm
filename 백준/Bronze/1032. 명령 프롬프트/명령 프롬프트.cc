#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

#define ll long long int

using namespace std;

int main() {
	string a, b;
	int n;

	cin >> n >>a;

	for (int i = 0; i < n - 1; i++) {
		cin >> b;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j]) {
				a[j] = '?';
			}
		}
	}
	cout << a;
}