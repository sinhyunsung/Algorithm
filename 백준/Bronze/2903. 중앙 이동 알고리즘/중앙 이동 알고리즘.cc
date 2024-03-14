#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int sum=2;

    for(int i=0; i<n; i++){
        sum=sum+sum-1;
    }
    cout<<sum*sum;

    return 0;
}