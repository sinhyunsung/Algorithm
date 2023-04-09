#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long

bitset<8> gear[4];


void turn_w(int idx) {
	bool temp = gear[idx][0];
	gear[idx] = gear[idx] >> 1;
	gear[idx][7] = temp;
}
void turn_b(int idx) {
	bool temp = gear[idx][7];
	gear[idx] = gear[idx] << 1;
	gear[idx][0] = temp;
}
void turn(int idx, int direction) {
	int stat[4] = { 0 };
	stat[idx] = direction;
	for (int i = idx - 1; i >= 0; i--) {
		if (gear[i + 1][1] != gear[i][5]) {
			stat[i] = -stat[i + 1];
		}
	}

	for (int i = idx + 1; i < 4; i++) {
		if (gear[i - 1][5] != gear[i][1]) {
			stat[i] = -stat[i - 1];
		}
	}

	for (int i = 0; i < 4; i++) {
		if (stat[i] == 1) {
			turn_w(i);
		}
		if (stat[i] == -1) {
			turn_b(i);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string b;
	
	for (int i = 0; i < 4; i++) {
		cin >> b;
		gear[i] = bitset<8>(b);
	}
	
	int n;
	cin >> n;
	int q, w;
	for (int i = 0; i < n; i++) {
		cin >> q >> w;
		turn(q-1, w);
	}
	

	cout << gear[0][7]+ gear[1][7]*2+ gear[2][7]*4+ gear[3][7]*8;

}