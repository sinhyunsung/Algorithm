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

vector<pair<int, int>> edges[501];
ll nodes[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int node_count, edge_count, edge_count2;
		cin >> node_count >> edge_count >> edge_count2;
		for (int j = 0; j < node_count; j++) {
			nodes[j + 1] = 100000000;
		}
		for (int j = 0; j < edge_count; j++) {
			int start, finish, value;
			cin >> start >> finish >> value;
			edges[start].push_back(make_pair(finish, value));
			edges[finish].push_back(make_pair(start, value));
		}
		for (int j = 0; j < edge_count2; j++) {
			int start, finish, value;
			cin >> start >> finish >> value;
			edges[start].push_back(make_pair(finish, -value));
		}

		nodes[1] = 0;

		for (int node_num = 1; node_num <= node_count; node_num++) {
			for (int edge_num = 1; edge_num <= node_count; edge_num++) {
				for (auto edge : edges[edge_num]) {
					if (edge.second + nodes[edge_num] < nodes[edge.first]) {
						nodes[edge.first] = edge.second + nodes[edge_num];
					}
				}
			}
		}
		bool no = 1;
		for (int edge_num = 1; edge_num <= node_count; edge_num++) {
			for (auto edge : edges[edge_num]) {
				if (edge.second + nodes[edge_num] < nodes[edge.first]) {
					nodes[edge.first] = edge.second + nodes[edge_num];
					
						no = 0;
				}
			}
		}

		if (no) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
		
		for (int j = 0; j < node_count; j++) {
			edges[j + 1].clear();
		}

	}

}
