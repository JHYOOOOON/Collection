#include <bits/stdc++.h>
using namespace std;

int n, m, mx = 0;
vector<int> v[101];

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
    vector<int> visit(n+1);

    queue<int> q;
    visit[1] = true;
    int cnt = 0;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i=0; i<v[cur].size(); i++){
            int nxt = v[cur][i];
            if(visit[nxt]) continue;
            visit[nxt] = true;
            q.push(nxt);
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
