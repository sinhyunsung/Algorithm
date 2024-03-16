#include <iostream>
#include <algorithm>
#include <map>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n!=-1){
        vector<int> l;
        int sum=0;
        for(int i=1; i<n/2+1; i++){
            if(n%i==0){
                sum+=i;
                l.push_back(i);
            }
        }
        if(sum==n){
            cout<<n<<" = ";
            for(int i=0; i<l.size(); i++){
                cout<<l[i]<<" ";
                if(i!=l.size()-1){
                    cout<<"+ ";
                }
            }
        }
        else{
            cout<<n<<" is NOT perfect.";
        }
        cout<<"\n";
        cin>>n;
    }

    return 0;
}