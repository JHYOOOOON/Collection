#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int, int>> board(5);
        bool flag = true;

        for(int i=0; i<4; i++)
            cin >> board[i].first >> board[i].second;
        sort(board.begin(), board.begin()+4);
        sort(board.begin()+2, board.begin()+4, greater<pair<int, int>>());

        int len = dist(board[3], board[0]);
        for(int i=1; i<4; i++){
            if(len != dist(board[i-1], board[i])){
                flag = false;
                break;
            }
        }
        
        if(flag && dist(board[2], board[0]) != dist(board[3], board[1])) flag = false;

        (flag) ? cout << "1\n" : cout << "0\n";

    }
    return 0;
}
