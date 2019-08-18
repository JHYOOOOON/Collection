#include <iostream>
#include <cmath>

using namespace std;

int next(int x){
    if(x % 2 == 1){ x += 1; }
    return x / 2;
}

int solution(int n, int a, int b)
{
    int round = log(n) / log(2);

    for(int i = 0 ; i < round ; i++){
        if(a / 2 + a % 2 == b / 2 + b % 2){
            return i + 1;
        }
        a = next(a);
        b = next(b);
    }
}
