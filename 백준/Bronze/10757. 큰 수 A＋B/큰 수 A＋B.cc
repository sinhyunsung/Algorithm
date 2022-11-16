
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b,c;
	cin >> a >> b;
	
	int a_len = a.length();
	int b_len = b.length();
	int len = (a_len >= b_len)?a_len : b_len;

	if (a_len < len) {
		for (int i = 0; i < (len - a_len); i++) {
			a = '0' + a;
		}
	}
	else
	{
		for (int i = 0; i < (len - b_len); i++) {
			b = '0' + b;
		}
	}

	int num3=0;
	for (int i = len-1; i >-1; i--)
	{
		int num1, num2, sum =0;
			num1 = (int)a[i]-'0';
			num2= (int)b[i]-'0';
		sum = (num1 + num2 + num3) % 10;
		
		num3 = (num1 + num2 + num3) /10;

		c = (char)(sum + '0')+c;
		
	}
	if(num3){ c = (char)(num3 + '0') + c; }
	
	cout << c;
	


}
