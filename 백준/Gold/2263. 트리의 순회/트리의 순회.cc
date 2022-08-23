#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

#define ll long long int

using namespace std;

int tree[100001];
int tree2[100001];
int index[100001];


void getpre(int instart, int inend, int poststart, int postend) {
    if (instart > inend || poststart > postend) {
        return;
    }

    cout << tree2[postend] << " ";
    int rootidx = index[tree2[postend]];
        int leftsize = rootidx - instart;
        int rightsize = inend-rootidx;
        getpre(instart, instart + leftsize,poststart,poststart+leftsize-1);
        getpre(rootidx+1, inend, poststart+leftsize, postend-1);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    int n;
    cin >> n;
 

    for (int i = 1; i < n+1; i++) {
        cin >> tree[i];
    }

    for (int i = 1; i < n+1; i++) {
        cin >> tree2[i];
    }


    for (int i = 1; i < n + 1; i++) {
        index[tree[i]] = i;
    }

    getpre(1, n ,1,n);
    
}