#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int n, m;
int tree[800000]={0};
int idx[100000];

void update(int node, int target, int value, int start, int end) {
    if (target<start || target>end) {
        return;
    }
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, target, value, start, mid);
        update(node * 2+1, target, value, mid+1, end);
    }
    if (start == end) {
        tree[node] = value;
        return;
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int v_s, int v_e, int start, int end) {
    if (v_e<start || v_s>end) {
        return 0;
    }
    if (v_s <= start && v_e >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, v_s, v_e, start, mid)+ query(node * 2+1, v_s, v_e, mid+1, end);
}

void solve() {
    cin >> n >> m;
    fill_n(tree, 800000, 0);
    for (int i = 0; i < n; i++) {
        update(1, i + m, 1, 0, n + m - 1);
        idx[i] = i + m;
    }
    int temp;



    for (int i = 0; i < m; i++) {
        cin >> temp;
        temp -= 1;
        cout<<query(1, 0, idx[temp]-1, 0, n + m - 1)<<" ";
        update(1, idx[temp], 0, 0, n + m - 1);
        update(1, m - 1 - i, 1, 0, n + m - 1);
        idx[temp] = m - 1 - i;
    }
    cout << "\n";
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