#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k, tmp;
    cin >> n >> k;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << arr[k-1] << "\n";

    return 0;
}
