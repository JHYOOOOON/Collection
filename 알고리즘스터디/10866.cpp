#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    string s;
    deque<int> dq;
    cin >> t;

    while(t--){
        cin >> s;
        if(s == "push_front"){
            cin >> n;
            dq.push_front(n);
        } else if(s == "push_back"){
            cin >> n;
            dq.push_back(n);
        } else if(s == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << "\n";
                dq.pop_front();
            } else{ cout << -1 << "\n"; }
        } else if(s == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << "\n";
                dq.pop_back();
            } else{ cout << -1 << "\n"; }
        } else if(s == "size"){
            cout << dq.size() << "\n";
        } else if(s == "empty"){
            (dq.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
        } else if(s == "front"){
            (dq.empty()) ? cout << -1 << "\n" : cout << dq.front() << "\n";
        } else if(s == "back"){
            (dq.empty()) ? cout << -1 << "\n" : cout << dq.back() << "\n";
        }
    }
    return 0;
}
