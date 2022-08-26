#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

string dp[101][101] = {""};

string str_plus(string a, string b) {

	int asize, bsize;
	asize = a.size();
	bsize = b.size();
	int idx = 1;
	string result = "";
	int seq = 0;
	while (!(idx > asize && idx > bsize)) {
		
		if (idx <= asize) {
			seq += int(a[asize - idx])-48;
		}
		if (idx <= bsize) {
			seq += int(b[bsize - idx]) - 48;
		}
		if (seq > 9) {
			seq -= 10;
			result = char(seq + 48)+result;
			seq = 1;
		}
		else {
			result = char(seq + 48) + result;
			seq = 0;
		}
		idx++;
	}
	if (seq == 1) {
		result = char(seq + 48) + result;
	}
	return result;

}


string combination(int a, int b) {
	if (b == 0 || a==b) {
		dp[a][b] = "1";
		return "1";
	}
	string num1, num2;
	if (dp[a-1][b] == "") {
		num1 = combination(a-1, b);
	}
	else {
		num1 = dp[a-1][b];
	}
	if (dp[a-1][b - 1] == "") {
		num2 = combination(a-1, b - 1);
	}
	else {
		num2 = dp[a-1][b - 1];
	}
	dp[a][b] = str_plus(num1, num2);
	return dp[a][b];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m, n;
	cin >> m >> n;

	cout << combination(m, n);

	
}
