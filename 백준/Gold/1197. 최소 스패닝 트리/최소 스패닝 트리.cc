#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,pair<int, int>>> heap;

void heapify(int idx) {
	int left = idx * 2;
	int right = idx * 2 + 1;
	int target = idx;

	if (left < heap.size() && heap[left].first <heap[target].first) {
		target = left;
	}
	if (right < heap.size() && heap[right].first < heap[target].first) {
		target = right;
	}
	if (idx != target) {
		swap(heap[idx], heap[target]);
		heapify(target);
	}
}

void heap_in(pair<int, pair<int, int>> a) {
	heap.push_back(a);
	int idx = heap.size() - 1;
	while (idx / 2 > 0 && heap[idx].first < heap[idx / 2].first) {
		swap(heap[idx], heap[idx / 2]);
		idx = idx / 2;
	}
}

void heap_pop() {
	swap(heap[1], heap.back());
	heap.pop_back();
	heapify(1);
}

int* node;

int find(int n) {
	if (node[n] == n) {
		return n;
	}

	node[n] = find(node[n]);
	return node[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	heap.push_back({ -1,{-1,-1} });

	int n, m;
	cin >> n >> m;
	node = new int[n+1];
	for (int i = 0; i < n + 1; i++) {
		node[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		heap_in(make_pair(c, make_pair(a, b)));
	}

	int result = 0;

	while (heap.size() != 1) {
		a = heap[1].second.first;
		b = heap[1].second.second;
		c = heap[1].first;
		
		a = find(a);
		b = find(b);
		if (a == b) {
			heap_pop();
			continue;
		}
		if (a < b) {
			node[b] = a;
			heap_pop();
			result += c;
			continue;
		}
		node[a] = b;
		heap_pop();
		result += c;
		continue;
	}


	cout << result;




}