#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;

	cin >> n;

	deque<int> q;

	int a;
	int maxn;
	int minn;

	int result = 0;
	int i = 0;

	cin >> a;
	q.push_back(a);
	i++;
	cin >> a;
	q.push_back(a);
	i++;
	cin >> a;
	q.push_back(a);
	i++;

	while (!q.empty()){
		if (q.size() < 4 && i<n) {
			cin >> a;
			q.push_back(a);
			i++;
			continue;
		}

		if (q[0] == 0) {
			q.pop_front();
			continue;
		}

		if (q.size() == 1) {
			result += q[0] * 3;
			q.pop_front();
			continue;
		}
		
		if (q.size() == 2) {
			result += min(q[0],q[1]) * 5 + (max(q[0], q[1])-min(q[0], q[1])) * 3;
			q.pop_front();
			q.pop_front();
			continue;
		}
		if (q.size() == 3) {
			minn = min({ q[0], q[1],q[2] });
			result += minn * 7;
			q[0] -= minn;
			q[1] -= minn;
			q[2] -= minn;

			if (q[2] == 0) {
				q.pop_back();
				continue;
			}
			if (q[0] == 0) {
				q.pop_front();
				continue;
			}
			if (q[1] == 0) {
				result += q[0] * 3 + q[2] * 3;
				q.pop_front();
				q.pop_front();
				q.pop_front();
				continue;
			}
		}

		if (q[1] > q[2]&& q[1] > q[0]) {
			minn = min({ q[1],q[2],q[3] });
			if (minn > q[1] - q[0]) {
				minn = q[1] - q[0];
			}
			result += minn * 7;
			q[3] -= minn;
			q[1] -= minn;
			q[2] -= minn;
		}
		minn = min({ q[0], q[1],q[2] });
		result += minn * 7;
		q[0] -= minn;
		q[1] -= minn;
		q[2] -= minn;

		if (q[0] == 0) {
			q.pop_front();
			continue;
		}

		if (q[1] == 0) {
			result += q[0] * 3;
			q.pop_front();
			q.pop_front();
			continue;
		}

		if (q[2] == 0) {
			result += min(q[0], q[1]) * 5 + (max(q[0], q[1]) - min(q[0], q[1])) * 3;
			q.pop_front();
			q.pop_front();
			continue;
		}




	}
	cout << result;
}