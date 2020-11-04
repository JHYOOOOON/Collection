#include <string>
#include <queue>
#include <iostream>
#define MAX 10 + 1
using namespace std;

// R, D, L, U
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool visited[MAX][MAX][MAX][MAX];

int solution(string dirs) {
    int answer = 0;
    
    int x = 5, y = 5;
    int nx, ny;
    for(auto dir : dirs){
        if(dir == 'U'){
            nx = x + dx[3];
            ny = y + dy[3];
        } else if(dir == 'R'){
            nx = x + dx[0];
            ny = y + dy[0];
        } else if(dir == 'L'){
            nx = x + dx[2];
            ny = y + dy[2];
        } else if(dir == 'D'){
            nx = x + dx[1];
            ny = y + dy[1];
        }
        
        if(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
        if(!visited[nx][ny][x][y]){
            answer++;
            visited[nx][ny][x][y] = 1;
            visited[x][y][nx][ny] = 1;
        }
        x = nx;
        y = ny;
    }
    
    return answer;
}
