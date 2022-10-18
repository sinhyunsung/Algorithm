#include <iostream>
#include <string>
#include <set>

using namespace std;


int* kmp(string word) {
	int len = word.size();
	int i = -1;
	int j = 0;
	int* kmp = new int[len+1];

	kmp[j] = i;
	while (j < len) {
		if (i==-1||word[i] == word[j]){
			kmp[++j] = ++i;
		}
		else
		{
			i=kmp[i];

		}
	}
	return kmp;
}

int kmp_find(string word, string search, int* kmp) {

	int len = word.size();
	int len2 = search.size();
	int i = 0;
	int j = 0;
	int sum = 0;
	while (i < len2) {
		if (j==-1||search[i] == word[j]) {
			i++;
			j++;
		}
		else
		{
			j = kmp[j];
			
		}
		if (j == len) {
			sum += 1;
			j = kmp[j];
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int n, m;
	string array;

	cin >> n >> m >> array;

	string word = "I";
	for (int i = 0; i < n; i++) {
		word = word + "OI";
	}

	int* l=kmp(word);
	cout<< kmp_find(word, array, l);
}