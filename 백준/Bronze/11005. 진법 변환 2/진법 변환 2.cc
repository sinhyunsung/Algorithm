#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,b;
    cin>>n>>b;

    string s="";

    while(n!=0){
        int now=n%b;
        n=n/b;
        if(now<10){
            s.push_back(char(now+48));
        }
        else{
            s.push_back(char(now+55));
        }
    }
    for(int i=0; i<s.length(); i++){
        cout<<s[s.length()-1-i];
    }

    return 0;
}