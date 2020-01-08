#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    queue<int> q;
    int n, tmp;
    cin >> n;

    while(n--){
        cin >> s;
        if(s == "push"){
            cin >> tmp;
            q.push(tmp);
        }else if(s == "pop"){
            if(q.empty()){ cout << -1 << endl; }
            else{ cout << q.front() << endl; q.pop(); }
        }else if(s == "size"){ cout << q.size() << endl; }
        else if(s == "empty"){
            if(q.empty()){
                cout << 1 << endl;
            }else { cout << 0 << endl;}
        }else if(s == "front"){
            if(q.empty()){ cout << -1 << endl; }
            else{ cout << q.front() << endl; }
        }else if(s == "back"){
            if(q.empty()){ cout << -1 << endl;}
            else{ cout << q.back() << endl;}
        }
    }

    return 0;
}
