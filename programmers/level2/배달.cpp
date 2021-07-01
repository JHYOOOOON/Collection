#include <iostream>
#include <vector>
#include <queue>
#define MAX 50 + 1
#define INF 987654321
using namespace std;
using pii = pair<int, int>;

int d[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[1] = 0;
    pq.push({d[1], 1});
    
    int cnt, idx;
    while(!pq.empty()){
        cnt = pq.top().first;
        idx = pq.top().second;
        pq.pop();
        
        if(d[idx] != cnt) continue;
        for(auto nxt : graph[idx]){
            int time = nxt.first, nidx = nxt.second;
            if(d[nidx] > cnt + time){
                d[nidx] = cnt + time;
                pq.push({d[nidx], nidx});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(auto r : road){
        graph[r[0]].push_back({r[2], r[1]});
        graph[r[1]].push_back({r[2], r[0]});
    }
    
    for(int i=1; i<=N; i++) d[i] = INF;
    dijkstra();
    
    for(int i=1; i<=N; i++)
        if(d[i] <= K) answer++;

    return answer;
}
