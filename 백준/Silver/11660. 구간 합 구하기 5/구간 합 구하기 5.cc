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


//vector<vector<int>>a(1, vector<int>(1));

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n>>m;

    vector<vector<int>>a(n, vector<int>(n));
    vector<vector<int>>b(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            
            b[i][j] = b[i][j]+ b[i][j-1];
            
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {

            b[j][i] = b[j][i] + b[j-1][i];

        }
    }


    for (int i = 0; i < m; i++) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result;
        
        if (x1 == 1 && y1 == 1) {
            result = b[x2 - 1][y2 - 1];
        }
        else if (x1 == 1 && y1 != 1) {
            result = b[x2 - 1][y2 - 1]-b[x2-1][y1-2];
        }
        else if (x1 != 1 && y1 == 1) {
            result = b[x2 - 1][y2 - 1] - b[x1 - 2][y2 - 1];
        }
        else {
            result = b[x2 - 1][y2 - 1] - b[x1 - 2][y2 - 1] - b[x2 - 1][y1 - 2]+ b[x1 - 2][y1 - 2];

        }
        cout << result << "\n";
    }
    



}