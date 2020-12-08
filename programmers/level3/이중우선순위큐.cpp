#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    int n;
    for(string operation : operations){
        n = stoi(operation.substr(2));
        if(operation[0] == 'I'){
            dq.push_back(n);
            sort(dq.begin(), dq.end());
        } else if(!dq.empty()){
            (n == 1) ? dq.pop_back() : dq.pop_front();
        }
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    } else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}
