#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	map<int, int> m;
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,d;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		m[d]++;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d;
		auto s = m.find(d);
		if (s != m.end()) {
			cout << s->second << " ";
		}
		else
		{
			cout << 0 << " ";

		}
	}


}
