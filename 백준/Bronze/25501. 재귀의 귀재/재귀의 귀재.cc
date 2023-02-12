#include <iostream>
#include <deque>
#include<cstring>

using namespace std;

int b;

int recursion(const char* s, int l, int r) {
	b++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		b = 0;
		cin >> a;
		cout << isPalindrome(a.c_str());
		cout << " " << b << "\n";
	}


}