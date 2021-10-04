#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n, x;
    deque<int> dq;
    vector<int> cp;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        dq.push_back(x);
    }

    for(int i=0; i<n; i++){
        cin >> x;
        cp.push_back(x);
    }

    while(dq.front() != cp[0]){
        dq.push_front(dq.back());
        dq.pop_back();
    }

    bool flag = true;
    for(int i=0; i<n; i++){
        if(dq[i] != cp[i]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "good puzzle\n";
        return 0;
    }

    dq.push_back(dq.front());
    dq.pop_front();

    flag = true;
    for(int i=0; i<n; i++){
        if(dq[i] != cp[n-1-i]){
            flag = false;
            break;
        }
    }

    (flag) ? cout << "good puzzle\n" : cout << "bad puzzle\n";

    return 0;
}
