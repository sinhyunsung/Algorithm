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
    int a[3];
    cin>>a[0]>>a[1]>>a[2];

    for(int j=0; j<2; j++) {
        for (int i = 0; i < 2; i++) {
            if (a[i] > a[i + 1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
            }
        }
    }

    if(a[2]>=a[1]+a[0]){
        cout<<(a[1]+a[0])*2-1;
    }
    else{
        cout<<a[1]+a[2]+a[0];
    }



    return 0;
}