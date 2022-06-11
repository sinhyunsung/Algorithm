#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;

	int* l = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	sort(l, l + n);

	bool* visit = new bool[n];
	fill_n(visit, n, false);

	for (int i = 0; i < n; i++) {
		if (visit[i]) {
			continue;
		}
		bool flag = false;
		int flag_idx;
		for (int j = i + 1; j < n; j++) {
			if (l[i] + 1 == l[j]&&!visit[j]) {
				flag = true;
				flag_idx = j;
				break;
			}
			else if (l[i] + 1 < l[j]) {
				break;
			}
		}

		if (flag) {
			bool flag2 = false;
			int flag2_idx;
			for (int j = flag_idx + 1; j < n; j++) {
				if (l[flag_idx] + 1 <= l[j]&&!visit[j]) {
					flag2 = true;
					flag2_idx = j;
					break;
				}
			}
			if (flag2) {
				for (int j = i; j < n; j++) {
					if (l[i] == l[j]) {
						cout << l[j] << " ";
						visit[j] = true;
					}
					else {
						break;
					}
				}
				cout << l[flag2_idx] << " ";
				visit[flag2_idx] = true;

			}
			else {
				for (int j = flag_idx; j < n; j++) {
					if (l[flag_idx] == l[j]) {
						cout << l[j] << " ";
						visit[j] = true;
					}
					else {
						break;
					}
				}
				for (int j = i; j < n; j++) {
					if (l[i] == l[j]) {
						cout << l[j] << " ";
						visit[j] = true;
					}
					else {
						break;
					}
				}

			}
		}
		else {

			for (int j = i; j < n; j++) {
				if (l[i] == l[j]) {
					cout << l[j] << " ";
					visit[j] = true;
				}
				else {
					break;
				}
			}
		}
	}


}