#include<iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

#define ll long long

int n;
string s;

int check(int left, int right,int type) {
        while (left < right) {
            if (s[left] == s[right]) {
                left++; right--;
                continue;
            }
            if (type == 0) {
                return min(check(left+1, right, type+1), check(left, right-1, type+1));
            }
            else {
                type++;
                return 2;
            }
        }
        return type;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cout << check(0, s.size() - 1, 0) << "\n";
    }

}