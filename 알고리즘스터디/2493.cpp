#include <stack>
#include <iostream>
#include <vector>
#define height first
#define idx second
using namespace std;

int main(){
    int n, h, idx = 0;
    vector<int> v;
    stack<pair<int, int>> s;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> h;
        if(s.empty() || s.top().height < h){
            while(!s.empty() && s.top().height < h){
                s.pop();
            }
            if(s.empty()){
                v.push_back(0);
            } else{
                v.push_back(s.top().idx);
            }
        } else { v.push_back(s.top().idx); }
        s.push({h, i+1});
    }

    for(int i=0; i<n; i++) cout << v[i] << ' ';

    return 0;
}
