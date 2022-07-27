#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n,s;
	int len = 100005;
	cin >> n >> s;

	int front = -1;

	vector<long long int> sv;
	
	int k;

	long long int frontn;

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (sv.size() > 0) {
			k += sv[sv.size() - 1];
		}
		sv.push_back(k);

		if (front == -1) {
			frontn = 0;
		}
		else {
			frontn = sv[front];
		}

		if (sv.back() - frontn < s) {
			continue;
		}
		while (sv.back() - frontn >= s) {
			if (front == -1) {
				len = sv.size();
			}
			else {
				if (len > sv.size() - front - 1) {
					len = sv.size() - front - 1;
				}
			}
			front++;
			frontn = sv[front];
		}
		
	}
	if (len == 100005) {
		cout << 0;
	}
	else{
		cout << len;
	}
	
}