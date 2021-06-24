#include <string>
#include <vector>
using namespace std;

int mn = 9, n, num;

void check(int result, int cnt){
    if(cnt > 8) return;
    if(result == num){
        mn = min(mn, cnt);
        return;
    }
    
    int tmp = 0;
    for(int i=1; i+cnt<9; i++){
        tmp = tmp*10 + n;
        check(result+tmp, cnt+i);
        check(result-tmp, cnt+i);
        check(result*tmp, cnt+i);
        check(result/tmp, cnt+i);
    }
}

int solution(int N, int number) {
    n = N, num = number;
    
    check(0, 0);
    
    return (mn == 9) ? -1 : mn;
}
