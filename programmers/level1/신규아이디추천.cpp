#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계
    for(int i=0; i<new_id.length(); i++)
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = char(new_id[i] + ('a' - 'A'));
        
    // 2단계
    string tmp = "";
    for(char alpha : new_id)
        if('a' <= alpha && alpha <= 'z' ||
            alpha == '-' ||
            alpha >= '0' && alpha <= '9' ||
            alpha == '_' ||
            alpha == '.')
            tmp += alpha;
    
    answer = tmp;
    tmp = "";
    
    // 3단계
    for(int i=0; i<answer.length(); i++)
        if(answer[i] != '.'){
            if(answer[i-1] == '.') tmp += '.';
            tmp += answer[i];
        }
    
    answer = tmp;
    
    // 4단계
    if(answer[0] == '.') answer = answer.substr(1);
    if(answer[answer.length()-1] == '.') answer = answer.substr(0, answer.length()-1);
    
    // 5단계
    if(answer == "") answer = "a";
    
    // 6단계
    if(answer.length() >= 16){
        answer = answer.substr(0, 15);
        if(answer[answer.length()-1] == '.')
            answer = answer.substr(0, 14);
    }
    
    // 7단계
    if(answer.length() <= 2){
        char alpha = answer[answer.length()-1];
        while(answer.length() < 3) answer += alpha;
    }
    
    return answer;
}
