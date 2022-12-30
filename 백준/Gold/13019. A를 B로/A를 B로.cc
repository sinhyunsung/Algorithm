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

    int cnt = 0;

    unordered_map<char, int> hsm1;
    unordered_map<char, int> hsm2;

    for (int i = 0; i < a.size(); i++) {
        if (hsm1.find(a[i]) != hsm1.end()) {
            hsm1.find(a[i])->second += 1;
        }
        else {
            hsm1.insert(make_pair(a[i], 1));
        }
        if (hsm2.find(b[i]) != hsm2.end()) {
            hsm2.find(b[i])->second += 1;
        }
        else {
            hsm2.insert(make_pair(b[i], 1));
        }
    }

    bool flag = true;
    for (auto v : hsm1) {
        if (hsm2.find(v.first) != hsm2.end()) {
            if (v.second != hsm2.find(v.first)->second) {
                flag = false;
            }
        }
        else {
            flag = false;
        }
    }
    

    if (flag) {

        int b_now = b.size() - 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == b[b_now]) {
                b_now -= 1;
                cnt += 1;
            }
        }

        cout << a.size() - cnt;

    }
    else {
        cout << -1;
    }

}