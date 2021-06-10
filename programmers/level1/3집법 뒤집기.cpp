#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = "";
    while(n>=1){
        str += char('0' + n%3);
        n/=3;
    }
    
    int multi = 1;
    for(int i=str.length()-1; i>=0; i--){
        answer += multi * (str[i]-'0');
        multi *= 3;
    }
    
    return answer;
}
