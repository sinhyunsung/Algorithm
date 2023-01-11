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


int n, m;
char sex[1001];

int f[1001];

struct conn {
    int dist;
    int node1;
    int node2;
};

struct compare {
    bool operator()(conn &a,conn &b) {
        if (a.dist != b.dist)
            return a.dist > b.dist;
        return a.node1 > b.node1;
    }
};


int find(int idx) {
    if (idx == f[idx]) {
        return idx;
    }
    else {
        f[idx] = find(f[idx]);
        return f[idx];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> sex[i];
    }

    int u, v, d;
    priority_queue<conn,vector<conn>,compare> edge;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        conn b;
        b.node1 = u;
        b.node2= v;
        b.dist = d;

        edge.push( b);
    }

    for (int i = 0; i < 1001; i++) {
        f[i] = i;
    }

    int min = 0;
    int dist;
    int n1, n2;
    for (int i = 0; i < m; i++) {
        dist = edge.top().dist;
        n1 = edge.top().node1;
        n2 = edge.top().node2;

        edge.pop();
        
        if (find(n1) != find(n2) && sex[n1]!=sex[n2]) {
            if (f[n1] < f[n2]) {
                f[f[n2]] = f[n1];
            }
            else {
                f[f[n1]] = f[n2];
            }
            min += dist;
        }
    }

    bool flag = false;

    for (int i = 1; i <= n; i++) {
        find(i);
        if (f[i] != 1) {
            flag = true;
        }
    }

    if (flag) {
        cout << -1;
    }
    else {
        cout << min;
    }

}