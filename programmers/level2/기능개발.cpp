#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx=0;
    int sum=0, temp=0;

    do{
        for(int i=idx;i<progresses.size();i++){
            if(progresses[i]>=100){continue;}
            progresses[i]+=speeds[i];
        }
        for(int i=idx;i<progresses.size();i++){
            if(progresses[i]>=100){
                temp++; sum++;
                if(i==progresses.size()-1){
                    answer.push_back(temp);
                }
            }
            else{
                if(temp==0){idx=i; break;}
                answer.push_back(temp);
                temp=0;
                idx=i;
                break;
            }
        }
    }while(sum<=progresses.size()-1);
    return answer;
}
