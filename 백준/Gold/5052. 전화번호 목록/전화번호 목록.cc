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
string s[10000];

struct tree {
    char value;
    tree* next[10]={0};
};


void solve() {
    cin >> n;

    tree* root = new tree;

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        tree* target = root;
        for (int j = 0; j < s[i].size(); j++) {
            if (target->next[s[i][j] - '0'] != 0) {
                target = target->next[s[i][j] - '0'];
            }
            else {
                tree* nextnode = new tree;
                nextnode->value = s[i][j];
                target->next[s[i][j] - '0'] = nextnode;
                target = nextnode;
            }
        }
    }
    bool flag = false;

    for (int i = 0; i < n; i++) {
        tree* target = root;
        for (int j = 0; j < s[i].size(); j++) {
            target = target->next[s[i][j]-'0'];
        }
        for (int j = 0; j < 10; j++) {
            if (target->next[j] != 0) {
                flag = true;
            }
        }
    }
    if (flag) {
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cs;
    cin >> cs;
    while (cs--) {
        solve();
    }
}