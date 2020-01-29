#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, tmp;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    tmp = sum;
    for(int i=n-1; i>=0; i--){
        tmp -= v[i];
        sum += tmp;
    }
    cout << sum << "\n";

    return 0;
}
