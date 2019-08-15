#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> str;

    for(int i = 0 ; i < s.length() ; i++){
        if(str.empty()){
            str.push(s[i]);
            continue;
        }

        if(str.top() == s[i]) { str.pop(); }
        else { str.push(s[i]); }
    }

    return str.empty() ? 1 : 0;
}
