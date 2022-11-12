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

    string a, b;

    cin >> a >> b;
    deque<char> c;
    int idx;
    bool check;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
        idx = c.size() - b.size();
        check = false;
        if (idx >= 0) {
            for (int j = 0; j < b.size(); j++) {
                if (c[j + idx] != b[j]) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                for (int j = 0; j < b.size(); j++) {
                    c.pop_back();
                }
            }
        }
    }
    if (c.empty()) {
        cout << "FRULA";
    }
    else {

        for (int j = 0; j < c.size(); j++) {
            cout << c[j];
        }
    }
}
