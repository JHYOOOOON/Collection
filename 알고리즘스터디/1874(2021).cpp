#include <stack>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, tmp, cnt = 0;
    stack<int> s;
    vector<char> v;
    cin >> n;
    while(n--){
        cin >> tmp;
        if(tmp > cnt){
            for(int i=cnt+1; i<=tmp; i++){
                s.push(i);
                v.push_back('+');
            }
        }else if(s.top() != tmp){
            cout << "NO" << "\n";
            return 0;
        }
        s.pop();
        v.push_back('-');
        if(cnt < tmp) cnt = tmp;
    }
    for(char op : v) cout << op << "\n";
    return 0;
}
