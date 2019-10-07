#include <iostream>

using namespace std;

int main(){
    int n, a, b, cnt = 0;
    cin >> n;
    a = n;

    while(1){
        b = a%10;
        a = a/10 + a%10;
        a = a%10 + b*10;
        cnt++;
        if(a == n){break;}
    }
    
    cout << cnt;

    return 0;
}
