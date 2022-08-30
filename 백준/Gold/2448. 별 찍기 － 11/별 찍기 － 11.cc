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
#include <unordered_map>

#define ll long long int

using namespace std;

int a[4000][8000];

void t(int x,int y,int scale) {
    
    if (scale == 3) {
        a[y][x] = 1;
        a[y+1][x+1] = 1;
        a[y + 1][x - 1] = 1;
        a[y + 2][x - 2] = 1;
        a[y + 2][x - 1] = 1;
        a[y + 2][x - 0] = 1;
        a[y + 2][x + 1] = 1;
        a[y + 2][x + 2] = 1;
    }
    else 
    {
        t(x , y , scale / 2);

        t(x - scale / 2, y + scale / 2, scale / 2);
        t(x + scale / 2, y + scale / 2, scale / 2);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    t(n - 1, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (a[i][j] == 1) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}
