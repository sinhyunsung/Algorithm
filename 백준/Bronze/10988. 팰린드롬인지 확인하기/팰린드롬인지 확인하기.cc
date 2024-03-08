#include <iostream>
#include <algorithm>

using namespace std;

bool check(string v){
    bool result=true;
    for(int i=0; i<v.length()/2; i++){
        if(v[i]!=v[v.length()-1-i]){
            result=false;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    cout<<check(s);
}