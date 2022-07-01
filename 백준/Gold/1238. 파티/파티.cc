#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <deque>
#include <vector>
#include <queue>

#define ll long long

using namespace std;


int m, n, x;

vector<pair<int, int>> info[1001];

priority_queue<pair<int, int>> q;
void dijkstra(int*d,int target);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	cin >> m >> n >> x;
	int a,b,distance;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> distance;
		info[a].push_back({ b,distance });
	}

	int** dl = new int* [m+1];
	for (int i = 0; i < m + 1; i++) {
		dl[i] = new int[m + 1];
		fill_n(dl[i], m + 1, 10000000);
		dijkstra(dl[i],i);
	}

	int max = 0;
	for (int i = 1; i < m + 1; i++) {
		if (i == x) {
			continue;
		}
		if (dl[x][i] + dl[i][x] > max) {
			max = dl[x][i] + dl[i][x];
		}
	}
	cout << max;


}

void dijkstra(int* d,int target) {
	int idx, distance,nextidx,nextdistance;
	q.push({ target,0 });
	d[target] = 0;

	while (!q.empty())
	{
		idx = q.top().first;
		distance = -q.top().second;
		q.pop();
		if (d[idx] < distance) {
			continue;
		}
		for (int i = 0; i < info[idx].size(); i++) {
			nextidx = info[idx][i].first;
			nextdistance = info[idx][i].second;
			if (distance + nextdistance < d[nextidx]) {
				d[nextidx] = distance + nextdistance;
				q.push({ nextidx,-d[nextidx] });
			}

		}

	}
}