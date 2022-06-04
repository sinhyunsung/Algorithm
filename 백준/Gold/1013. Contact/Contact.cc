#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

void solve() {
	string n;
	cin >> n;
	
	while (!n.empty()) {
		if (n.front() == '0') {
			if (n[1] == '1') {
				n = n.substr(2, n.size() - 2);
			}
			else {
				cout << "NO\n";
				return;
			}
		}
		else {

			if (n.size()>3 && n[1] == '0' && n[2]=='0') {
				int idx = 1;
				while (n[idx] == '0') {
					idx++;
				}
				bool flag = true;
				while (n[idx] == '1') {
					idx++;
					flag = false;
				}
				if (flag) {
					cout << "NO\n";
					return;

				}
				if (idx+1<n.size()&& idx-2>=0&& n[idx + 1] == '0'&& n[idx - 2]=='1') {
					idx--;
				}
				n = n.substr(idx, n.size() - idx);
			}
			else {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
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