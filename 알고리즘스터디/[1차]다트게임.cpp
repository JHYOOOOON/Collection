#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0, t, num, j;
    vector<int> score;
    
    for(int i=0; i<dartResult.length(); i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(dartResult[i+1] == '0'){
                j = i+2;
                num = (dartResult[i] - '0') * 10;
                i++;
            } else{
                j = i+1;
                num = dartResult[i] - '0';
            }
            
            if(dartResult[j] == 'D'){ t = 2; }
            else if(dartResult[j] == 'T'){ t = 3; }
            else{ t = 1; }
            
            score.push_back(pow(num, t));
            i++;
        } else if(dartResult[i] == '*'){
            int size = score.size() - 1;
            score[size] *= 2;
            score[size-1] *= 2;
        } else if(dartResult[i] == '#') {
            int size = score.size() - 1;
            score[size] *= -1;
        }
    }
    
    for(int n : score) answer += n;
    
    return answer;
}
