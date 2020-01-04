#include <bits/stdc++.h>
using namespace std;

int n, m, i, j, x, y, k, tmp, sum = 0;
int d[302][302];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> tmp;
            d[i][j] = d[i-1][j] + d[i][j-1] - d[i-1][j-1] + tmp;
        }
    }
    cin >> k;
    while(k--){
        cin >> i >> j >> x >> y;
        sum = d[x][y] - d[x][j-1] - d[i-1][y] + d[i-1][j-1];
        cout << sum << endl;
    }
    return 0;
}
