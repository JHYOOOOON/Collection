#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    int n, tmp; 
    cin >> n;
    vector<pair<int, int>> v;
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        cin >> tmp;
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());

    for(int i=0; i<n; i++){
        int idx = v[i].second;
        ans[idx] = i;
    }

    for(int n:ans) cout << n << ' ';
    return 0;
}
