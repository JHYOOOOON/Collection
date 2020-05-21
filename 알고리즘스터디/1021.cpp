#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, m, tmp, idx, ans=0;
    deque<int> dq;
    cin >> n >> m;

    for(int i=1; i<=n; i++) dq.push_back(i);

    while(m--){
        cin >> tmp;
        for(int i=0; i<dq.size(); i++)
            if(dq[i] == tmp){
                idx = i;
                break;
            }

        if(idx < dq.size() - idx){
            while(dq.front() != tmp){
                ans++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        } else{
            while(dq.front() != tmp){
                ans++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }

    cout << ans << "\n";

    return 0;
}
