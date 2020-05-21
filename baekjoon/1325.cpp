#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return (a.first == b.first) ? a.second < b.second : a.first > b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<int> v[10001];
    vector<pair<int, int>> num;

    while(m--){
        cin >> a >> b;
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        int cnt = 0;
        bool visited[10001] = {false};
        queue<int> q;

        visited[i] = 1;
        q.push(i);

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int j=0; j<v[cur].size(); j++){
                int tmp = v[cur][j];
                if(!visited[tmp]){
                    visited[tmp] = 1;
                    q.push(tmp);
                    cnt++;
                }
            }
        }
        num.push_back({cnt, i});
    }

    sort(num.begin(), num.end(), compare);
    cout << num[0].second;
    for(int i=1; i<num.size(); i++)
        if(num[i].first == num[0].first)
            cout << ' ' << num[i].second;
        else break;

    return 0;
}
