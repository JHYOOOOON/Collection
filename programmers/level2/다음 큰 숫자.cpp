#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool next(int x, int cnt1){
    int cnt2 = 1;
    while(1){
        if(x==1){break;}
        if(x%2==1){cnt2++;}
        x/=2;
    }
    if(cnt2 == cnt1){return true;}
    else{ return false;}
}

int solution(int n) {
    int cnt1 = 1;
    int x=n+1;
    bool flag = false;

    while(1){
        if(n==1){break;}
        if(n%2==1){cnt1++;}
        n/=2;
    }

    for(x; x<=10000001; x++){
        flag = next(x,cnt1);
        if(flag == true){return x;}
    }
}
