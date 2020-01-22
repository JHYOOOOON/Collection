#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
#define X first
#define Y second

int m, n, k;
int board[101][101] = {0};
bool visit[101][101] = {false};
int x1, y1, x2, y2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> a;

int main(){
    cin >> m >> n >> k;
    
    while(k--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                board[j][i] = 1;
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j] and board[i][j] == 0){
                visit[i][j]++;
                int cnt = 1;
                stack<pair<int,int>> s;
                s.push({i, j});
                while(!s.empty()){
                    auto cur = s.top(); s.pop();
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] == 0 and !visit[nx][ny]){
                            cnt++;
                            visit[nx][ny] = true;
                            s.push({nx, ny});
                        }
                    }
                }
                a.push_back(cnt);
            }
        }
    }

    sort(a.begin(), a.end());
    cout << a.size() << "\n";
    for(int i=0; i<a.size(); i++)
        cout << a[i] << ' ';

    return 0;
}
