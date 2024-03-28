#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
using namespace std;

long long fact(long long n){
    if(n==0)return 1;
    return fact(n-1)*n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    cout<<fact(n);

    return 0;
}