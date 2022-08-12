#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;
int score[16][16];

int dp[16][1<<16];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		fill_n(dp[i], (1 << n), 100000000);
		dp[i][1 << i] = score[0][i];
	}

	for (int state = 1; state < (1 << 16); state++) {
		for (int current = 0; current < n; current++) {
			if (state & (1 << current)) {
				for (int prev = 0; prev < n; prev++) {
					if (dp[prev][state & ~(1 << current)]!=0&&score[prev][current]!=0&&state | (1 << prev)) {
						dp[current][state] = min(dp[current][state], dp[prev][state & ~(1 << current)] + score[prev][current]);
					}
				}
			}
		}
	}

	cout << dp[0][(1 << n) - 1];

}
