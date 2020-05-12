#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main(){
    int k, tmp;
    ll sum = 0;
    stack<int> s;
    cin >> k;

    while(k--){
        cin >> tmp;
        if(tmp){
            sum += tmp;
            s.push(tmp);
        } else{
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum << "\n";

    return 0;
}
