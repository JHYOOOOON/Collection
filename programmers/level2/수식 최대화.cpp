#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calc(long long a, long long b, char oper){
    if(oper == '+') return a + b;
    else if(oper == '-') return a - b;
    else if(oper == '*') return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<char> oper;
    vector<long long> number;
    
    string num = "";
    // 연산자와 숫자 나눠서 배열에 넣기
    for(char c : expression){
        if(c == '+' || c == '-' || c == '*'){
            oper.push_back(c);
            number.push_back(stoi(num));
            num = "";
        } else num += c;
    }
    number.push_back(stoi(num));
    
    vector<char> oper_list = {'*', '+', '-'};
    do{
        vector<char> tmp_oper = oper;
        vector<long long> tmp_number = number;
        for(int i=0; i<3; i++){
            for(int j=0; j<tmp_oper.size(); j++){
                if(oper_list[i] == tmp_oper[j]){
                    tmp_number[j] = calc(tmp_number[j], tmp_number[j+1], tmp_oper[j]);
                    tmp_number.erase(tmp_number.begin()+j+1);
                    tmp_oper.erase(tmp_oper.begin()+j);
                    j--;
                }
            }
        }
        if(answer < abs(tmp_number[0])) answer = abs(tmp_number[0]);
    }while(next_permutation(oper_list.begin(), oper_list.end()));
    
    return answer;
}
