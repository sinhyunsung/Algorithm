#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int n;

    cin>>s>>n;

    int result=0;

    for(int i=0; i<s.length(); i++){
        int now;
        if(int(s[s.length()-1-i])>64){
            now=int(s[s.length()-1-i])-55;
        }
        else{
            now=int(s[s.length()-1-i])-48;
        }
        for(int j=0;j<i; j++){
            now*=n;
        }
        result+=now;
    }

    cout<<result;


    return 0;
}