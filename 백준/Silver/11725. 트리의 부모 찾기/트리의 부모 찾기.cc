//
//  main.cpp
//  CPWorkSpace
//
//  Created by Rajveer Singh on 21/01/22.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <string>
#include <time.h>
#include <chrono>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cstring>

//MARK:- PRACTICE
using namespace std;

#define len(a) (ll) a.size()
typedef long long ll;
typedef long double ld;

constexpr bool test = true;
constexpr ll mod1 = 1e9 + 7;
constexpr ll mod2 = 998244353;
constexpr ll inf = 1e18 + 5;
constexpr ll lim = 2e5 + 5;

vector<int> node[100001];
int visit[100001] = { 0 };
int parent[100001] = { 0 };


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    deque<pair<int,int>> dfs;
    dfs.push_back(make_pair(0, 1));
    int parents, now;
    while (!dfs.empty()) {
        parents = dfs.back().first;
        now = dfs.back().second;
        dfs.pop_back();
        for (int i = 0; i < node[now].size(); i++) {
            if (visit[node[now][i]] == 0) {
                dfs.push_back(make_pair(now, node[now][i]));
                visit[node[now][i]] = 1;
            }
        }
        if (parents != 0) {
            parent[now] = parents;
        }
        
    }
    for (int i = 2; i < n + 1; i++) {
        cout << parent[i] << "\n";
    }
}