#include <iostream>
using namespace std;

int n, m, cnt = 0;
char a[55][55], b[55][55];

void changeMatrix(int x, int y){
    cnt++;
    for(int i=x; i<x+3; i++)
        for(int j=y; j<y+3; j++)
            a[i][j] = (a[i][j] - '0') ? '0' : '1';
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> b[i][j];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] != b[i][j] && (i+3 <= n && j+3 <= m))
                changeMatrix(i, j);
            else if(a[i][j] != b[i][j] && (i+3 > n || j+3 > m)){
                cout << -1 << "\n";
                return 0;
            }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] != b[i][j]){
                cout << -1 << "\n";
                return 0;
            }

    cout << cnt << "\n";
    return 0;
}
