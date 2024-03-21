#include <iostream>
#include <algorithm>
#include <map>
#include <vector>


using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b+c==0){
            break;
        }
        if (a+b<=c | a+c<=b | b+c<=a) {
            cout << "Invalid";
        } else {
            if (a==b & b==c) {
                cout << "Equilateral";
            } else if (a==b | b==c | c==a) {
                cout << "Isosceles";
            } else {
                cout << "Scalene";
            }
        }
        cout<<"\n";
    }

    return 0;
}