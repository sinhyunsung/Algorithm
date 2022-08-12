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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    int a, b, c;

    int d, e, f;


    int maxdp[3] = { 0 };
    int mindp[3] = { 0 };
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        
        d = max(maxdp[0], maxdp[1])+a;
        e = max({ maxdp[0], maxdp[1], maxdp[2] }) + b;
        f = max(maxdp[1], maxdp[2]) + c;
        maxdp[0] = d;
        maxdp[1] = e;
        maxdp[2] = f;

        d = min(mindp[0], mindp[1]) + a;
        e = min({ mindp[0], mindp[1], mindp[2] }) + b;
        f = min(mindp[1], mindp[2]) + c;
        mindp[0] = d;
        mindp[1] = e;
        mindp[2] = f;



        

    }

    cout << max({ maxdp[0], maxdp[1], maxdp[2] }) << " " << min({ mindp[0], mindp[1], mindp[2] });

}