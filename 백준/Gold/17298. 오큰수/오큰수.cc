#include <iostream>
#include <stack>
using namespace std;

#define ll long long



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	int n;
	int m[1000001];
	int result[1000001];
	fill_n(result, 1000001, -1);
	cin >> n;

	stack<int> st;


	for (int i = 1; i <= n; i++) {
		cin >> m[i];
		if (st.empty()) {
			st.push(i);
			continue;
		}

		while (!st.empty()&&m[st.top()] < m[i]) {
			result[st.top()] = m[i];
			st.pop();
		}

		st.push(i);
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] << " ";
	}

}