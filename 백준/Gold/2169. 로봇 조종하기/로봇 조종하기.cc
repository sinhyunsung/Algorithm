#include <iostream>
#include <complex>
#include <deque>

using namespace std;

int n,m;
int map[1001][1001];
int val[1001][1001][3];

int dp(int x,int y,int direction) {
    if(x<=0 | y<=0 | x>m | y>n){return -99999999;}
    if (x == m & y == n)return map[n][m];
    if (val[y][x][direction] != -1) { return val[y][x][direction]; }
    if (direction == 0) { val[y][x][direction] = map[y][x]+max({dp(x + 1, y, 1), dp(x - 1, y, 2), dp(x, y + 1, 0)}); }
    if (direction == 1) { val[y][x][direction] = map[y][x]+max(dp(x + 1, y, 1), dp(x, y + 1, 0));}
    if (direction == 2) { val[y][x][direction]= map[y][x]+max(dp(x - 1, y, 2), dp(x, y + 1, 0));}
    return val[y][x][direction];
}

int main()
{
    cin>>n>>m;

    fill(&val[0][0][0],&val[1000][1000][2],-1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }

    cout<<dp(1,1,0);


}