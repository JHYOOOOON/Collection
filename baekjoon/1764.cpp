#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> ans;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i=0; i<m; i++){
        cin >> s;
        if(binary_search(a.begin(), a.end(), s)){
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << "\n";
    
    return 0;
}
