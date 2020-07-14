#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i=0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
            if(b == pq.top()){
                pq.pop();
                answer += 1;
                if(a == location){
                break;
            }
        } else{ q.push(make_pair(a,b)); }
    }
    return answer;
}
