#include <bits/stdc++.h>
using namespace std;

int board[301][301];
bool visited[301][301];
int dx[8] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[8] = {1, 2, -1, -2, 2, 1, -2, -1};
int a1, b1, a2, b2;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            fill(board[i], board[i]+n, 0);
            fill(visited[i], visited[i]+n, false);
        }
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        queue<pair<int, int>> q;
        visited[a1][b1] = true;
        q.push({a1, b1});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i=0; i<8; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                if(board[nx][ny] == 0 and !visited[nx][ny]){
                    visited[nx][ny] = true;
                    board[nx][ny] = board[cur.first][cur.second] + 1;
                    q.push({nx, ny});
                }
            }
        }
        cout << board[a2][b2] << "\n";
    }
    return 0;
}
