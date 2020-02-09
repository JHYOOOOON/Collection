#include <iostream>
#include <cmath>
#define MAX 123456*2+1
using namespace std;

bool arr[MAX];
void sosu(){
    arr[0] = arr[1] = true;
    for(int i=2; i<sqrt(MAX); i++){
        if(arr[i] == true) continue;
        for(int j=i*2; j<MAX; j+=i)
            arr[j] = true;
    }
    return;
}
int main(){
    sosu();
    int n, cnt;
    while(1){
        cnt = 0;
        cin >> n;
        // n이 0이면 탈출
        if(!n) { break; }

        // n이 음수일 경우
        if(n < 0){ 
            cout << 0 << "\n";
            continue;
        }
        // 주어진 범위 내 소수 개수 세기
        for(int i=n+1; i<=2*n; i++)
            if(!arr[i]) { cnt++; }
        
        // 출력
        cout << cnt << "\n";
    }
    return 0;
}
