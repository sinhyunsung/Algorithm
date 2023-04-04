#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

struct human {
	string name;
	int kor;
	int eng;
	int math;
};

bool cmp(human a, human b) {
	if (a.kor < b.kor) {
		return false;
	}
	else if (a.kor > b.kor) {
		return true;
	}
	if (a.eng > b.eng) {
		return false;
	}
	else if(a.eng < b.eng) {
		return true;
	}
	if (a.math < b.math) {
		return false;
	}
	else if(a.math > b.math) {
		return true;
	}
	return a.name < b.name;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	human l[100000];
	int n;
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> l[i].name >> l[i].kor >> l[i].eng >> l[i].math;
	}

	sort(l, l+n, cmp);

	for (int i = 0; i < n; i++) {
		cout << l[i].name << "\n";
	}

}