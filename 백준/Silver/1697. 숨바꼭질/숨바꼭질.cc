#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <numeric>
#include <cmath>

using namespace std;



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r;
	cin >> n >> r;
	
	int l[100001] = { 0 };

	deque<int> dq;
	int a;
	dq.push_back(n);
	while (true) {
		 a = dq.front();
		 dq.pop_front();
		 if (a == r) {
			 cout << l[a];
			 break;
		 }
		 if (a > 0 && (l[a - 1] == 0 || l[a - 1] > l[a] + 1)) {
			 l[a - 1] = l[a] + 1;
			 dq.push_back(a-1);
		 }
		 if (a < 100000 && (l[a + 1] == 0 || l[a + 1] > l[a] + 1)) {
			 l[a + 1] = l[a] + 1;
			 dq.push_back(a+1);
		 }
		 if (a <= 50000 && (l[a * 2] == 0 || l[a * 2] > l[a] + 1)) {
			 l[a * 2] = l[a] + 1;
			 dq.push_back(a * 2);
		 }
	}


}