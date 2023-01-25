#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n, m;
int a[50][50];


vector<pair<int, int>> chicken;
bool* chicken_visit;
vector<int> chicken_search;

vector<pair<int, int>> house;

vector<int>* dist;

int minv = 10000000;



void search(int depth,int start) {
	if (depth == m) {
		int result = 0;


		for (int j = 0; j < house.size(); j++) {
			int mindist = 10000000;

			for (int i = 0; i < chicken_search.size(); i++) {
				if (dist[chicken_search[i]][j] < mindist) {
					mindist = dist[chicken_search[i]][j];
				}
			}
			result += mindist;
			if (result > minv) {
				break;
			}
		}
		
		if (result < minv) {
			minv = result;
		}
	}
	else {
		for (int i = start; i < chicken.size(); i++) {
				chicken_search.push_back(i);
				search(depth + 1,i+1);
				chicken_search.pop_back();
		}
		
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	chicken_visit = new bool[chicken.size()];
	dist= new vector<int>[chicken.size()];
	fill_n(chicken_visit, chicken.size(), 0);

	for (int i = 0; i < chicken.size(); i++) {
		for (int j = 0; j < house.size(); j++) {
			dist[i].push_back(abs(chicken[i].first - house[j].first) + abs(chicken[i].second - house[j].second));
		}
	}


	search(0,0);

	cout << minv;
	
	

	
}