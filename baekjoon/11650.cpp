#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2){
    if(p1.first != p2.first)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    int n, x, y;
    scanf("%d", &n);
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<n; i++){
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}
