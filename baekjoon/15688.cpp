#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        printf("%d\n", v[i]);
    return 0;
}
