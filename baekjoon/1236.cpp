#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    vector<bool> row(n);
    vector<bool> col(m);
    int cnt_n = n, cnt_m = m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'X'){
                if(!row[i]){
                    cnt_n--;
                    row[i] = true;
                }
                if(!col[j]){
                    cnt_m--;
                    col[j] = true;
                }
            }
        }

    (cnt_m >= cnt_n) ? cout << cnt_m << "\n" : cout << cnt_n << "\n";

	return 0;
}
