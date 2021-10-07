#include <iostream>
using namespace std;

int main(){
    string a, b;
    char op;
    cin >> a >> op >> b;

    if(op == '*'){
        cout << "1";
        for(int i=0; i<a.length()+b.length()-2; i++) cout << "0";
    } else if(op == '+'){
        if(a.length() > b.length()){
            for(int i=a.length()-1; i>=0; i--){
                if(a.length()-i == b.length()){
                    a[i] = '1';
                    break;
                }
            }
            cout << a;
        } else if(a.length() == b.length()){
            cout << "2";
            for(int i=0; i<a.length()-1; i++) cout << "0";
        } else{
            for(int i=b.length()-1; i>=0; i--){
                if(b.length()-i == a.length()){
                    b[i] = '1';
                    break;
                }
            }
            cout << b;
        }
    }
    cout << "\n";
    return 0;
}
