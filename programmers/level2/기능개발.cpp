#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++){
        ((100 - progresses[i]) % speeds[i]) ?
            q.push((100 - progresses[i]) / speeds[i] + 1) : 
            q.push((100 - progresses[i]) / speeds[i]);
    }
    
    int cnt = 0, date = 0;
    while(!q.empty()){
        if(!date){
            date = q.front();
            q.pop();
            cnt++;
        } else if(q.front() <= date){
            cnt++;
            q.pop();
        } else if(q.front() > date){
            answer.push_back(cnt);
            cnt = 0;
            date = 0;
        }
        if(q.empty())
            answer.push_back(cnt);
    }
    
    return answer;
}
