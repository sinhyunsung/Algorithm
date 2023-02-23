#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

#define ll long long

vector<int> tree[50];

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int a;
	int root;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == -1) {
			root = i;
		}
		else {
			tree[a].push_back(i);
		}
;	}

	int target;

	cin >> target;

	deque<int> q;
	if (target != root) {
		q.push_back(root);
	}
	
	int result = 0;

	int now;
	bool leaf_flag;
	while (!q.empty()) {
		now = q.front();
		q.pop_front();
		leaf_flag = true;
		for (int i = 0; i < tree[now].size(); i++) {
			if (tree[now][i] != target) {
				q.push_back(tree[now][i]);
				leaf_flag = false;
			}
		}
		if (leaf_flag) {
			result++;
		}
	}

	cout << result;
}