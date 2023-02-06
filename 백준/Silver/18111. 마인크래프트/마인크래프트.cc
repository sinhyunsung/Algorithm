#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <numeric>

using namespace std;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y, x, b;
	cin >> y >> x >> b;
	int* m =new int[y * x];
	for (int i = 0; i < x * y; i++) {
		cin >> m[i];
	}
	int start, end;
	start = *min_element(m,m+(x*y));
	end = 0;
	for (int i = 0; i < x * y; i++) {
		end += m[i];
	}
	end += b;
	end =end/ (x * y);

	int result_time = 100000000;
	int result = 0;

	for (int i = start; i < end + 1; i++)
	{
		int time = 0;
		int nb = b;
		for (int j = 0; j < x * y; j++) {
			if (m[j] < i) {
				nb =nb - (i - m[j]);
				time = time+ (i - m[j]);
			}
			if (m[j] > i) {
				nb =nb+  m[j]-i;
				time = time + (m[j]-i)*2;
			}
		
		}
		if (nb < 0) {
			continue;
		}

		if (result_time >= time) {
			result_time = time;
			result = i;
		}
	}

	cout << result_time << " " << result;
}