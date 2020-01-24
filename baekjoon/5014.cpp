#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;

int main(){
    cin >> f >> s >> g >> u >> d;
    vector<int> building(f+1);
    vector<bool> visited(f+1);
    fill(building.begin(), building.end(), -1);
    fill(visited.begin(), visited.end(), false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    building[s] = 0;

    while(!q.empty()){
        int cur = q.front(); q.pop();
        int next = cur + u;
        if(next <= f && !visited[next]){
            visited[next] = true;
            building[next] = building[cur] + 1;
            q.push(next);
        }
        next = cur - d;
        if(1 <= next && !visited[next]){
            visited[next] = true;
            building[next] = building[cur] + 1;
            q.push(next);
        }
    }
    if(visited[g]) cout << building[g] << "\n";
    else cout << "use the stairs" << "\n";
    return 0;
}
