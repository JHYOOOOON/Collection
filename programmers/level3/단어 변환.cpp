#include <string>
#include <vector>

using namespace std;

bool isused[50];
string t;
int ans;
vector<string> w;

bool compare(string a, string b){
    int cnt = 0;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]) cnt++;
    }
    
    return (cnt == 1) ? true : false;
}

void dfs(string s, int cnt){
    if(s == t){
        ans = cnt;
        return;
    }
    
    bool flag;
    for(int i=0; i<w.size(); i++){
        if(!isused[i]){
            flag = compare(s, w[i]);
            if(flag){
                isused[i] = 1;
                dfs(w[i], cnt+1);
                isused[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    t = target;
    w = words;
    
    bool flag = false;
    for(auto str : words){
        if(str == target){
            flag = true;
            break;
        }
    }
    if(!flag) return 0;
    
    dfs(begin, 0);
    
    return ans;
}
