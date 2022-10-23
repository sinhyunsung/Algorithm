
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

vector<int> q;

void fun(int start, int end) {
    int rightidx=end+1;
 
    if (start > end ) {
        return;
    }

    if (start != end)
    {
        for (int i = start + 1; i <= end; i++) {
            if (q[start] < q[i]) {
                rightidx = i;
                break;
            }
        }
        if (rightidx != start + 1)
        {
            fun(start + 1, rightidx - 1);
        }
        if(rightidx!=end+1){
            fun(rightidx, end);
        }

        
    }

    cout << q[start] << "\n";

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    int n;
    while (!cin.eof()) {
        q.push_back(n);
        cin >> n;
    }
    
    fun(1, q.size() - 1);

}