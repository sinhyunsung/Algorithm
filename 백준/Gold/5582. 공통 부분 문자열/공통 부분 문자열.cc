#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

#define ll long long

string a, b;
int ab[4000][4000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    int result = 0;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (i > 0 && j > 0) {
                if (a[i] == b[j]) {
                    ab[i][j] = ab[i - 1][j - 1] + 1;
                }
                else {
                    ab[i][j] = 0;
                }
            }
            else {
                if (a[i] == b[j]) {
                    ab[i][j] = 1;
                }
                else {
                    ab[i][j] = 0;
                }
            }
            result = max(result, ab[i][j]);
        }
    }
    cout << result;
}