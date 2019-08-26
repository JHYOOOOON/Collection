#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int i=0; i<brown; i++){
        for(int j=0; j<brown; j++){
            if(i*j==brown+red && i>=j && (i-2)*(j-2)==red){
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
}
 ​
