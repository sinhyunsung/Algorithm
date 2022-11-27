#include <iostream>

using namespace std;

#define ll long long int

ll a[5][5];
ll result[5][5];

void matrix_multiplication(ll n, ll m) {
	if (m <= 0) {
		return;
	}
	if (m % 2 == 1) {
		ll zero[5][5] = { 0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					zero[i][j] += result[i][k] * a[k][j] %1000;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result[i][j] = zero[i][j] % 1000;
			}
		}
		m -= 1;
	}
	
		ll zero[5][5] = { 0 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					zero[i][j] += a[i][k] * a[k][j] % 1000;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = zero[i][j] % 1000;
			}
		}
		m /= 2;
		matrix_multiplication(n, m);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, m;
	cin >> n >> m;



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i == j) {
				result[i][j] = 1;
			}
			else
			{
				result[i][j] = 0;
			}
		}
	}

	matrix_multiplication(n, m);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << result[i][j] <<" ";
		}
		cout << "\n";
	}

}
