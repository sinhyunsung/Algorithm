#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

#define ll long long

using namespace std;



int n;
ll* l;

ll min_v = 100000000000;
ll result[3];

void check(int idx) {
	int p1 = 0;
	int p2 = n - 1;
	
	if (idx == p1) p1++;
	if (idx == p2) p2--;


	int next1,next2;
	while (p1 < p2) {
		if (abs(l[p1] + l[p2] + l[idx]) < min_v) {
			result[0] = l[p1];
			result[1] = l[p2];
			result[2] = l[idx];
			min_v = abs(l[p1] + l[p2] + l[idx]);
		}
		
		if (p1 + 1 == idx) {
			next1= p1+2;
		}
		else {
			next1 = p1+1;
		}
		if (p2 - 1 == idx) {
			next2 = p2-2;
		}
		else {
			next2 = p2-1;
		}

		if (abs(l[next1] + l[p2] + l[idx]) > abs(l[p1] + l[next2] + l[idx])) {
			p2 = next2;
		}
		else {
			p1 = next1;
		}

	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	l = new ll[n];
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	sort(l, l + n);
	
	for (int i = 0; i < n; i++) {
		check(i);
	}

	sort(result, result + 3);

	cout << result[0] << " " << result[1] << " " << result[2];

}