#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int dx1, dx2, dx3, dy1, dy2, dy3;
	cin >> dx1 >> dy1 >> dx2 >> dy2 >> dx3 >> dy3;

	if (ccw(dx1, dy1, dx2, dy2, dx3, dy3) > 0) {
		cout << 1;
	}
	else if (ccw(dx1, dy1, dx2, dy2, dx3, dy3) < 0)
	{
		cout << -1;
	}
	else {
		cout << 0;
	}

}