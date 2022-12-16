#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

#define ll long long int

using namespace std;

bool binary_search(vector<int>& arr, int len, int target) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        //원하는 값을 찾았다면 true 반환
        if (target == arr[mid])	return true;

        // 원하는 값이 더 작다면 검사 범위를 더 낮게 잡아야 한다.
        if (target < arr[mid]) {
            high = mid - 1;
        }
        // 원하는 값이 더 크다면 검사 범위를 더 크게 잡아야 한다.
        else if (target > arr[mid]) {
            low = mid + 1;
        }
    }
    return false; // 마지막까지 못찾는다면 false 반환
}

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}





int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n,m;
    int d[101][101];
    for (int i = 0; i < 101; i++) {
        fill_n(d[i], 101, 100000000);
    }

    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (d[a][b] > c) {
            d[a][b] = c;
        }
    }

    for (int i = 1; i < n + 1; i++) {

        for (int j = 1; j < n + 1; j++) {

            for (int k = 1; k < n + 1; k++) {
                if (d[j][k] > d[j][i] + d[i][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (i == j) {
                cout << 0 << " ";
            }
            else if (d[i][j] == 100000000) {
                cout << 0 << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout <<"\n";

    }

}