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

    int x_min=10000,x_max=-10000,y_min=10000,y_max=-10000;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(x<x_min){
            x_min=x;
        }
        if(y<y_min){
            y_min=y;
        }
        if(x>x_max){
            x_max=x;
        }
        if(y>y_max){
            y_max=y;
        }
    }

    cout<<(x_max-x_min)*(y_max-y_min);

    return 0;
}