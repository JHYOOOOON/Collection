#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string board[26];
bool visited[26][26] = {false};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> ans;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> board[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '1' and !visited[i][j]){
                queue<pair<int, int>> q;
                visited[i][j] = true;
                q.push({i, j});
                int cnt = 1;
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;;
                        if(board[nx][ny] == '1' and !visited[nx][ny]){
                            cnt++;
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
