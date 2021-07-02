#include <string>
#include <vector>
using namespace std;

int numberCnt = 0;

int oneCnt(int x){
    int cnt = 0;
    while(x >= 1){
        if(x%2) cnt++;
        x/=2;
    }
    return cnt;
}

int solution(int n) {
    numberCnt = oneCnt(n);
    
    int i = n;
    while(i++){
        if(oneCnt(i) == numberCnt)
            return i;
    }
}
