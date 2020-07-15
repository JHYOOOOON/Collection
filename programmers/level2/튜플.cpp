#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> mp;
    
    // string에서 숫자만 빼서 map에 넣고 같은 숫자 몇번 나왔는지 값 업데이트
    string tmp = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '{') continue;
        if((s[i] == ',' && s[i-1] != '}') || (s[i] == '}' && s[i-1] != '}')){
            int n = stoi(tmp);
            if(mp.find(n) == mp.end()) { mp.insert({n, 1}); }
            else { mp[n]++; }
            tmp = "";
        } else if(s[i] >= '0' && s[i] <= '9'){ tmp += s[i]; }
    }
    
    // 정렬을 위해 map -> vector
    vector<pair<int, int>> sorting;
    for(auto it=mp.begin(); it!=mp.end(); it++)
       sorting.push_back(*it);
    
    // map에서 value에 따라 내림차순 정렬
    sort(sorting.begin(), sorting.end(), compare);
    for(int i=0; i<sorting.size(); i++)
        answer.push_back(sorting[i].first);
    
    return answer;
}
