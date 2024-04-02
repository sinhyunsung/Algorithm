#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int now=0;
    int v=0;
    int result=0;


    for(int i=1; i<=n; i++){
        v+=i;
        while(v>n){
            v-=now;
            now++;
        }
        if(v<n)continue;
        if(v==n)result++;
    }
    cout<<result;
    return 0;
}