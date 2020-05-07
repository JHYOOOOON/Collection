#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool compare(pair<int, double> a, pair<int, double> b){
    return (a.second == b.second) ? a.first < b.first : a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> fail;
    vector<bool> flag(N);
    double sum = 0, idx = 0;
    
    sort(stages.begin(), stages.end(), greater<int>());
    
    for(int i=0; i<stages.size(); i++){
        idx++;
        sum++;
        if(stages[i] != stages[i+1]){
            if(stages[i] <= N){
                fail.push_back({stages[i], idx/sum});
                flag[stages[i]] = true;
            }
            idx = 0;
        }
    }
    
    for(int i=1; i<=N; i++)
        if(!flag[i])
            fail.push_back({i,0});
    
    sort(fail.begin(), fail.end(), compare);
    for(int i=0; i<fail.size(); i++)
        answer.push_back(fail[i].first);
        
    return answer;
}
