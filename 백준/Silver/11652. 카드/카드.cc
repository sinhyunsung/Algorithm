#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;


bool cmp(const pair<ll,ll>& a, const pair<ll,ll>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<ll,ll> m;
    ll n;
    cin>>n;
    ll k;
    for(int i=0; i<n; i++){
        cin>>k;
        m[k]++;
    }
    vector<pair<ll,ll>> vec( m.begin(), m.end() );
    sort(vec.begin(), vec.end(), cmp);

    cout<<vec[0].first;

    return 0;
}