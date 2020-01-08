#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2){
    return p1.first < p2.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, age;
    string name;
    cin >> n;
    vector<pair<int,string>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(), v.end(), compare);
    for(int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << "\n";
    }

    return 0;
}
