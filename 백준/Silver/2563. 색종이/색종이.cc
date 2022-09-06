#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define ll long long

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;

	cin >> n;

	int** m = new int*[n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[2];
		cin >> m[i][0] >> m[i][1];
	}

	int k[101][101] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int x = m[i][0]; x < m[i][0] + 10; x++) {
			for (int y = m[i][1]; y < m[i][1] + 10; y++) {
				k[y][x] = 1;
			}
		}
	}
	int result = 0;

	for (int x = 1; x < 101; x++) {
		for (int y =1; y < 101; y++) {
			if(k[y][x]) result++;
		}
	}
	
	cout << result;
	

}