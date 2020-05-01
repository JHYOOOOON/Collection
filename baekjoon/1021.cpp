#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, tmp, idx, cnt = 0;
    deque<int> dq;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    while (m--){
        cin >> tmp;
        
        // 현재 dq에서 뽑아내려고 하는 수의 위치 찾기
        for(int i=0; i<dq.size(); i++)
            if(tmp == dq[i]){
                idx = i;
                break;
            }

        // dq의 뒤에서보다 앞에서 더 가깝다면
        if (idx < dq.size() - idx){
            while (dq.front() != tmp){
                cnt++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else{
            while (dq.front() != tmp){
                cnt++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
    }
    cout << cnt << "\n";

    return 0;
}
