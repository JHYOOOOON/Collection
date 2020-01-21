#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    queue<pair<int,int>> q;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            dist[i][j] = -1;
            if(board[i][j] == 1){
                q.push({i,j});
                dist[i][j] = 0;
            }
        }
    }
    int mx = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(0 <= nx and nx < n and 0 <= ny and ny < m){
                if(board[nx][ny] == 0 and dist[nx][ny] == -1){
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                    mx = max(mx, dist[nx][ny]);
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 0 and dist[i][j] == -1){
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << mx << "\n";
    return 0;
}
