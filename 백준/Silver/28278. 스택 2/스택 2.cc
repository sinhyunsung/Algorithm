#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    deque<int> q;

    for(int i=0; i<n; i++){
        int c,k;
        cin>>c;

        switch (c) {
            case 1:{cin>>k; q.push_front(k); break;}
            case 2: {
                if(q.size()>0){
                    cout<<q.front()<<"\n"; q.pop_front();
                }else{
                    cout<<-1<<"\n";
                }
           break;}
            case 3: {cout<<q.size()<<"\n";break;}
            case 4: {cout<<q.empty()<<"\n";break;}
            case 5: {
                if(q.size()>0){
                    cout<<q.front()<<"\n";
                }else{
                    cout<<-1<<"\n";
                }break;}
        }



    }



    return 0;
}