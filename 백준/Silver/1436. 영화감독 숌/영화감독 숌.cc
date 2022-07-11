#include<iostream>
#include<algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    int num = 0;

    while (1)
    {
        string strnum = to_string(num);
        int num6_count = 0;
        for (int i = 0; i < strnum.size(); i++)
        {
            if (strnum[i]=='6')
            {
                num6_count += 1;
            }
            else
            {
                num6_count = 0;
            }
            
            if (num6_count == 3)
            {
                n -= 1;
                break;
            }
        }
        if (n == 0)
        {
            cout << num;
            break;
        }
        num += 1;
    }


}
