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

deque<int> q;

void sol(int* c,int* visit,int n, int depth, int max) {
    if (max < depth) {
        for (int i = 0; i < max; i++) {
            cout << q[i] << " ";
        }
        cout << "\n";
        return;
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                q.push_back(c[i]);
                visit[i] = 1;
                sol(c, visit, n, depth+1, max);
                q.pop_back();
                visit[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;

    int* c = new int[a];
    int* visit = new int[a];

    for (int i = 0; i < a; i++) {
        cin >> c[i];
        visit[i] = 0;
    }

    sort(c, c + a);
    
    sol(c, visit, a, 1, b);


}