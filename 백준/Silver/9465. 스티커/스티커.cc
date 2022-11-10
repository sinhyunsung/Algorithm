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

int dp1[100000], dp2[100000], num1[100000], num2[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int cs;
    int n;
    cin >> cs;
    for (int i = 0; i < cs; i++) {
        cin >> n;
        for (int k = 0; k < n; k++) {
            cin >> num1[k];
        }
        for (int k = 0; k < n; k++) {
            cin >> num2[k];
        }


        for (int k = 0; k < n; k++) {
            int dp1v = 0;
            int dp2v = 0;
            if (k > 1) {
                if (dp1[k - 1] > dp1[k - 2]) {
                    dp2v = dp1[k - 1] + num2[k];
                }
                else {
                    dp2v = dp1[k - 2] + num2[k];
                }
                if (dp2[k - 1] > dp2[k - 2]) {
                    dp1v = dp2[k - 1] + num1[k];
                }
                else {
                    dp1v = dp2[k - 2] + num1[k];
                }
            }
            else if (k > 0) {

                dp1v += num1[k];
                dp2v += num2[k];
                dp1v += dp2[k - 1];
                dp2v += dp1[k - 1];
            }
            else {
                dp1v += num1[k];
                dp2v += num2[k];

            }
            dp1[k] = dp1v;
            dp2[k] = dp2v;
        }
        if (dp1[n - 1] < dp2[n - 1]) {
            cout << dp2[n - 1] << "\n";
        }
        else {
            cout << dp1[n - 1] << "\n";
        }
    }
    
}