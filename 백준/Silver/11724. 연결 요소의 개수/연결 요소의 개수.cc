#include <iostream>
#include <string>
#include <set>

using namespace std;

int find(int* l,int x){
	if (x == l[x]) {
		return x;
	}
	else {
		int y = find(l,l[x]);
		l[x] = y;
		return y;
	}
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m, a, b ,x,y;

	cin >> n >> m;

	int* l = new int[n + 1];

	for (int i = 1; i < n + 1; i++) {
		l[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		x = find(l, a);
		y = find(l, b);


		if (x < y) {
			l[y] = x;
		}
		else
		{
			l[x] = y;
		}
	}

	set<int> s;
	for (int i = 1; i < n + 1; i++) {
		find(l, i);
		s.insert(l[i]);
	}
	cout << s.size();
}