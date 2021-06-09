#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rank[7] = {6, 6, 5, 4, 3, 2, 1};
    int correct = 0, zero = 0;
    for(int lotto : lottos){
        if(lotto == 0) zero++;
        else{
            for(int win_num : win_nums){
                if(win_num == lotto){
                    correct++;
                    break;
                }
            }
        }
    }
    
    answer.push_back(rank[correct+zero]);
    answer.push_back(rank[correct]);
    
    return answer;
}
