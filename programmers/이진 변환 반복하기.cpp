#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer(2, 0);

void count(string s){
    if(s.length() == 1) return;
    
    int one = 0;
    for(char c : s)
        if(c == '1') one++;
    
    answer[0]++;
    answer[1] += s.length() - one;
    
    string tmp = "";
    while(one >= 1){
        tmp += (one % 2) ? '1' : '0';
        one /= 2;
    }
    
    reverse(tmp.begin(), tmp.end());
    count(tmp);
}

vector<int> solution(string s) {
    count(s);
    return answer;
}
