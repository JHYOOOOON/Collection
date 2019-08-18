#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool flag = true;

    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z'){
            if(s[i] == ' '){flag = true; continue;}
            else {flag = false; continue;}
        }

        if(flag == true){
            s[i] = toupper(s[i]);
            flag = false;
        }
        else{
            s[i] = tolower(s[i]);
        }

    }
    return s;
}
