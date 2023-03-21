#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long 


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	int result = 0;
	for (int i = 0; (1 << i) <= 64; i++) {
		if (((1 << i) & n) != 0) {
			result++;
		}
	}
	cout << result;
}


