#include <iostream>
#include <vector>
using namespace std;


int n;
int* a;
vector<int> b;

int binary_search(int x) {
	int left = 0;
	int right = b.size()-1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (b[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n;

	a= new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	b.push_back(a[0]);
	
	for (int i = 1; i < n; i++) {
		if (b.back() < a[i]) {
			b.push_back(a[i]);
		}
		else {
			b[binary_search(a[i])]=a[i];
		}	
	}

	cout << b.size();
}