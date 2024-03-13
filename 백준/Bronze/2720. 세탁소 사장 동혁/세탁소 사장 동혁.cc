#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,c;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>c;
        cout<<c/25<<" ";
        c=c%25;
        cout<<c/10<<" ";
        c=c%10;
        cout<<c/5<<" ";
        c=c%5;
        cout<<c/1<<"\n";
        c=c%1;
    }

    return 0;
}