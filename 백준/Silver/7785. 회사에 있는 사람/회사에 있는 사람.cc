#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string,int,greater<string>> visit;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s,m;
        cin>>s>>m;
        if(m=="enter"){
            visit[s]=1;
        }
        else{
            visit[s]=0;
        }
    }

    for(auto i:visit){
        if(i.second==1){
            cout<<i.first<<"\n";
        }
    }


    return 0;
}