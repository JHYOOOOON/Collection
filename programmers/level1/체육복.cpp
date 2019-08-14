#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int temp=0;
    vector<int>ath;

    for(int i=0;i<n;i++){
        ath.push_back(1);
    }
    for(int i=0;i<lost.size();i++){
        ath[lost[i]-1]--;
    }
    for(int i=0;i<reserve.size();i++){
        ath[reserve[i]-1]++;
    }

    for(int i=0;i<n;i++){
        if(ath[i]==1){answer++;}
        else if(ath[i]==2){
            answer++;
            if(ath[i-1]==0&&i>0){
                answer++;
            }
            else if(ath[i+1]==0){
                ath[i+1]=1;
            }
        }
    }
    return answer;
}
