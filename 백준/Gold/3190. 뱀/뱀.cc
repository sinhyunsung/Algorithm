#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int n, k, m;

int l[101][101] = { 0 };
deque <pair<int, char>> direction;


int t = 0;
int headx = 1, heady = 1, tailx = 1, taily = 1;
int now_direction = 'R';

void cut_tail() {
	if (l[taily][tailx] == 2) {
		l[taily][tailx] = 0;
		tailx++;
		return;
	}
	if (l[taily][tailx] == 3) {
		l[taily][tailx] = 0;
		tailx--;
		return;
	}
	if (l[taily][tailx] == 4) {
		l[taily][tailx] = 0;
		taily++;
		return;
	}
	if (l[taily][tailx] == 5) {
		l[taily][tailx] = 0;
		taily--;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> k;

	int x, y;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		l[y][x] = 1;
	}

	cin >> m;

	int a; 
	char b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		direction.push_back(make_pair(a,b));
	}


	l[1][1] = 2;

	while (1) {
		t++;

		if (now_direction == 'R') {
			if (l[heady][headx + 1] == 1) {
				l[heady][headx + 1] = 2;
				headx++;
			}
			else if(headx + 1>n|| l[heady][headx + 1]>1){
				break;
			}
			else {
				l[heady][headx + 1] = 2;
				headx++;
				cut_tail();
			}
		}
		if (now_direction == 'L') {
			if (l[heady][headx - 1] == 1) {
				l[heady][headx - 1] = 3;
				headx--;
			}
			else if (headx - 1 < 1 || l[heady][headx - 1] > 1) {
				break;
			}
			else {
				l[heady][headx - 1] = 3;
				cut_tail();
				headx--;
			}
		}
		if (now_direction == 'D') {
			if (l[heady+1][headx] == 1) {
				l[heady+1][headx] = 4;
				heady++;
			}
			else if (heady + 1 > n || l[heady+1][headx] > 1) {
				break;
			}
			else {
				l[heady+1][headx] = 4;
				cut_tail();
				heady++;
			}
		}
		if (now_direction == 'U') {
			if (l[heady - 1][headx] == 1) {
				l[heady - 1][headx] = 5;
				heady--;
			}
			else if (heady - 1 < 1 || l[heady - 1][headx] > 1) {
				break;
			}
			else {
				l[heady - 1][headx] = 5;
				cut_tail();
				heady--;
			}
		}

		char turn;

		if (direction.size() > 0 && direction.front().first == t) {
			turn = direction.front().second;
			
			direction.pop_front();

			if (now_direction == 'R')
			{
				if (turn == 'L') {
					now_direction = 'U';
				}
				else {
					now_direction = 'D';
				}
			}
			else if (now_direction == 'L')
			{

				if (turn == 'L') {
					now_direction = 'D';
				}
				else {
					now_direction = 'U';
				}
			}
			else if (now_direction == 'D')
			{

				if (turn == 'L') {
					now_direction = 'R';
				}
				else {
					now_direction = 'L';
				}
			}
			else if (now_direction == 'U')
			{

				if (turn == 'L') {
					now_direction = 'L';
				}
				else {
					now_direction = 'R';
				}
			}

			if (now_direction == 'R')
			{
				l[heady][headx] = 2;
			}
			if (now_direction == 'L')
			{
				l[heady][headx] = 3;
			}
			if (now_direction == 'D')
			{
				l[heady][headx] = 4;
			}
			if (now_direction == 'U')
			{
				l[heady][headx] = 5;
			}
		}

	}
	
	cout << t;

}