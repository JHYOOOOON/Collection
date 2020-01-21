#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[102][102][102];
int dist[102][102][102];
int n, m, h;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main(){
    queue<tuple<int, int, int>> q;
    cin >> m >> n >> h;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> board[j][k][i];
                dist[j][k][i] = -1;
                if(board[j][k][i] == 1){
                    q.push({j,k,i});
                    dist[j][k][i] = 0;
                }
            }
        }
    }
    int mx = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0; dir<6; dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx < 0 or nx >=n or ny < 0 or ny >= m or nz < 0 or nz >= h) continue;
            if(board[nx][ny][nz] == 0 and dist[nx][ny][nz] == -1){
                q.push({nx, ny, nz});
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                mx = max(mx, dist[nx][ny][nz]);
            }
        }
    }
    
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(board[j][k][i] == 0 and dist[j][k][i] == -1){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << mx << "\n";
    return 0;
}
