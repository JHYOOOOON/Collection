#include <bits/stdc++.h>
using namespace std;

bool arr[1000001] = {false, };

void sosu(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(arr[i] == true) continue;
        for(int j=2*i; j<=n; j+=i)
            arr[j] = true;
    }
}

int main(){
    int m, n;
    cin >> m >> n;
    arr[1] = true;
    sosu(n);
    for(int i=m; i<=n; i++)
        if(!arr[i]) cout << i << "\n";
    return 0;
}
