#include <iostream>
#include <vector>

using namespace std;

int n,m;
int v[1000001];

int find(int target){
    if(v[target]!=target){
        v[target]=find(v[target]);
        return v[target];
    }
    return target;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<=n; i++){
        v[i]=i;
    }
    
    int a,b,c;
    for(int i=0; i<m; i++){
        cin >>a>>b>>c;
        if(a==0){
            int t1=find(b);
            int t2=find(c);
            if(t1>t2){
                v[t1]=t2;
            }
            if(t2>t1){
                v[t2]=t1;
            }
            continue;
        }
        int t1=find(b);
        int t2=find(c);
        if(t1==t2){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
        
    }
    
    
}