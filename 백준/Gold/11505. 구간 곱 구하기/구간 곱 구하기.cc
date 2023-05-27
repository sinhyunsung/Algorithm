#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#define ll long long

ll v[1000000];
ll n, m, k;

ll tree[4000000];

ll mod = 1000000007;

ll init(ll idx,  ll start, ll end) {
    if (start == end) {
        tree[idx] = v[start];
        return tree[idx];
    }
    ll mid = (start + end) / 2;
    tree[idx] = init(idx * 2, start, mid) * init(idx * 2 + 1, mid + 1, end) % mod;
    return tree[idx];
}

ll update(ll idx,ll c_idx, ll c_v, ll start, ll end) {
    if (start > c_idx || end < c_idx) {
        return tree[idx];
    }
    if (start == end) {
        if (start == c_idx) {
            tree[idx] = c_v;
        }
        return tree[idx];
    }
    ll mid = (start + end) / 2;
    tree[idx] = update(idx * 2, c_idx, c_v, start, mid) * update(idx * 2 + 1, c_idx, c_v, mid + 1, end) % mod;
    return tree[idx];
}

ll query(ll idx, ll s_v, ll s_e, ll start, ll end) {
    if (s_v <= start && s_e >= end) {
        return tree[idx];
    }
    if (s_v > end || s_e < start) {
        return 1;
    }
    ll mid = (start + end) / 2;
    return query(idx * 2, s_v, s_e, start, mid) * query(idx * 2 + 1, s_v, s_e, mid + 1, end) % mod;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    init(1, 0, n - 1);

    int a, b, c;

    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;


        if (a == 1) {
            update(1, b - 1, c, 0, n - 1);
        }
        else {

           cout<< query(1, b - 1, c-1, 0, n - 1)<<"\n";
        }
    }
    
   
}