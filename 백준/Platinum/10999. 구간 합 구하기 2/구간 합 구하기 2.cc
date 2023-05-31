#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

ll n, m, k;
ll v[1000000];
ll tree[4000000];
ll lazy[4000000]={0};

ll init(ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = v[start];
        return tree[node];
    }
    ll mid = (start + end) / 2;
    tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
    return tree[node];
}

void update_lazy(ll x, ll s, ll e) {
    if (lazy[x] != 0) {
        tree[x] += (e - s + 1) * lazy[x];
        if (s != e) {
            lazy[x * 2] += lazy[x];
            lazy[x * 2+1] += lazy[x];
        }
        lazy[x] = 0;
    }
}

ll query(ll node, ll s_v, ll e_v, ll start, ll end) {
    update_lazy(node, start, end);
    if (s_v > end || e_v < start) {
        return 0;
    }
    if (s_v <= start && e_v >= end) {
        return tree[node];
    }
    ll mid = (start + end) / 2;
    return query(node * 2, s_v, e_v, start, mid) + query(node * 2 + 1, s_v, e_v, mid + 1, end);
}

void update(ll node, ll value , ll s_v, ll e_v, ll start, ll end) {
    update_lazy(node, start, end);
    if (s_v > end || e_v < start) {
        return;
    }
    if (s_v <= start && e_v >= end) {
        tree[node] += (end - start + 1) * value;
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2+1] += value;
        }
        return;
    }

    ll mid = (start + end) / 2;
    update(node * 2, value, s_v, e_v, start, mid);
    update(node * 2 + 1, value, s_v, e_v, mid + 1, end);
    
    tree[node] = tree[node << 1] + tree[(node << 1) + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ll a, b, c, d;

    init(1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;

        if (a == 1) {
            cin >> d;
            update(1, d, b-1, c-1, 0, n - 1);
            continue;
        }
        cout << query(1, b-1, c-1, 0, n - 1) << "\n";
    }
}