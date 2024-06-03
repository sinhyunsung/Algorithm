#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdio>

using namespace std;

#define ll long long

int n;
pair<int,int> arr[500001];
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


bool cmp(pair<int,int> &a, pair<int,int> &b){
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr+1, arr+n+1);
    for(int i = 1; i <= n; i++){
        arr[i].first = i;
    }
    sort(arr+1, arr+n+1, cmp);

    for (int i = 1; i <= n; i++) {
        update(1, arr[i].first, 1, n );
        cout << (i+1)-query(1, arr[i].first, 1, n ) << "\n";
    }


    return 0;
}
