#include <bits/stdc++.h>
using namespace std;

bool arr[10001] = {false,};

int main(){
    int m, n;
    cin >> m >> n;
    arr[1] = true;
    for(int i=2; i<=sqrt(n); i++){
        if(arr[i] == true) continue;
        for(int j=i*2; j<=n; j+=i)
            arr[j] = true;
    }
    int sum = 0;
    bool flag = false;
    int mn;
    for(int i=m; i<=n; i++){
        if(arr[i] == true) continue;
        if(!flag){mn = i; flag = true;}
        sum += i;
    }
    if(sum == 0){
        cout << -1 << "\n";
    } else {
        cout << sum << "\n" << mn << "\n";
    }
    return 0;
}
