
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	
	cin >> a >> b >> c;

	b = b + c;
	while (b > 59) {
		b = b - 60;
		a = a + 1;
	}
	while (a > 23) {
		a = a - 24;
	}

	cout << a << ' ' << b << endl;

	return 0;


}
