#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    // answer[0] 영역 개수
    // answer[1] 가장 큰 영역
    vector<int> answer(2, 0);
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(picture[i][j] && !visited[i][j]){
                // 영역개수 하나 추가
                answer[0]++;
                // 영역너비
                int area = 1;
                // 영역 숫자 저장
                int num = picture[i][j];
                queue<pair<int, int>> q;
                visited[i][j] = 1;
                q.push({i, j});
                while(!q.empty()){
                    auto cur = q.front(); q.pop();
                    for(int k=0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(picture[nx][ny] != num || visited[nx][ny]) continue;
                        area++;
                        visited[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
                if(answer[1] < area) answer[1] = area;
            }
    
    return answer;
}
