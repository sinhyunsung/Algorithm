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
   
    int n[28];

    for (int i = 0; i < 28; i++) {
        cin >> n[i];
    }
    sort(n, n + 28);

    int p = 1;
    for (auto v : n) {
        if (p != v) {
            cout << v-1 << endl;
            p = v+1;
        }
        else {
            p = v + 1;
        }
    }

    if (p == 30) {
        cout << 30;
    }
    
}