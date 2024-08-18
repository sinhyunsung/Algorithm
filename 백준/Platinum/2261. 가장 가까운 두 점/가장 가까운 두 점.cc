#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdio>
#include <cmath>
using namespace std;
#define ll long long

struct dot{
    int x;
    int y;
};

vector<dot> dots;

int dist(dot a,dot b){
    return int(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

bool cmpx(dot& a,dot& b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
bool cmpy(dot& a,dot& b){
    return a.y<b.y;
}

int dd(int l,int r){
    int n=r-l+1;
    if(n==2)return dist(dots[l],dots[r]);
    if(n==3)return min({dist(dots[l],dots[l+1]),dist(dots[l+1],dots[r]),dist(dots[r],dots[l])});
    int mid=(r+l)/2;
    int result=min(dd(l,mid),dd(mid+1,r));

    vector<dot> search;
    search.reserve(n);
    int target=(dots[mid].x+dots[mid+1].x)/2;

    for (int i = l; i <= r; i++) {
        if (pow((target - dots[i].x),2) < result) {
            search.push_back(dots[i]);
        }
    }

    sort(search.begin(),search.end(),cmpy);

    for(int i=0; i<search.size();i++){
        for (int j = i + 1; j < search.size(); j++) {
            if (pow(search[i].y - search[j].y,2) > result) break;
            else result = min(result, dist(search[i], search[j]));
        }
    }
    return result;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        dots.push_back(dot(x,y));
    }
    sort(dots.begin(),dots.end(),cmpx);
    cout<<dd(0,dots.size()-1);
}
