#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int result1 = 0;
int result2 = 0;

int fib(int n) {
	if (n == 1 || n == 2) {
		result1++;
		return 1;
	}
	return (fib(n - 1) + fib(n - 2));
}

int f[41];

int fibonacci(int n) {
	if (n == 1 || n == 2) {
		f[n] = 1;
	}
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		result2++;

	}
	return f[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << result1 << " " << result2;


}
