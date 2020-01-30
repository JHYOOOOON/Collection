#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    for(int i=1; i<=n; i++)
        cnt = cnt + abs(i-v[i-1]);

    cout << cnt << "\n";

    return 0;
}
