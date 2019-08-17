#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int>v;
    string temp="";

    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            v.push_back(stoi(temp));
            temp="";
        }
        else if(i==s.length()-1){
            temp+=s[i];
            v.push_back(stoi(temp));
        }
        else{
            temp+=s[i];
        }
    }

    sort(v.begin(), v.end());

    answer=to_string(v[0])+' '+to_string(v[v.size()-1]);

    return answer;
}
