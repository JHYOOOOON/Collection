#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<char> s;

bool correct(string b){
    for(int i=0; i<b.length(); i++){
        if(b[i] == '('){
            s.push('(');
        }else{
            if(s.empty()){
                return false;
             }else{
                s.pop();
            }
        }
    }
    if(s.empty()){ return true; }else{ return false; }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    bool flag;
    string b, Y = "YES", N = "NO";

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> b;
        flag = correct(b);
        if(flag){ cout << Y << endl; }else{ cout << N << endl; }
        while(!s.empty()){
            s.pop();
        }
    }

    return 0;
}
