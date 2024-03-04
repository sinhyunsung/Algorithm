#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int& a,int& b){
    int tmp=a;
    a=b;
    b=tmp;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> l;
    for(int i=1; i<=n; i++){
        l.push_back(i);
    }
    for(int i=0; i<m; i++){
        int idx1,idx2;
        cin>>idx1>>idx2;
        swap(l[idx1-1],l[idx2-1]);
    }

    for(int i=0; i<n; i++){
        cout<<l[i]<<" ";
    }
    return 0;
}
