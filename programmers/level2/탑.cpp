#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int, int>> s;
    
    for(int i=0; i < heights.size(); i++){
        if(s.empty() || s.top().first <= heights[i]){
            while(!s.empty() && s.top().first <= heights[i]) s.pop();
            (s.empty()) ? answer.push_back(0) : answer.push_back(s.top().second);
        } else { answer.push_back(s.top().second); }
        s.push({heights[i], i+1});
    }
    
    return answer;
}
