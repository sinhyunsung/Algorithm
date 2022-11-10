#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int* l = new int[n + 1];
	bool* visit = new bool[n + 1];
	bool* cycle = new bool[n + 1];
	fill_n(visit, n + 1, false);
	fill_n(cycle, n + 1, false);


	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}

	int result = 0;

	for (int i = 1; i <= n; i++) {
		if (visit[i]) {
			continue;
		}
		int now = i;
		while (!visit[now]) {
			visit[now] = true;
			now = l[now];
		}


		while (!cycle[now]) {
			cycle[now] = true;
			now = l[now];
			result++;
		}
		now = i;
		while (!cycle[now]) {
			cycle[now] = true;
			now = l[now];
		}
	}
	cout << n - result << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int cs;
	cin >> cs;
	while (cs--) {
		solve();
	}
}