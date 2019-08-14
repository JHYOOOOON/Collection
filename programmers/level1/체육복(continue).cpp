#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int>ath;
    for(int i=0;i<n;i++){
        ath.push_back(1);
    }
    for(int i=0;i<lost.size();i++){
        ath[lost[i]]--;
    }
    for(int i=0;i<reserve.size();i++){
        ath[reserve[i]]++;
    }
    
    for(int i=0;i<n;i++){
        if(ath[i]==2){
            if(ath[i-1]==0){
                ath[i-1]=1;
                ath[i]=1;
            }
            else if(ath[i+1]==0){
                ath[i+1]=1;
                ath[i]=1;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(ath[i]==1||ath[i]==2){answer++;}
    }
    return answer;
}
