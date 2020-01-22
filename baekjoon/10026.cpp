#include <bits/stdc++.h>
using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[101];
bool visited [101][101] = {false};
int ans[2], cnt1 = 0, cnt2 = 0;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({x, y});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
            if(!visited[nx][ny] and board[nx][ny] == board[x][y]){
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> board[i];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                cnt1++;
                bfs(i, j);
            }
        }
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(board[i][j] == 'G')
                board[i][j] = 'R';

    for(int i=0; i<N; i++)
        fill(visited[i], visited[i]+N, false);
        
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                cnt2++;
                bfs(i, j);
            }
        }
    }
    cout << cnt1 << ' ' << cnt2 << "\n";
    return 0;
}
