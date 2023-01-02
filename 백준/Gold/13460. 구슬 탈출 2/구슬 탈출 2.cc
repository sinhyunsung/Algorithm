#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define ll long long

using namespace std;

int n, m;

string l[10];

pair<int, int> start_blue, start_red, hole;

int result = 15;

pair<int, int> left(pair<int, int> new_bead) {
	pair<int, int> bead = { 0,0 };
	bead.first = new_bead.first;
	bead.second = new_bead.second;
	while (1) {
		if (l[bead.first][bead.second - 1] == '.') { bead.second--; continue; }
		else if (l[bead.first][bead.second - 1] == '#') break;
		else if (l[bead.first][bead.second - 1] == 'R') break;
		else if (l[bead.first][bead.second - 1] == 'B') break;
		else if (l[bead.first][bead.second - 1] == 'O') { bead.first = -1; break; }
	}
	return bead;
}
pair<int, int> right(pair<int, int> new_bead) {
	pair<int, int> bead = { 0,0 };
	bead.first = new_bead.first;
	bead.second = new_bead.second;
	while (1) {
		if (l[bead.first][bead.second + 1] == '.') { bead.second += 1; continue; }
		else if (l[bead.first][bead.second + 1] == '#') break;
		else if (l[bead.first][bead.second + 1] == 'R') break;
		else if (l[bead.first][bead.second + 1] == 'B') break;
		else if (l[bead.first][bead.second + 1] == 'O') { bead.first = -1; break; }
	}
	return bead;
}
pair<int, int> up(pair<int, int> new_bead) {
	pair<int, int> bead = { 0,0 };
	bead.first = new_bead.first;
	bead.second = new_bead.second;
	while (1) {
		if (l[bead.first - 1][bead.second] == '.') { bead.first -= 1; continue; }
		else if (l[bead.first - 1][bead.second] == '#') break;
		else if (l[bead.first - 1][bead.second] == 'R') break;
		else if (l[bead.first - 1][bead.second] == 'B') break;
		else if (l[bead.first - 1][bead.second] == 'O') { bead.first = -1; break; }
	}
	return bead;
}
pair<int, int> down(pair<int, int> new_bead) {
	pair<int, int> bead = { 0,0 };
	bead.first = new_bead.first;
	bead.second = new_bead.second;
	while (1) {
		if (l[bead.first + 1][bead.second] == '.') { bead.first += 1; continue; }
		else if (l[bead.first + 1][bead.second] == '#') break;
		else if (l[bead.first + 1][bead.second] == 'R') break;
		else if (l[bead.first + 1][bead.second] == 'B') break;
		else if (l[bead.first + 1][bead.second] == 'O') { bead.first = -1; break; }
	}
	return bead;
}


void dfs(pair<int, int> blue, pair<int, int> red, int depth) {
	if (depth == 10) {
		return;
	}



	for (int i = 0; i < 4; i++) {

		pair<int, int> next_blue, next_red;

		bool red_in = false, blue_in = false;
		bool red_first;
		if (i == 0) {


			if (red.second < blue.second) {
				red_first = true;
				next_red = left(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
				next_blue = left(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
			}
			else {
				red_first = false;
				next_blue = left(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
				next_red = left(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
			}
		}
		if (i == 1) {
			if (red.second > blue.second) {
				red_first = true;
				next_red = right(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
				next_blue = right(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
			}
			else {
				red_first = false;
				next_blue = right(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
				next_red = right(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
			}
		}
		if (i == 2) {
			if (red.first > blue.first) {
				red_first = true;
				next_red = down(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
				next_blue = down(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
			}
			else {
				red_first = false;
				next_blue = down(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
				next_red = down(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
			}
		}
		if (i == 3) {
			if (red.first < blue.first) {
				red_first = true;
				next_red = up(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
				next_blue = up(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
			}
			else {
				red_first = false;
				next_blue = up(blue);
				if (next_blue.first == -1) {
					blue_in = true;
					l[blue.first][blue.second] = '.';
				}
				else {
					swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				}
				next_red = up(red);
				if (next_red.first == -1) {
					red_in = true;
					l[red.first][red.second] = '.';
				}
				else {
					swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				}
			}
		}

		if (red_in && !blue_in) {
			result = min(result, depth + 1);
			if (!red_first) {
				l[red.first][red.second] = 'R';
				swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
			}
			else {
				swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				l[red.first][red.second] = 'R';
			}
		}
		if (red_in && blue_in) {
			if (!red_first) {
				l[red.first][red.second] = 'R';
				l[blue.first][blue.second] = 'B';
			}
			else {
				l[blue.first][blue.second] = 'B';
				l[red.first][red.second] = 'R';
			}
		}
		if (!red_in && blue_in) {
			if (!red_first) {
				swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				l[blue.first][blue.second] = 'B';
			}
			else {
				l[blue.first][blue.second] = 'B';
				swap(l[red.first][red.second], l[next_red.first][next_red.second]);
			}
		}
		if (!red_in && !blue_in) {
			dfs(next_blue, next_red, depth + 1);

			if (red_first) {
				swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
				swap(l[red.first][red.second], l[next_red.first][next_red.second]);
			}
			else  {
				swap(l[red.first][red.second], l[next_red.first][next_red.second]);
				swap(l[blue.first][blue.second], l[next_blue.first][next_blue.second]);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> l[i];
		if (l[i].find('B') != string::npos) {
			start_blue = { i,l[i].find('B') };
		}
		if (l[i].find('R') != string::npos) {
			start_red = { i,l[i].find('R') };
		}
	}

	dfs(start_blue, start_red, 0);

	if (result == 15) {
		cout << -1;
	}
	else {
		cout << result;
	}

}