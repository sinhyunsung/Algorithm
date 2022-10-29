#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

void heap_push(long long* l, long long v, int size) {
	l[size] = v;
	while (size > 1) {
		int idx = size;
		size /= 2;
		if (l[idx] > l[size]) {
			long long temp = l[idx];
			l[idx] = l[size];
			l[size] = temp;
			continue;
		}
		break;
	}
}

void heap_delete(long long* l, int size) {
	l[1] = l[size];
	int idx = 1;
	while (idx <= size / 2) {
		int left = idx * 2;
		int right = idx * 2 + 1;
		int target = idx;
		if (left <= size && l[left] > l[target]) {
			target = left;
		}
		if (right <= size && l[right] > l[target]) {
			target = right;
		}
		if (idx != target) {
			long long temp = l[target];
			l[target] = l[idx];
			l[idx] = temp;
			idx = target;
			continue;
		}
		break;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, c;
	long long k;
	string m;

	long long* maxheap1 = new long long[1000004];
	long long* maxheap2 = new long long[1000004];
	long long* minheap1 = new long long[1000004];
	long long* minheap2 = new long long[1000004];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		int maxcnt1 = 1;
		int maxcnt2 = 1;
		int mincnt1 = 1;
		int mincnt2 = 1;

		for (int j = 0; j < c; j++) {
			cin >> m >> k;
			if (m == "I") {
				heap_push(maxheap1, k, maxcnt1);
				heap_push(minheap1, -k, mincnt1);
				maxcnt1++;
				mincnt1++;
			}
			else
			{
				while (maxcnt2 > 1 && maxheap1[1] == maxheap2[1]) {

					maxcnt1--;
					maxcnt2--;
					heap_delete(maxheap1, maxcnt1);
					heap_delete(maxheap2, maxcnt2);

				}
				while (mincnt2 > 1 && minheap1[1] == minheap2[1]) {

					mincnt1--;
					mincnt2--;
					heap_delete(minheap1, mincnt1);
					heap_delete(minheap2, mincnt2);

				}

				if (k == 1 && maxcnt1 > 1) {
					maxcnt1--;
					heap_push(minheap2, -maxheap1[1], mincnt2);
					heap_delete(maxheap1, maxcnt1);
					mincnt2++;
				}
				if(k==-1 && mincnt1>1)
				{

					mincnt1--;
					heap_push(maxheap2, -minheap1[1], maxcnt2);
					heap_delete(minheap1, mincnt1);
					maxcnt2++;

				}
			}
		}

		while (maxcnt2 > 1 && maxheap1[1] == maxheap2[1]) {

			maxcnt1--;
			maxcnt2--;
			heap_delete(maxheap1, maxcnt1);
			heap_delete(maxheap2, maxcnt2);

		}
		while (mincnt2 > 1 && minheap1[1] == minheap2[1]) {

			mincnt1--;
			mincnt2--;
			heap_delete(minheap1, mincnt1);
			heap_delete(minheap2, mincnt2);

		}
		if (maxcnt1 > 1) {
			cout << maxheap1[1] << " " << -minheap1[1] << "\n";
		}
		else {
			cout << "EMPTY" << "\n";
		}
	}




}
