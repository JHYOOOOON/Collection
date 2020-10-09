#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<bool>> board(m+1, vector<bool>(n+1, 1));
    for(auto puddle : puddles)
        board[puddle[0]][puddle[1]] = 0;

    vector<vector<int>> d(m+1, vector<int>(n+1, 0));
    d[1][0] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]) d[i][j] = (d[i-1][j] + d[i][j-1])%MOD;
            else d[i][j] = 0;
        }
    }

    return d[m][n];
}
