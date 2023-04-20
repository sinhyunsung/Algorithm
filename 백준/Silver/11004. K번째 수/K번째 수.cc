#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    int* v=new int[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v,v+n);
    cout<<v[m-1];
}