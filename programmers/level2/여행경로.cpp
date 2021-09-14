#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 10000 + 1
using namespace std;

vector<string> answer;
bool isused[MAX];

bool cp(vector<string> road){
    for(int i=0; i<road.size(); i++){
        if(answer[i] == road[i]) continue;
        return (answer[i] < road[i]) ? false: true;   
    }
}

void dfs(string dep, vector<vector<string>>& tickets, vector<string> road){
    bool flag = false;
    for(int i=0; i<tickets.size(); i++){
        if(isused[i]) continue;
        flag = true;
        if(tickets[i][0] == dep){
            isused[i] = 1;
            
            vector<string> tmp;
            tmp = road;
            tmp.push_back(tickets[i][1]);
            
            dfs(tickets[i][1], tickets, tmp);
            
            isused[i] = 0;
        }
    }
    
    if(!flag){
        if(answer.size() == 0 || cp(road)) answer = road;
        return;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> road;
    road.push_back("ICN");
    dfs("ICN", tickets, road);
    
    sort(tickets.begin(), tickets.end());
    return answer;
}
