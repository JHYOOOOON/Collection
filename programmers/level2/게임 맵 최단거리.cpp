#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int solution(vector<vector<int>> maps){
    int n = maps.size(), m = maps[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    queue<pair<int, int>> q;
    visited[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.X == n-1 && cur.Y == m-1) break;

        for(int k=0; k<4; k++){
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!maps[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            q.push({nx, ny});
        }
    }

    return (visited[n-1][m-1]) ? visited[n-1][m-1] : -1;
}
