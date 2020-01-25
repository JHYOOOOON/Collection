#include <bits/stdc++.h>
using namespace std;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
char board[31][31][31];
int visited[31][31][31];
int L, R, C;
tuple<int, int, int> start;
tuple<int, int, int> ed;

int main(){
    while(1){
        cin >> L >> R >> C;
        if(L == 0 && R == 0 && C == 0) return 0;
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    cin >> board[j][k][i];
                    visited[j][k][i] = -1;
                    if(board[j][k][i] == 'S'){
                        start = {j, k, i};
                    } else if(board[j][k][i] == 'E'){
                        ed = {j, k, i};
                    }
                }
            }
        }

        queue<tuple<int, int, int>> q;
        visited[get<0>(start)][get<1>(start)][get<2>(start)] = 0;
        q.push(start);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int i=0; i<6; i++){
                int nx = get<0>(cur) + dx[i];
                int ny = get<1>(cur) + dy[i];
                int nz = get<2>(cur) + dz[i];
                if(nx < 0 or nx >= R or ny < 0 or ny >= C or nz < 0 or nz >= L) continue;
                if(board[nx][ny][nz] != '#' && visited[nx][ny][nz] == -1){
                    visited[nx][ny][nz] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                    q.push({nx, ny, nz});
                }
            }
        }

        if(visited[get<0>(ed)][get<1>(ed)][get<2>(ed)] != -1){
            cout << "Escaped in " << visited[get<0>(ed)][get<1>(ed)][get<2>(ed)] << " minute(s)." << "\n";
        } else { cout << "Trapped!" << "\n"; }
    }
    return 0;
}
