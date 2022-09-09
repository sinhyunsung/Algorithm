#include <iostream>
#include <deque>
#include <vector>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
    
    int max,i,j;
    max=0;
    int n,ni,nj;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
              cin>>n;
            if(n>=max){
                max=n;
                ni=i;
                nj=j;
            }
        }
    
    }
    
    cout<< max << "\n" << ni+1<< " " << nj+1;

}