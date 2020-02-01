#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, tmp;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cin >> m;
    while(m--){
        cin >> tmp;
        if(binary_search(v.begin(), v.end(), tmp)){
            cout << 1 << ' ';
        } else { cout << 0 << ' '; }
    }
    return 0;
}
