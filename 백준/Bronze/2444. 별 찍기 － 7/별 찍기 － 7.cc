#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int v;
    cin>>v;
    for(int i=0; i<v; i++){
        for(int j=i; j<v-1; j++){
            cout<<' ';
        }
        cout<<"*";
        for(int j=0; j<i; j++){
            cout<<"**";
        }
        cout<<"\n";
    }
    for(int i=v-2; i>=0; i--){
        for(int j=i; j<v-1; j++){
            cout<<' ';
        }
        cout<<"*";
        for(int j=0; j<i; j++){
            cout<<"**";
        }
        cout<<"\n";
    }
}