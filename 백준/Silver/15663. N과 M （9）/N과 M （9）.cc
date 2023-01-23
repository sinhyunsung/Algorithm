#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[8];
int n, m;
vector <int> q;
int visit_idx[8] = { false };

void sequence(int depth) {
	if (depth > m) {
		for (int i = 0; i < q.size(); i++) {
			cout << q[i] << " ";
		}
		cout << "\n";
		return;
	}
	bool visit[10001] = { false };

	for (int i = 0; i < n; i++) {
		
		if (!visit[a[i]] && !visit_idx[i])
		{
			visit[a[i]] = true;
			q.push_back(a[i]);
			visit_idx[i] = true;
			sequence(depth + 1);
			visit_idx[i] = false;
			q.pop_back();
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);

	sequence(1);


}