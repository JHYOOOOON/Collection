#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> tmp;
    for(int i=0; i<moves.size(); i++){
        int idx = moves[i]-1;
        for(int j=0; j<board.size(); j++){
            if(board[j][idx]){
                if(!tmp.empty() && (tmp.top() == board[j][idx])){
                    tmp.pop();
                    answer += 2;
                } else { tmp.push(board[j][idx]); } 
                board[j][idx] = 0;
                break;
            }
        }
    }
    return answer;
}
