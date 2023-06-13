#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int n,m;
int v[100000];
int tree[400000];

int init(int node, int start, int end) {
    if (start == end) {
        tree[node] = v[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
    return tree[node];
}

void update(int node, int target, int value, int start, int end) {
    if (target<start || target>end) {
        return;
    }
    int mid = (start + end) / 2;
    if (start != end) {
        update(node * 2, target, value, start, mid);
        update(node * 2 + 1, target, value, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
        return;
    }
    tree[node] = value;
}

int query(int node, int v_s, int v_e, int start, int end) {
    if (v_e<start || v_s>end) {
        return 1000000001;
    }
    if (v_s <= start && v_e >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return min(query(node * 2, v_s, v_e, start, mid), query(node * 2 + 1, v_s, v_e, mid + 1, end));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> m;
    init(1, 0, n - 1);

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 2) {
            cout << query(1, b - 1, c - 1, 0, n - 1) << "\n";
        }
        else {
            update(1, b - 1, c, 0, n - 1);
        }
    }

}