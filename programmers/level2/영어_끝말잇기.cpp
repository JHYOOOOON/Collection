#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    char tail = (words[0])[words[0].length()-1];
    s.insert(words[0]);
    for(int i=1; i<words.size(); i++){
        string tmp = words[i];
        if(tmp[0] == tail && s.count(tmp) == 0){
            s.insert(tmp);
            tail = tmp[tmp.length()-1];
        } else{
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            break;
        }
    }
    if(answer.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
