#include <iostream>
using namespace std;

int main(){
    string s;
    int num[5] = {0};
    
    cin >> s;

    num[s[0]-'0']++;
    for(int i=1; i<s.length(); i++)
        if(s[i] != s[i-1])
            num[s[i]-'0']++;

    (num[0] < num[1]) ? cout << num[0] << "\n" : cout << num[1] << "\n";

    return 0;
}
