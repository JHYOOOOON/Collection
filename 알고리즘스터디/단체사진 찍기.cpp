#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<string> Data;
int answer = 0;
bool isused[8];
char friends1[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
char result[8];

void confirm(){
    for(string str : Data){
        char f1 = str[0], f2 = str[2], oper = str[3];
        int dist = str[4] - '0' + 1;
        
        int idx1 = -1, idx2 = -1;
        for(int i=0; i<8; i++){
            if(idx1 != -1 && idx2 != -1) break;
            if(result[i] == f1) idx1 = i;
            else if(result[i] == f2) idx2 = i;
        }
        
        int real_dist = abs(idx1 - idx2);
        if(oper == '=' && real_dist != dist) return;
        else if(oper == '<' && real_dist >= dist) return;
        else if(oper == '>' && real_dist <= dist) return;
    }
    answer++;
    return;
}

void check(int cnt){
    if(cnt == 8) confirm();
    
    for(int i=0; i<8; i++){
        if(isused[i]) continue;
        isused[i] = 1;
        result[cnt] = friends1[i];
        check(cnt+1);
        isused[i] = 0;
    }
}

int solution(int n, vector<string> data) {
    Data = data;
    answer = 0;
    memset(isused, 0, sizeof(isused));
    
    check(0);
    
    return answer;
}
