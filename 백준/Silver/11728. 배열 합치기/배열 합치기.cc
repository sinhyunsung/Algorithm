#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int l[2000000];
    for(int i=0; i<n+m; i++){
        cin>>l[i];
    }
    sort(l,l+n+m);

    for(int i=0; i<n+m; i++){
        cout<<l[i]<<" ";
    }
    return 0;
}