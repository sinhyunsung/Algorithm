#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main()
{
	int num;
	cin >> num;
	int* data=new int[num];
	for (int i=0; i < num; i++) {
		cin >> data[i];
	}
	int* data2 = new int[num];
	copy(data, data + num, data2);
	sort(data2,data2+num);
	
	unordered_map<int, int> datamap;
	int idx = 0;
	for (int i = 0; i < num; i++) {
		if (datamap.find(data2[i]) == datamap.end()) {
			datamap.insert({ data2[i],idx });
			idx++;
		}
	}


	for (int i = 0; i < num; i++) {
		data[i] = datamap[data[i]];
	}

	for (int i = 0; i < num; i++) {
		cout << data[i] << " ";
	}


}
