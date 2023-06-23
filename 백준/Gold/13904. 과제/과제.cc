#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

#define ll long long

int n;
vector<pair<int, int>> d;

int link[1001];
int result = 0;

int search(int x) {
    if (link[x] == x) {
        return x;
    }
    else {
        link[x] = search(link[x]);
        return link[x];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int a, b;

    for (int i = 0; i <= 1001; i++) {
        link[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        d.push_back(make_pair(b, a));
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < n; i++)
    {
        a = d.back().second;
        b = d.back().first;
        d.pop_back();

        int s = search(a);
        if (s == 0) {
            continue;
        }
        result+= b;
        link[s] = s - 1;
    }
    cout << result;


}