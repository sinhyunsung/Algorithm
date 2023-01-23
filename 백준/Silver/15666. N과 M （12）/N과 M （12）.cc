#include <iostream>
#include <set>
#include <vector>
#include <deque>
using namespace std;

int n, m;
vector<int> arr;
set<int> setarr;

deque<int> q;

void sequence(int depth,int max) {
	if (depth > m) {
		for (int i = 0; i < q.size(); i++) {
			cout << q[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 0; i < arr.size(); i++) {
		if (max <= arr[i]) {
			q.push_back(arr[i]);
			sequence(depth + 1, arr[i]);
			q.pop_back();

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		setarr.insert(temp);
	}

	for (auto v = setarr.begin(); v != setarr.end(); v++) {
		arr.push_back(*v);
	}

	sequence(1, 0);
	
}