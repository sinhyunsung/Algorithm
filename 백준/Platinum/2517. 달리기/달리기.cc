#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int n;
int v[500000];
int v_sort[500000];
unordered_map<int, int> idx;
int tree[2000000] = { 0 };

void update(int node,int target, int start, int end) {
    if (target <start || target> end) {
        return;
    }
    int mid = (start + end) / 2;
    tree[node]++;
    if (start != end) {
        update(node * 2, target, start, mid);
        update(node * 2+1, target, mid+1, end);
    }
}

int query(int node, int target, int start, int end) {
    if (target < start) {
        return 0;
    }
    if (0 <= start && target >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, target, start, mid) + query(node * 2 + 1, target, mid + 1, end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v_sort[i] = v[i];
    }
    sort(v_sort, v_sort+n);
    for (int i = 0; i < n; i++) {
        idx[v_sort[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        update(1, idx[v[i]], 0, n - 1);
        cout << (i+2)-query(1, idx[v[i]], 0, n - 1) << "\n";
    }


}