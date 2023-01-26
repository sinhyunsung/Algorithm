#include <iostream>

using namespace std;

int n, m, t;
pair<int, int> air1, air2;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m >> t;

	int** a = new int* [n];
	int** b = new int* [n];
	int** c = new int* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[m];
		b[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
			if (a[i][j] == -1 && !air1.first) {
				air1 = { i,j };
			}
			else if (a[i][j] == -1 && air1.first) {
				air2 = { i,j };
			}
		}
	}

	bool flag = true;
	int dust, diffusion, count ,ddx,ddy;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };



	for (int k = 0; k < t; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (flag) {
					dust = a[i][j];
				}
				else {
					dust = b[i][j];
				}
				if (dust == 0) {
					continue;
				}

				if (dust == -1) {
					if (flag) {
						b[i][j] = -1;
					}
					else {
						a[i][j] = -1;
					}
					continue;
				}

				diffusion = dust / 5;
				count = 0;

				for (int l = 0; l < 4; l++) {
					ddy = i + dy[l];
					ddx = j + dx[l];
					if (ddy >= 0 && ddx >= 0 && ddx < m && ddy < n) {
						if (flag) {
							if (a[ddy][ddx] != -1) {
								b[ddy][ddx] += diffusion;
								count ++;
							}
						}
						else {
							if (b[ddy][ddx] != -1) {
								a[ddy][ddx] += diffusion;
								count++;
							}
						}
					}
				}
				if (flag) {
					b[i][j] += dust - count * diffusion;
					a[i][j] = 0;
				}
				else {
					a[i][j] += dust - count * diffusion;
					b[i][j] = 0;
				}


			}
		}

		int temp1,temp2;

		if (flag) {
			temp1 = b[air1.first][air1.second + 1];
			temp2 = 0;
		}
		else {
			temp1 = a[air1.first][air1.second + 1];
			temp2 = 0;
		}

		int targetx, targety;
		targetx = air1.second + 1;
		targety = air1.first;

		if (!flag) {
			while (targetx < m ) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
			targety--;

			while (targety >= 0) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targety--;
			}
			targety++;
			targetx--;

			while (targetx >= 0) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx--;
			}
			targetx++;
			targety++;

			while (targety < air1.first) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targety++;
			}
			targety--;
			targetx++;

			while (targetx < air1.second) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
		}
		else {

			while (targetx < m) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
			targety--;

			while (targety >= 0) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targety--;
			}
			targety++;
			targetx--;

			while (targetx >= 0) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx--;
			}
			targetx++;
			targety++;

			while (targety < air1.first) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targety++;
			}
			targety--;
			targetx++;
			while (targetx < air1.second) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
		}


		if (flag) {
			temp1 = b[air2.first][air2.second + 1];
			temp2 = 0;
		}
		else {
			temp1 = a[air2.first][air2.second + 1];
			temp2 = 0;
		}

		targetx = air2.second + 1;
		targety = air2.first;

		if (!flag) {
			while (targetx < m) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
			targety++;

			while (targety < n) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targety++;
			}
			targety--;
			targetx--;

			while (targetx >= 0) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx--;
			}
			targetx++;
			targety--;

			while (targety > air2.first) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targety--;
			}
			targety++;
			targetx++;
			while (targetx < air2.second) {
				temp1 = a[targety][targetx];
				a[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
		}
		else {

			while (targetx < m) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
			targety++;

			while (targety < n) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targety++;
			}
			targety--;
			targetx--;

			while (targetx >= 0) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx--;
			}
			targetx++;
			targety--;

			while (targety > air2.first) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targety--;
			}
			targety++;
			targetx++;
			while (targetx < air2.second) {
				temp1 = b[targety][targetx];
				b[targety][targetx] = temp2;
				temp2 = temp1;
				targetx++;
			}
			targetx--;
		}


		flag = !flag;

	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += a[i][j] + b[i][j];
		}
	}

	sum += 4;
	cout << sum;




}