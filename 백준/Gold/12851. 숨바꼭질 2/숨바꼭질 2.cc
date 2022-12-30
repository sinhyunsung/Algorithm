#include <iostream>
#include <deque>

using namespace std;

int subin[100001];
int n,m;

deque<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	bool flag = false;
	int result = 0;
	int result_time;

	q.push_back(make_pair(n, 0));
	subin[n] = 0;
	int now,time;


	while (!q.empty()) {
	
		
		now = q.front().first;
		time = q.front().second;
		q.pop_front();
		subin[now] = time;

		if (now == m && flag==false) {
			cout << time;
			result_time = time;
			result++;
			flag = true;
			continue;
		}
		if (flag) {
			if (result_time < time) {
				continue;
			}
			else {
				if (now == m) {
					result++;
					continue;
				}
			}

		}

		if (now - 1 >= 0 && subin[now - 1] == NULL) {
			q.push_back(make_pair(now - 1, time + 1));
		}
		if ( now + 1 < 100001 && subin[now + 1] == NULL) {
			q.push_back(make_pair(now + 1, time + 1));
		}
		if ( now * 2 < 100001 && subin[now *2] == NULL) {
			q.push_back(make_pair(now *2, time + 1));
		}

	}

	cout << "\n" << result;

}