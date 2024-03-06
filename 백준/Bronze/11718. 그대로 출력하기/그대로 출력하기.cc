#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    while(1){
        string s;
        getline(cin, s);
        if(s == "") break;
        cout << s << '\n';
    }
}