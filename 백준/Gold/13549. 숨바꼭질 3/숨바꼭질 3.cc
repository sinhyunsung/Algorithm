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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;

    deque<pair<int, int>> bfs;

    int visit[100001] = {0};

    cin >> a >> b;

    int now, time;

    bfs.push_back(make_pair(a, 0));
    while (!bfs.empty()) {
        now = bfs.front().first;
        time= bfs.front().second;
        bfs.pop_front();
        if (now == b) {
            cout << time;
            break;
        }
        if (now * 2 < 100001 && visit[now * 2] == 0) {
            bfs.push_front(make_pair(now * 2, time));
            visit[now * 2] = 1;
        }
        if (now + 1 < 100001 && visit[now + 1] == 0) {
            bfs.push_back(make_pair(now + 1, time + 1));
            visit[now + 1] = 1;
        }
        if (now - 1 >= 0 && visit[now - 1] == 0) {
            bfs.push_back(make_pair(now - 1, time + 1));
            visit[now - 1] = 1;
        }


    }


}