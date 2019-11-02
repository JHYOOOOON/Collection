#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    int arr[26], ans = 0;
    fill(arr, arr+26, 0);
    cin >> a >> b;

    for(int i=0; i<a.length(); i++){
        arr[a[i]-'a']++;
    }
    for(int i=0; i<b.length(); i++){
        arr[b[i]-'a']--;
    }

    for(int i=0; i<26; i++){
        if(arr[i] != 0){
            ans += abs(arr[i]);
        }
    }
    cout << ans << endl;


    return 0;
}
