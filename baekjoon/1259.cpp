#include <iostream>
using namespace std;

int main() {
    string s;
    bool flag;
	while(1){
        cin >> s;
        if(s == "0") return 0;
        int len = s.length();
        flag = true;
        for(int i=0; i<len/2; i++){
            if(s[i] != s[len-1-i]){
                flag = false;
            }
        }
        (flag) ? cout << "yes\n" : cout << "no\n";
    }
	return 0;
}
