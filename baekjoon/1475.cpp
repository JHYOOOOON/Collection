#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, arr[9], max;
    fill(arr, arr+10, 0);
    cin >> N;
    string tmp = to_string(N);

    for(int i=0; i<tmp.length(); i++){
        if(tmp[i]=='9'){ arr[6]++; }
        else{ arr[tmp[i]-'0']++; }
    }
    arr[6] = (arr[6]+1)/2;
    max = *max_element(arr, arr+9);
    cout << max;

    return 0;
}
