#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    vector<int> ans;
    queue<int> arr;

    for(int i=1; i<=n; i++){
        arr.push(i);
    }
    
    while(!arr.empty()){
        for(int i=1; i<=k; i++){
            tmp = arr.front();
            arr.pop();
            if(i == k) {
                ans.push_back(tmp);
            }else { arr.push(tmp); }
        }
    }

    // print
    cout << '<';
    for(int i=0; i<n-1; i++){
        cout << ans[i] << ", ";
    }
    cout << ans[n-1] << '>';

    return 0;
}
