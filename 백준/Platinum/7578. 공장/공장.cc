#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

ll n;

ll a[500000];
unordered_map<ll, ll> b;

ll tree[2000000]={0};

void update(int node, int target, int start, int end) {
    if (target<start || target>end) {
        return;
    }
    tree[node]++;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, target, start, mid);
        update(node * 2+1, target, mid+1, end);
    }
}

ll query(int node, int sidx, int eidx, int start, int end) {
    if (sidx > end || eidx < start) {
        return 0;
    }
    if (sidx <= start && eidx >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, sidx, eidx, start, mid) + query(node * 2 + 1, sidx, eidx, mid + 1, end);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        b[temp] = i;
    }

    ll result = 0;
    for (int i = 0; i < n; i++) {
        update(1, b[a[i]], 0, n - 1);
        result += query(1, b[a[i]] + 1, n - 1, 0, n - 1);
    }
    cout << result;


   
}