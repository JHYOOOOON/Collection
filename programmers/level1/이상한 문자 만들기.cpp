#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool temp=true;

    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            answer+=' ';
            temp=true;
        }
        else{
            if(temp){
                answer+=toupper(s[i]);
                temp=false;
            }
            else{
                answer+=tolower(s[i]);
                temp=true;
            }
        }
    }
    return answer;
}
