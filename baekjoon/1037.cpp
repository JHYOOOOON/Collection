#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[0] * v[v.size()-1] << "\n";
    return 0;
}
