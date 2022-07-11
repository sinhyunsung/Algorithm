#include <iostream> 
#include <string>


using namespace std;

string s;

bool palindrome[2500][2500] = { 0 };
int result[2501];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> s;
	
	for (int plus = 0; plus < s.size(); plus++) {
		for (int idx = 0; idx + plus < s.size(); idx++) {
			if (plus == 0) {
				palindrome[idx][idx + plus] = true;
				continue;
			}
			if (s[idx] == s[idx + plus] && (plus == 1 || palindrome[idx + 1][idx + plus - 1])) {
				palindrome[idx][idx + plus] = true;
			}
		}
	}

	result[0] = 0;
	result[1] = 1;

	for (int i = 2; i <= s.size(); i++) {
		result[i] = result[i - 1] + 1;
		for (int j = 0; j < i; j++) {
			if (palindrome[j][i - 1]) {
				result[i] = min(result[i], result[j] + 1);
			}
		}
	}
	cout << result[s.size()];

}
