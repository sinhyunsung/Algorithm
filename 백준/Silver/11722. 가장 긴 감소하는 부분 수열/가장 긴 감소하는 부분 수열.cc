#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int n;

vector<int> q;

void input(int x){
	if (q.size() == 0) {
		q.push_back(x);
		return;
	}

	if (q.back() > x) {
		q.push_back(x);
		return;
	}

	int left = 0;
	int right = q.size()-1;

	while (left <= right && q.size() >= 2) {
		int mid = (left + right) / 2;
		if (x < q[mid]) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	q[left] = x;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int m;
	for (int i = 0; i < n; i++) {
		cin >> m;
		input(m);
	}

	cout << q.size();

}