#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main(){
    int t, tmp, len;
    string p, n;
    deque<int> dq;
    cin >> t;

    while (t--){
        dq.clear();
        stringstream ss;
        char flag = 'f';
        cin >> p >> len >> n;

        for(int i=0; i<n.length(); i++)
            if(n[i] == '[' || n[i] == ']' || n[i] == ',')
                n[i] = ' ';

        ss.str(n);
        while(ss >> tmp){
            dq.push_back(tmp);
        }

        for(char c:p){
            if(c == 'R'){
                (flag == 'f') ? flag = 'b' : flag = 'f';
            } else if(c == 'D'){
                if(dq.empty()){
                    cout << "error\n"; 
                    flag = 'e';
                    break;
                } else{
                    (flag == 'f') ? dq.pop_front() : dq.pop_back();
                    len--;
                }
            }
        }

       
        if(flag == 'f'){
            cout << '[';
            for(int i=0; i<len; i++){
                cout << dq[i];
                if(i == len-1) continue;
                cout << ',';
            }
            cout << "]\n";
        } else if(flag == 'b'){
            cout << '[';
            for(int i=len-1; i>=0; i--){
                cout << dq[i];
                if(i == 0) continue;
                cout << ',';
            }
            cout << "]\n";
        }
        
    }

    return 0;
}
