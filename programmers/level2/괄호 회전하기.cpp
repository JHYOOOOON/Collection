#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool isCorrect(string bracket){
    stack<char> st;
    for(char b : bracket){
        if(b == '[' || b == '(' || b == '{') st.push(b);
        else{
            if(st.empty()) return false;
            if(b == ']'){
                if(st.top() == '[') st.pop();
                else return false;
            } else if(b == '}'){
                if(st.top() == '{') st.pop();
                else return false;
            } else if(b == ')'){
                if(st.top() == '(') st.pop();
                else return false;
            }
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

int solution(string s) {
    int answer = 0, len = s.length()-1;
    string tmp;
    while(len--){
        answer += isCorrect(s);
        s = s.substr(1) + s[0];
    }
    answer += isCorrect(s);
    
    return answer;
}
