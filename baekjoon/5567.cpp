#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visit(n+1);
    
    int cnt = 0;
    visit[1] = true;
    for(int i=0; i<v[1].size(); i++){
        int nxt = v[1][i];
        if(!visit[nxt]){
            visit[nxt] = true;
            cnt++;
        }
        for(int j=0; j<v[nxt].size(); j++){
            int nxt2 = v[nxt][j];
            if(visit[nxt2]) continue;
            visit[nxt2] = true;
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
