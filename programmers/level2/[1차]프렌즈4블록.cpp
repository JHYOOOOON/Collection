#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        bool flag = 0;
        vector<vector<bool>> checked(m, vector<bool>(n, 0));
        for(int i=0; i<m-1; i++)
            for(int j=0; j<n-1; j++){
                char alpha = board[i][j];
                if(alpha == 'X') continue;
                if(alpha == board[i+1][j] && alpha == board[i][j+1] && alpha == board[i+1][j+1]){
                    flag = 1;
                    checked[i][j] = 1;
                    checked[i+1][j] = 1;
                    checked[i][j+1] = 1;
                    checked[i+1][j+1] = 1;
                }
            }
        if(!flag) break;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(checked[i][j]){
                    answer++;
                    for(int k=i; k>=0; k--){
                        if(k == 0) board[0][j] = 'X';
                        else board[k][j] = board[k-1][j];
                    }
                }
    }
    return answer;
}
