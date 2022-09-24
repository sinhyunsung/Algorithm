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

bool binary_search(vector<int>& arr, int len, int target) {
    int low = 0, high = len - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        //원하는 값을 찾았다면 true 반환
        if (target == arr[mid])	return true;

        // 원하는 값이 더 작다면 검사 범위를 더 낮게 잡아야 한다.
        if (target < arr[mid]) {
            high = mid - 1;
        }
        // 원하는 값이 더 크다면 검사 범위를 더 크게 잡아야 한다.
        else if (target > arr[mid]) {
            low = mid + 1;
        }
    }
    return false; // 마지막까지 못찾는다면 false 반환
}

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


//vector<vector<int>>a(1, vector<int>(1));


int find(vector<int> li, int n) {
    if (li[n] == n) {
        return n;
    }
    else {
        li[n] = find(li, li[n]);
        return li[n];
    }
}



ll* mul(ll* a, ll* b) {
    ll* c=new ll[4];
    c[0] = (a[0] * b[0] + a[1] * b[2])%1000000;
    c[1] = (a[0] * b[1] + a[1] * b[3] )% 1000000;
    c[2] = (a[2] * b[0] + a[3] * b[2] )% 1000000;
    c[3] = (a[2] * b[1] + a[3] * b[3] )% 1000000;
    return c;
}


ll* cal(ll* h,ll* d,ll n) {
    ll* h2 =new ll[4];
    ll* d2 =new ll[4];
    for (int i = 0; i < 4; i++) {
        h2[i] = h[i];
        d2[i] = d[i];
    }


    if (n == 0) {
        return h2;
    }
    else {
        if (n % 2 == 1) {
            h2 = mul(h2, d2);
            n -= 1;
            return cal(h2,d2,n);
        }
        else
        {
            n = n / 2;
            d2 = mul(d2, d2);
            return cal(h2,d2,n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
    ll n;
    cin >> n;

    ll* d;
    ll* h;

    d = new ll[4];
    d[0] = 1;
    d[1] = 1;
    d[2] = 1;
    d[3] = 0;

    h = new ll[4];
    h[0] = 1;
    h[1] = 0;
    h[2] = 0;
    h[3] = 1;


    h = cal(h,d,n);

    cout << h[1];

    




}