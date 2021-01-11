#include <vector>
#include <iostream>
#include <cmath>
#define MAX 50000 + 1
using namespace std;

bool sosu[MAX];
vector<int> n;
vector<bool> isused;
int count = 0;

void checkSosu(){
    for(int i=2; i<=sqrt(MAX); i++){
        if(sosu[i]) continue;
        for(int j=i+i; j<MAX; j+=i)
            sosu[j] = 1;
    }
    return;
}

void choice(int start, int cnt){
    if(cnt == 3){
        int sum = 0;
        for(int i=0; i<isused.size(); i++){
            if(isused[i]) sum += n[i];
        }
        
        if(!sosu[sum]) count++;
        return;
    }
    
    for(int i=start; i<n.size(); i++){
        if(!isused[i]){
            isused[i] = 1;
            choice(i+1, cnt+1);
            isused[i] = 0;
        }
    }
}

int solution(vector<int> nums) {
    checkSosu();
    
    n = nums;
    isused.resize(nums.size());
    
    choice(0, 0);

    return count;
}
