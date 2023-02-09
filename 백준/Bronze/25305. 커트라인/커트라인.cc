#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int* k;
int n, m;

void heapify(int idx,int len) {
	int left = idx * 2;
	int right = idx * 2 + 1;
	int target = idx;
	

	if (left <= len && k[left] > k[target]) {
		target = left;
	}
	if (right <= len && k[right] > k[target]) {
		target = right;
	}
	if (target != idx) {
		swap(k[idx], k[target]);
		heapify(target,len);
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n >> m;

	k = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}

	for (int i = n/2; i >= 1; i--) {
		heapify(i,n);
	}

	for (int i = n; i >= 2; i--) {
		swap(k[i], k[1]);
		heapify(1, i - 1);
	}

	cout << k[n - m+1];
}
