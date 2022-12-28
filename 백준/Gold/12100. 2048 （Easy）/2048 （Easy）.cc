#include <iostream>
#include <deque>

using namespace std;

int n;

int** m;

int maxn = 0;

void dfs(int** newstat,int depth,int direction) {
	if (depth == 5) {
		return;
	}

	int** stat;
	stat = new int* [n];
	for (int i = 0; i < n; i++) {
		stat[i] = new int[n];
		for (int j = 0; j < n; j++) {
			 stat[i][j]= newstat[i][j];
		}
	}

	

	if (direction == 0) {
		for (int i = 0; i < n; i++) {
			int merge_idx = 0;
			int merge_n = stat[i][0];
			for (int j = 0; j < n; j++) {
				if (stat[i][j] == 0) {
					continue;
				}
				if (j == 0) {
					continue;
				}
				if (merge_n == stat[i][j]) {
					stat[i][merge_idx] *= 2;
					if (maxn < stat[i][merge_idx]) {
						maxn = stat[i][merge_idx];
					}
					stat[i][j] = 0;
					merge_idx++;
					merge_n = 0;
				}
				else {
					if (merge_n != 0) {
						merge_idx++;
					}
					stat[i][merge_idx] =stat[i][j];
					if (j != merge_idx) {
						stat[i][j] = 0;
					}
					merge_n = stat[i][merge_idx];
				}
				
			}
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < n; i++) {
			int merge_idx = n-1;
			int merge_n = stat[i][n-1];
			for (int j = n-1; j >=0; j--) {
				if (stat[i][j] == 0) {
					continue;
				}
				if (j == n-1) {
					continue;
				}
				if (merge_n == stat[i][j]) {
					stat[i][merge_idx] *= 2;
					if (maxn < stat[i][merge_idx]) {
						maxn = stat[i][merge_idx];
					}
					stat[i][j] = 0;
					merge_idx--;
					merge_n = 0;
				}
				else {
					if (merge_n != 0) {
						merge_idx--;
					}
					stat[i][merge_idx] = stat[i][j];
					if (j != merge_idx) {
						stat[i][j] = 0;
					}
					merge_n = stat[i][merge_idx];
				}

			}
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < n; i++) {
			int merge_idx = 0;
			int merge_n = stat[0][i];
			for (int j = 0; j < n; j++) {
				if (stat[j][i] == 0) {
					continue;
				}
				if (j == 0) {
					continue;
				}
				if (merge_n == stat[j][i]) {
					stat[merge_idx][i] *= 2;
					if (maxn < stat[merge_idx][i]) {
						maxn = stat[merge_idx][i];
					}
					stat[j][i] = 0;
					merge_idx++;
					merge_n = 0;
				}
				else {
					if (merge_n != 0) {
						merge_idx++;
					}
					stat[merge_idx][i] = stat[j][i];
					if (j != merge_idx) {
						stat[j][i] = 0;
					}
					merge_n = stat[merge_idx][i];
				}

			}
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < n; i++) {
			int merge_idx = n-1;
			int merge_n = stat[n-1][i];
			for (int j = n-1; j >= 0; j--) {
				if (stat[j][i] == 0) {
					continue;
				}
				if (j == n-1) {
					continue;
				}
				if (merge_n == stat[j][i]) {
					stat[merge_idx][i] *= 2;
					if (maxn < stat[merge_idx][i]) {
						maxn = stat[merge_idx][i];
					}
					stat[j][i] = 0;
					merge_idx--;
					merge_n = 0;
				}
				else {
					if (merge_n != 0) {
						merge_idx--;
					}
					stat[merge_idx][i] = stat[j][i];
					if (j != merge_idx) {
						stat[j][i] = 0;
					}
					merge_n = stat[merge_idx][i];
				}

			}
		}
	}


	dfs(stat, depth + 1, 0);
	dfs(stat, depth + 1, 1);
	dfs(stat, depth + 1, 2);
	dfs(stat, depth + 1, 3);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;


	m = new int* [n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
			if (maxn < m[i][j]) {
				maxn = m[i][j];
			}
		}
	}


	dfs(m,  0, 0);
	dfs(m, 0, 1);
	dfs(m, 0, 2);
	dfs(m, 0, 3);


	cout << maxn;


}