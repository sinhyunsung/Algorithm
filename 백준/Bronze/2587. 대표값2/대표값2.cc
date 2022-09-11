#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int a[5];
	int result = 0;

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		result += a[i];
	}
	sort(a,a+5);
	cout << result/5 << "\n" << a[2];

}
