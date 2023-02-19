#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define ll long long

deque<int> q;

int result = 0;
void left() {
	q.push_back(q[0]);
	q.pop_front();
	result++;
}
void right() {
	q.push_front(q[q.size()-1]);
	q.pop_back();
	result++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
	}
	int target;
	int idx;
	for (int i = 0; i < m; i++) {
		cin >> target;
		for (int j = 0; j < q.size(); j++) {
			if (target == q[j]) {
				idx = j;
				break;
			}
		}
		if (q.size() - idx < idx - 0) {
			for (int j = 0; j < q.size() - idx; j++) {
				right();
			}
		}
		else {

			for (int j = 0; j < idx; j++) {
				left();
			}
		}

		q.pop_front();

	}

	cout << result;

}