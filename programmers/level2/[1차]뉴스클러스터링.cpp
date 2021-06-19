#include <string>
#include <algorithm>
#include <vector>
#define MULTI 65536
using namespace std;

bool isCorrect(string s){
    if(s[0] >= 'a' && s[0] <= 'z' &&
      s[1] >= 'a' && s[1] <= 'z') return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0, mn = 0, mx = 0;
    vector<string> s1, s2;
    
    // 소문자로 변환
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    
    // s1, s2 2글자씩 잘라서 벡터에 저장
    string tmp = "";
    for(int i=0; i<str1.length()-1; i++){
        tmp = str1.substr(i, 2);
        if(isCorrect(tmp)) s1.push_back(tmp);
    }
    
    for(int i=0; i<str2.length()-1; i++){
        tmp = str2.substr(i, 2);
        if(isCorrect(tmp)) s2.push_back(tmp);
    }
    
    mx = s1.size() + s2.size();
    for(string str : s1){
        auto it = find(s2.begin(), s2.end(), str);
        if(it != s2.end()){
            mn++;
            s2.erase(it);
        }
    }
    
    mx -= mn;
    if(mn == 0 && mx == 0) return MULTI;
    double check = double(mn) / mx;
    
    return check * MULTI;
}
