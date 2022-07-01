#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	while (1)
	{
		string a;
		cin >> a;
		if (a=="0") {
			break;
		}
		else
		{
			bool check = false;
			for (int i=0; i < a.size(); i++) {
				if (a[i] != a[a.size()-1-i]) {
					check = true;
					break;
				}
			}
			if (check)
			{
				cout << "no\n";
			}
			else
			{
				cout << "yes\n";
			}
		}

	}

}
