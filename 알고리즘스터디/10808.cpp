#include <iostream>
using namespace std;

int main(){
    string s;
    int alpha[26] = {0};
    cin >> s;

    for(int i=0; i<s.length(); i++)
        alpha[s[i]-'a']++;

    for(int i=0; i<26; i++)
        cout << alpha[i] << ' ';

    return 0;
}
