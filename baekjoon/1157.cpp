#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    string a;
    int count[26], max = 0, temp = 0, index;
    fill_n(count, 26, 0);
    cin >> a;
    transform(a.begin(), a.end(), a.begin(), :: toupper);
    for(int i=0; i<a.length(); i++){
        count[a[i]-65]++;
    }
    max = *max_element(count, count+26);
    for(int i=0; i<26; i++){
        if(max == count[i]){temp++; index = i;}
        if(temp > 1) { cout << '?' << endl; return 0;}
    }
    printf("%c", index+65);
    return 0;
}
