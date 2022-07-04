#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int pi[1000000];

void kmp(string pat) {
	int i = 0;
	int j = 1;
	int leng = pat.size();
	while (j < leng) {
		if (pat[i] == pat[j]) {
			pi[j++] = ++i;
		}
		else {
			if (i == 0) {
				pi[j] = 0;
				j++;
			}
			else {
				i = pi[i-1];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n;
	string s;
	cin >> n >> s;

    kmp(s);

	cout << s.size() - pi[n-1];

}