#include <iostream>
using namespace std;

int main(){
    int alpha[26] = {0}, cnt = 0;
    string a, b;
    cin >> a >> b;

    for(int i=0; i<a.length(); i++)
        alpha[a[i]-'a']++;
    for(int i=0; i<b.length(); i++)
        alpha[b[i]-'a']--;

    for(int i=0; i<26; i++)
        if(alpha[i])
            cnt += abs(alpha[i]);

    cout << cnt << "\n";

    return 0;
}
