#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void sosu(int tmp){
    vector<bool> arr(tmp);
    fill(arr.begin(), arr.end(), false);
    if(tmp == 1) return;
    for(int i=2; i<tmp; i++){
        if(arr[i] == true) continue;
        if(tmp % i == 0) return;
        if(tmp % i != 0){
            for(int j=i*2; j<tmp; j+=i)
                arr[j] = true;
        }
    }
    cnt++;
}

int main(){
    int n, tmp;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> tmp;
        sosu(tmp);
    }
    cout << cnt << "\n";
    return 0;
}
