
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>
#include <list>
#include <string>
#include <time.h>
#include <chrono>
#include <array>
#include <random>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>
#include <unordered_map>
#include <numeric>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll* a = new ll[n];
    ll* b = new ll[n];

    unordered_map<ll,ll> hm;

    ll result = 0;


    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0)
        {
            b[i] = a[i];
        }
        else {
            b[i] = b[i - 1] + a[i];
        }
        b[i] %= m;
        if (b[i] == 0) {
            result++;
        }
        if (hm.find(b[i]) == hm.end()) {
            hm.insert(make_pair(b[i], 1));
        }
        else {
            hm.find(b[i])->second += 1;
        }
    }

    for (auto& pair : hm) {
        result += (pair.second) * (pair.second - 1) / 2;
    }

    cout << result;

}