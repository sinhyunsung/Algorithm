#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int v;
    cin>>v;
    for(int i=0; i<v; i++){
        cin>>s;
        cout<<s[0]<<s[s.length()-1]<<"\n";
    }
}