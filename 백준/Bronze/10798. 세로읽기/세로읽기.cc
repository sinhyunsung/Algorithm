#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s[5];

    for(int i=0; i<5; i++){
        cin>>s[i];
    }

    string result="";

    bool check=true;
    int idx=0;
        for(int i=0; i<15; i++){
            for(int j=0; j<5; j++) {
                if (s[j].length() > i) {
                    result.push_back(s[j][i]);
                }
            }

        }

    cout<<result;




    return 0;
}