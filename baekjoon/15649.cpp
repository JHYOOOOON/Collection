#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[21];
bool isused[21];

void func(int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << arr[i]+1 << ' ';
        cout << "\n";
        return;
    }
    for(int i=0; i<n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
    return 0;
}
