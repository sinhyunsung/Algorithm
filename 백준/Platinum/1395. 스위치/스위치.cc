#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int n, m;
int tree[400000] = { 0 };
bool lazy[400000] = { 0 };

void propagation(int node,int start,int end) {
    if (lazy[node]) {
        lazy[node] = !lazy[node];
        tree[node] = (end - start + 1)-tree[node];
        if (start != end) {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2+1] = !lazy[node * 2+1];
        }
    }
}

int query(int node, int v_s, int v_e, int start, int end) {
    propagation(node, start, end);
    if (v_e<start || v_s>end) {
        return 0;
    }
    if (v_s <= start && v_e >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, v_s, v_e, start, mid) + query(node * 2 + 1, v_s, v_e, mid + 1, end);
}

void update(int node, int v_s, int v_e, int start, int end) {
    propagation(node, start, end);
    if (v_e<start || v_s>end) {
        return;
    }
    if (v_s <= start && v_e >= end) {
        tree[node] = (end - start + 1) - tree[node];
        if (start != end) {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, v_s, v_e, start, mid);
    update(node * 2 + 1, v_s, v_e, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) {
            update(1, b, c, 1, n);
            continue;
        }
        cout << query(1, b, c, 1, n) << "\n";
    }

}