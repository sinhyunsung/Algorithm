
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a, b, c;
	
	cin >> a >> b >> c;

	if (a == b && a == c) {
		cout << 10000 + a * 1000;
	}
	else if ((a == b && b != c) || (a == c && b != c))
	{
		cout << 1000 + a * 100;
	}
	else if (c == b && a != c)
	{
		cout << 1000 + c * 100;
	}
	else
	{
		if (a > b && a > c) {
			cout << 100 * a;
		}
		else if (b > a && b > c) {
			cout << 100 * b;
		}
		else
		{
			cout << 100 * c;
		}
	}


}
