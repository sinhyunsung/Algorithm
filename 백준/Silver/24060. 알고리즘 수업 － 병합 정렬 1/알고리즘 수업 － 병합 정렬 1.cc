#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int num[500001];

int result = 0;
int n, m;

void merge(int size, int left, int mid, int right) {
	int* tmp = new int[size];
	int i = left; int j = mid + 1; int t = 0;
	while (i <= mid && j <= right) {
		if (num[i] <= num[j]) { tmp[t] = num[i]; t++; i++; }
		else { tmp[t] = num[j]; t++; j++; }
	}
	while (i <= mid) { tmp[t] = num[i]; t++; i++; }
	while (j <= right) { tmp[t] = num[j]; t++; j++; }
	for (int i = left; i <= right; i++) {
		num[i] = tmp[i-left];
		result++;
		if (result == m) {
			cout << num[i];
		}
	}
}

void merge_sort(int start,int end) {
	if (start < end) {
		merge_sort(start, (start + end) / 2);
		merge_sort((start + end) / 2+1,end);
		merge(end - start + 1, start, (start + end) / 2, end);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	merge_sort(0, n - 1);

	if (result < m) {
		cout << -1;
	}


}