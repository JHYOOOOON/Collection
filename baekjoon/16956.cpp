#include <iostream>
#define MAX 500 + 1
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    int r, c;
    cin >> r >> c;

    char board[MAX][MAX];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) cin >> board[i][j];

    bool flag = true;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            if(!flag) break;

            if(board[i][j] == 'S')
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    
                    if(board[nx][ny] == 'W'){
                        flag = false;
                        break;
                    }
                }
        }
    
    if(!flag){
        cout << "0\n";
    } else{
        cout << "1\n";
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(board[i][j] == 'S'){
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if(board[nx][ny] == '.') board[nx][ny] = 'D';
                    }
                }
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++) cout << board[i][j];
            cout << "\n";
        }
    }

    return 0;
}
