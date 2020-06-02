#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, sur_sheep = 0, sur_wolf = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    cin >> r >> c;
    vector<vector<char>> board(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> board[i][j];

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] != '#' && !visited[i][j]){
                int sheep = 0, wolf = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();

                    if(board[cur.first][cur.second] == 'v') wolf++;
                    else if(board[cur.first][cur.second] == 'o') sheep++;
                    
                    for(int k=0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];

                        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if(visited[nx][ny] || board[nx][ny] == '#') continue;

                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                (sheep <= wolf) ? sur_wolf += wolf : sur_sheep += sheep;
            }
        }
    }

    cout << sur_sheep << ' ' << sur_wolf << "\n";

    return 0;
}
