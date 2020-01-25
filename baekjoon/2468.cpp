#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    bool visited[101][101];
    
    int mx = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            (mx < board[i][j]) ? mx = board[i][j] : mx = mx;
        }
    }

    int realMax = 1;
    for(int a=1; a<mx; a++){
        for(int b=0; b<n; b++)
            fill(visited[b], visited[b]+n, false);
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] > a && !visited[i][j]){
                    q.push({i, j});
                    cnt++;
                    while(!q.empty()){
                        auto cur = q.front(); q.pop();
                        for(int k=0; k<4; k++){
                            int nx = cur.first + dx[k];
                            int ny = cur.second + dy[k];
                            if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                            if(board[nx][ny] > a && !visited[nx][ny]){
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        (realMax < cnt) ? realMax = cnt : realMax = realMax;
    }
    cout << realMax << "\n";

    return 0;
}
