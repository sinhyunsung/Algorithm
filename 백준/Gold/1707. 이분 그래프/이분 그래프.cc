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

vector<int> edge[20001];


int find(vector<int> li, int n) {
    if (li[n] == n) {
        return n;
    }
    else {
        li[n] = find(li, li[n]);
        return li[n];
    }
}

void solve() {


    int n, m;
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }


    deque<pair<int, int>> que;

    vector<int> check(n + 1);

    bool flag = false;
    int now, t;

    for (int i = 1; i < n + 1; i++) {
        if (check[i] == 0) {
            que.push_back(make_pair(i, 1));

            while (!que.empty()) {
                now = que.back().first;
                t = que.back().second;
                que.pop_back();
                if (check[now] == 0) {
                    check[now] = t;
                    for (int i = 0; i < edge[now].size(); i++) {
                        que.push_back(make_pair(edge[now][i], -t));
                    }
                }
                else {
                    if (check[now] != t) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
    }
    if (flag) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }

    for (int i = 1; i < n+1; i++) {
        edge[i].clear();
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cs;
    cin >> cs;
    for (int i = 0; i < cs; i++) {
        solve();
    }




}