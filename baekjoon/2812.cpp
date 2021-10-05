#include <iostream>
#include <deque>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    deque<char> dq;
    char c;

    while(n--){
        cin >> c;
        if(k != 0){
            while(!dq.empty() && dq.back()-'0' < c-'0' && k != 0){
                dq.pop_back();
                k--;
            }
        }
        dq.push_back(c);
    }

    while(k--)  dq.pop_back();
    

    while(!dq.empty()){
        cout << dq.front();
        dq.pop_front();
    }

    return 0;
}
