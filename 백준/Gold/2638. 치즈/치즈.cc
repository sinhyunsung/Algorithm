
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

using namespace std;

typedef long long ll;
typedef long double ld;


int a[100][100];
bool visit[100][100];


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    deque<pair<int, int>> air,cheese;
    int x, y,dx,dy;
    int ddx[4] = { 0,0,1,-1 };
    int ddy[4] = { 1,-1,0,0 };
    int time = 0;
    
    air.push_back(make_pair(0, 0));
    air.push_back(make_pair(m-1, 0));
    air.push_back(make_pair(0, n-1));
    air.push_back(make_pair(m-1, n-1));

    for (int i = 0; i < 100; i++) {
        fill_n(visit[i], 100, false);
    }

    while (!air.empty() || !cheese.empty())
    {
        while (!air.empty()) {
            x = air.front().first;
            y = air.front().second;
            air.pop_front();

            if (a[y][x] == 0) {
                visit[y][x] = 1;
                a[y][x] = -1;
            }
            for (int i = 0; i < 4; i++) {
                dx = x + ddx[i];
                dy = y + ddy[i];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    if (!visit[dy][dx]) {
                        if (a[dy][dx] == 0) {
                            visit[dy][dx] = 1;
                            a[dy][dx] = -1;
                            air.push_back(make_pair(dx, dy));
                        }
                        else if (a[dy][dx] == 1) {
                            visit[dy][dx] = 1;
                            cheese.push_back(make_pair(dx, dy));
                        }
                    }
                }
            }
        }


        int check;
        int check2;

        check2 = 0;
        while (!cheese.empty()) {
            x = cheese.front().first;
            y = cheese.front().second;
            cheese.pop_front();

            check = 0;
            for (int i = 0; i < 4; i++) {
                dx = x + ddx[i];
                dy = y + ddy[i];
                if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
                    if (a[dy][dx] == -1) {
                        check++;
                    }
                }
            }
            if (check > 1) {
                a[y][x] = 0;
                air.push_back(make_pair(x, y));
                if (check2 == 0) {
                    check2 = 1;
                    time++;
                }
            }
            else {
                visit[y][x] = false;
            }
        }
    }

    cout << time;




}