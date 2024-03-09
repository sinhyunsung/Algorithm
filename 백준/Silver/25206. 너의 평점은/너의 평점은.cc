#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    float cnt=0;
    float avg=0;
    map<string,float> dict;
    dict["A+"]=4.5;
    dict["A0"]=4.0;
    dict["B+"]=3.5;
    dict["B0"]=3.0;
    dict["C+"]=2.5;
    dict["C0"]=2.0;
    dict["D+"]=1.5;
    dict["D0"]=1.0;
    dict["F"]=0;
    dict["P"]=0;

    for(int i=0; i<20; i++){
        string s; float c; string score;
        cin>>s>>c>>score;
        if(score=="P"){
            continue;
        }
        cnt+=c;
        avg+=c*dict[score];
    }

    cout<<avg/cnt;


    return 0;
}