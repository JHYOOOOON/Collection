#include <deque>
#include <iostream>
using namespace std;

int main(){
    int N, tmp;
    string s;
    deque<int> d;
    cin >> N;
    while(N--){
        cin >> s;
        if(s == "push_front"){
            cin >> tmp;
            d.push_front(tmp);
        } else if(s == "push_back"){
            cin >> tmp;
            d.push_back(tmp);
        } else if(s == "front"){
            (d.empty()) ? cout << -1 << "\n" : cout << d.front() << "\n";
        } else if(s == "back"){
            (d.empty()) ? cout << -1 << "\n" : cout << d.back() << "\n";
        } else if(s == "empty"){
            (d.empty()) ? cout << 1 << "\n" : cout << 0 << "\n";
        } else if(s == "size"){
            cout << d.size() << "\n";
        } else if(s == "pop_front"){
            if(d.empty()){
                cout << -1 << "\n";
            } else{
                cout << d.front() << "\n";
                d.pop_front();
            }
        } else if(s == "pop_back"){
            if(d.empty()){
                cout << -1 << "\n";
            } else{
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
    }
    return 0;
}
