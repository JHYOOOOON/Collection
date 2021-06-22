#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    for(auto num : edge){
        graph[num[0]].push_back(num[1]);
        graph[num[1]].push_back(num[0]);
    }
    
    queue<int> q;
    vector<int> visited(n+1, -1);
    visited[1] = 0;
    q.push(1);
    
    int mx = 0;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int nxt : graph[node]){
            if(visited[nxt] != -1) continue;
            visited[nxt] = visited[node] + 1;
            if(visited[nxt] > mx) mx = visited[nxt];
            q.push(nxt);
        }
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++)
        if(visited[i] == mx) answer++;
    
    return answer;
}
