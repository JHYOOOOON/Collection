#include <iostream>
#define MAX 50 + 1
using namespace std;

char board[MAX][MAX];
int n, mx = 0;

void check(){
    char tmp;
    for(int i=0; i<n; i++){
        int cnt = 1;
        tmp = board[i][0];
        for(int j=1; j<n; j++){
            (board[i][j] == tmp) ? cnt++ : cnt = 1;
            tmp = board[i][j];
            if(cnt > mx) mx = cnt;
        }
    }

    for(int i=0; i<n; i++){
        int cnt = 1;
        tmp = board[0][i];
        for(int j=1; j<n; j++){
            (board[j][i] == tmp) ? cnt++ : cnt = 1;
            tmp = board[j][i];
            if(cnt > mx) mx = cnt;
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) cin >> board[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++){
            swap(board[i][j], board[i][j+1]);
            check();
            swap(board[i][j], board[i][j+1]);
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++){
            swap(board[j][i], board[j+1][i]);
            check();
            swap(board[j][i], board[j+1][i]);
        }

    cout << mx << "\n";

    return 0;
}
