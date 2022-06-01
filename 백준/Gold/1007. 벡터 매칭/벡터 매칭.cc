#include <iostream>
#include <deque>
#include <vector>
#include <math.h>

using namespace std;


int n;
long double minn;

vector<pair<long long int, long long int>> dot;
vector<bool> idx;

void seq(int depth,int start) {
	if (depth == n / 2) {
		double a;
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++) {
			if (idx[i]) {
				x += dot[i].first;
				y += dot[i].second;
			}
			else {
				x -= dot[i].first;
				y -= dot[i].second;
			}
		}

		a = sqrt(pow(x,2)+pow(y,2));
		if (minn > a) {
			minn = a;
		}
		return;
	}

	for (int i = start; i < n; i++) {
		idx[i] = true;
		seq(depth + 1,i+1);
		idx[i] = false;
	}
}


void solve() {
	cin >> n;
	minn = 1000000000;
	int a, b;
	dot.clear();
	idx.clear();

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		dot.push_back(make_pair(a, b));
		idx.push_back(false);
	}

	seq(0,0);

	cout << minn << "\n";
	
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie(); 
	cout.precision(18);

	int cs;
	cin >> cs;

	for (int i = 0; i < cs; i++) {
		solve();
	}
	
}