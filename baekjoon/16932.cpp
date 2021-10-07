#include <iostream>
#include <set>
#include <queue>
#include <tuple>
#define MAX 1000 + 1
using namespace std;

int n, m;
bool board[MAX][MAX];
bool visited[MAX][MAX];
int g_cnt[MAX];
int group[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) cin >> board[i][j];

    // 그룹화
    queue<pair<int, int>> q;
    int num = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j] && board[i][j]){
                q.push({i, j});
                visited[i][j] = 1;
                group[i][j] = ++num;
                int cnt = 1, x, y;
                while(!q.empty()){
                    tie(x, y) = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(!board[nx][ny] || visited[nx][ny]) continue;
                        cnt++;
                        group[nx][ny] = num;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                g_cnt[num] = cnt;
            }
    
    int mx = 0;
    for(int x=0; x<n; x++)
        for(int y=0; y<m; y++)
            if(!board[x][y]){
                set<int> s;
                for(int k=0; k<4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(!board[nx][ny]) continue;
                    s.insert(group[nx][ny]);
                }

                int sum = 1;
                for(auto it=s.begin(); it!=s.end(); it++)
                    sum += g_cnt[*it];
                mx = max(mx, sum);
            }
    
    cout << mx << "\n";

    return 0;
}
